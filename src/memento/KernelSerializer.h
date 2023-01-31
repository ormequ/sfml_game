//
// Created by User on 06.12.2022.
//

#ifndef GAME_KERNELSERIALIZER_H
#define GAME_KERNELSERIALIZER_H


namespace memento {
    class KernelSerializer;
}

#include <string>
#include <map>
#include "EventsSerializer.h"
#include "../../GameMediator.h"
#include "MementoException.h"

namespace memento {
    /// Класс, преобразующий ядро (см. папку kernel) в std::map и обратно
    class KernelSerializer {
    public:
        explicit KernelSerializer(GameMediator *game_mediator);

        std::map<std::string, std::map<std::string, std::string>> serialize();

        void deserialize(std::map<std::string, std::map<std::string, std::string>> data);

        ~KernelSerializer();
    private:
        EventsSerializer *events_serializer_ = nullptr;
        GameMediator *game_mediator_;
            std::map<kernel::ICreature::Direction, std::string> direction_to_str_ {
                {kernel::ICreature::Direction::UP, "UP"},
                {kernel::ICreature::Direction::DOWN, "DOWN"},
                {kernel::ICreature::Direction::LEFT, "LEFT"},
                {kernel::ICreature::Direction::RIGHT, "RIGHT"},
        };
        std::map<kernel::Cell::Tileset, std::string> tileset_to_str_ {
                {kernel::Cell::Tileset::GRASS,             "GRASS"},
                {kernel::Cell::Tileset::HOLE,              "HOLE"},
                {kernel::Cell::Tileset::ROCK,              "ROCK"},
                {kernel::Cell::Tileset::WATER_GLARE,       "WATER_GLARE"},
                {kernel::Cell::Tileset::WATER_LILY,        "WATER_LILY"},
                {kernel::Cell::Tileset::WATER_FISH,        "WATER_FISH"},
                {kernel::Cell::Tileset::BUTTON,            "BUTTON"},
                {kernel::Cell::Tileset::FENCE_VERTICAL,    "FENCE_VERTICAL"},
                {kernel::Cell::Tileset::FENCE_HORIZONTAL,  "FENCE_HORIZONTAL"},
                {kernel::Cell::Tileset::SMALL_IRON_PILLAR, "SMALL_IRON_PILLAR"},
                {kernel::Cell::Tileset::AID_KIT,           "AID_KIT"},
                {kernel::Cell::Tileset::TORII,             "TORII"},
                {kernel::Cell::Tileset::TUNNEL,            "TUNNEL"},
                {kernel::Cell::Tileset::TREE_OAK,          "TREE_OAK"},
                {kernel::Cell::Tileset::TREE_SPRUCE,       "TREE_SPRUCE"}
        };
    };
}


#endif //GAME_KERNELSERIALIZER_H
