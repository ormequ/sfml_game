//
// Created by User on 06.12.2022.
//

#include "KernelSerializer.h"

namespace memento {
    KernelSerializer::KernelSerializer(GameMediator *game_mediator) : game_mediator_(game_mediator) {}

    std::map<std::string, std::map<std::string, std::string>> KernelSerializer::serialize() {
        if (!events_serializer_) {
            events_serializer_ = new EventsSerializer(game_mediator_->getEventsController());
        }
        // Сохраняем все объекты в std::map, где ключ - название сохраняемого объекта, а значение - его std::map
        std::map<std::string, std::map<std::string, std::string>> result{};
        kernel::IField *field = game_mediator_->getField();
        result["field"] = {};
        result["field"]["WIDTH"] = std::to_string(field->getWidth());
        result["field"]["HEIGHT"] = std::to_string(field->getHeight());

        // Для клеток поле std::map -- CELL_{x}.{y}_{PARAM}
        for (const auto &vec: field->getAllCells()) {
            for (auto cell: vec) {
                std::string point = std::to_string(cell->getPoint().x) + "." + std::to_string(cell->getPoint().y);
                if (tileset_to_str_.count(cell->getTileset())) {
                    result["field"]["CELL_" + point + "_TILESET"] = tileset_to_str_[cell->getTileset()];
                }
                if (cell->getListener()) {
                    // Вызываем EventSerializer для сохранения события
                    result["field"]["CELL_" + point + "_EVENT"] = events_serializer_->serialize(cell->getListener());
                }
                result["field"]["CELL_" + point + "_PASSABLE"] = std::to_string((int) cell->isPassable());
            }
        }

        result["creatures"] = {};
        // Для создание поле std::map -- {CREATURE_NAME}_{x}.{y}_{PARAM}
        // Примечание: из созданий реализован только игрок
        for (auto creature: game_mediator_->getCreatures()) {
            std::string prefix;
            if (dynamic_cast<kernel::Player *>(creature) != nullptr) {
                prefix = "PLAYER_";
            }
            auto hp = creature->getHp();
            std::string point = std::to_string(creature->getPoint().x) + ":" + std::to_string(creature->getPoint().y);
            result["creatures"][prefix + "HP"] = std::to_string(hp.value) + ":" + std::to_string(hp.max);
            result["creatures"][prefix + "DIRECTION"] = direction_to_str_[creature->getDirection()];
            result["creatures"][prefix + "POINT"] = point;
        }
        return result;
    }

    KernelSerializer::~KernelSerializer() {
        delete events_serializer_;
    }

    void KernelSerializer::deserialize(std::map<std::string, std::map<std::string, std::string>> data) {
        if (!events_serializer_) {
            events_serializer_ = new EventsSerializer(game_mediator_->getEventsController());
        }
        // Обязательно должно быть поле, его ширина и высота, а также создания (хотя бы одно - игрок)
        if (!data.count("field") || !data["field"].count("WIDTH") ||
            !data["field"].count("HEIGHT") || !data.count("creatures")) {
            throw MementoException(MementoException::Reason::INCORRECT_DATA, MementoException::Action::LOADING);
        }
        auto new_field = new kernel::Field(std::stoi(data["field"]["WIDTH"]), std::stoi(data["field"]["HEIGHT"]));
        game_mediator_->setField(new_field);
        std::map<std::string, kernel::Cell::Tileset> str_to_tileset{};
        std::map<std::string, kernel::ICreature::Direction> str_to_direction{};
        for (const auto &it: tileset_to_str_) {
            str_to_tileset[it.second] = it.first;
        }
        for (const auto &it: direction_to_str_) {
            str_to_direction[it.second] = it.first;
        }

        // Преобразуем CELL_{x}.{y}_{PARAM} для каждой клетки
        for (const auto &pair: data["field"]) {
            std::string key = pair.first;
            if (key.find("CELL") != std::string::npos) {
                key.erase(0, key.find('_') + 1);
                std::string point_str = key.substr(0, key.find('_'));
                key.erase(0, key.find('_') + 1);
                Point point{
                        std::stoi(point_str.substr(0, point_str.find('.'))),
                        std::stoi(point_str.substr(point_str.find('.') + 1, point_str.size()))
                };
                kernel::Cell *cell = new_field->getCell(point);
                if (key == "TILESET" && str_to_tileset.count(pair.second)) {
                    cell->setTileset(str_to_tileset[pair.second]);
                }
                if (key == "EVENT") {
                    cell->addListener(events_serializer_->deserialize(pair.second));
                }
                if (key == "PASSABLE") {
                    cell->changeState((bool) std::stoi(pair.second));
                }
            }
        }

        // Преобразуем {CREATURE_NAME}_{x}.{y}_{PARAM} для каждого создания (пока для одного игрока)
        for (const auto &pair: data["creatures"]) {
            std::string key = pair.first;
            std::string name = key.substr(0, key.find('_'));
            key.erase(0, key.find('_') + 1);
            if (name == "PLAYER") {
                kernel::ICreature *player = game_mediator_->getPlayer();
                if (key == "HP") {
                    kernel::CreatureParam hp{
                            std::stoi(pair.second.substr(0, pair.second.find(':'))),
                            std::stoi(pair.second.substr(pair.second.find(':') + 1, pair.second.size())),
                    };
                    player->setHpParams(hp);
                }
                if (key == "POINT") {
                    Point point{
                            std::stoi(pair.second.substr(0, pair.second.find(':'))),
                            std::stoi(pair.second.substr(pair.second.find(':') + 1, pair.second.size())),
                    };
                    player->setPoint(point);
                }
                if (key == "DIRECTION" && str_to_direction.count(pair.second)) {
                    player->setDirection(str_to_direction[pair.second]);
                }
            }
        }
        str_to_tileset.clear();
        str_to_direction.clear();
    }
}