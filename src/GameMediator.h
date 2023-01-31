//
// Created by ilyab on 21.09.2022.
//

#ifndef GAME_GAMEMEDIATOR_H
#define GAME_GAMEMEDIATOR_H

class GameMediator;

#include <string>
#include <iostream>
#include "view/ViewController.h"
#include "kernel/KernelController.h"
#include "events/EventsController.h"
#include "Point.h"
#include "mapmaker/MapGenerator.h"
#include "GameStateController.h"
#include "logger/LoggerController.h"
#include "memento/MementoController.h"

/**
 * Связующее звено между всеми компонентами игры
 * Паттерн -- Mediator
 * */
class GameMediator {
public:
    /// Вместо конструктора, чтобы остальным объектам можно было передать медиатора
    void init(
        kernel::KernelController *, view::ViewController *, mapmaker::MapGenerator *, events::EventsController *,
        logger::LoggerController *, memento::MementoController *
    );

    /// Обновить состояние игры
    void update();

    events::EventsController *getEventsController();

    ///@return поле только для чтения
    [[nodiscard]] const kernel::IField *readField() const;

    ///@return поле для записи
    kernel::IField *getField();

    /// Поворот создания на направление direction
    void rotateCreature(kernel::ICreature *creature, kernel::ICreature::Direction direction);

    /// Движение существа на клетку point, если она доступна
    void moveCreature(kernel::ICreature *creature, Point point);

    kernel::ICreature *getPlayer();

    std::vector<kernel::ICreature *> getCreatures();

    /// Перезапись поля (изменение карты)
    void setField(kernel::IField *field);

    GameStateController::State getState();

    void setState(GameStateController::State state);

    IGameState *getStateController();

    /// Сохранение игры
    void save();

    /// Загрузка игры
    void load(const std::string& filename);

    /**
     * Задать пользователю вопрос
     * @param question вопрос
     * @param answers варианты ответа
     *
     * @return ответ
     * */
    std::string askUser(const std::string &question, const std::vector<std::string> &answers);

    /**
     * Добавить событие на клетку
     *
     * @param point клетка
     * @param event событие
     * @param tileset внешний вид клетки после добавления события
     * @param is_able условие вызова события
     * */
    void addCellEvent(
        Point point, events::EventChainLink *event,
        kernel::Cell::Tileset tileset = kernel::Cell::Tileset::GRASS,
        const std::function<bool()>& is_able = []() { return true; }
    );

    mapmaker::MapGenerator *getMapGenerator();

    ~GameMediator();

protected:
    kernel::KernelController *kernel_controller_ = nullptr;
    view::ViewController *view_controller_ = nullptr;
    mapmaker::MapGenerator *map_generator_ = nullptr;
    events::EventsController *events_controller_ = nullptr;
    logger::LoggerController *logger_controller_ = nullptr;
    memento::MementoController *memento_controller_ = nullptr;
    IGameState *game_state_controller_ = nullptr;
};


#endif //GAME_GAMEMEDIATOR_H
