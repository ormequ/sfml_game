//
// Created by ilyab on 21.09.2022.
//

#include "GameMediator.h"

void GameMediator::init(
    kernel::KernelController *kernel_controller, view::ViewController *view_controller,
    mapmaker::MapGenerator *map_generator, events::EventsController *events_controller,
    logger::LoggerController *logger_controller, memento::MementoController *memento_controller
) {
    kernel_controller_ = kernel_controller;
    view_controller_ = view_controller;
    map_generator_ = map_generator;
    events_controller_ = events_controller;
    logger_controller_ = logger_controller;
    memento_controller_ = memento_controller;

    game_state_controller_ = logger_controller_->getProxy(new GameStateController);
    game_state_controller_->setState(IGameState::State::START);
    kernel_controller_->setPlayer(
        logger_controller_->getProxy(kernel_controller_->getPlayer()),
        false
    );
}

const kernel::IField *GameMediator::readField() const {
    return kernel_controller_->getField();
}

kernel::ICreature *GameMediator::getPlayer() {
    return kernel_controller_->getPlayer();
}

std::vector<kernel::ICreature *> GameMediator::getCreatures() {
    return kernel_controller_->getCreatureManager()->getAllCreatures();
}

kernel::IField *GameMediator::getField() {
    if (!kernel_controller_->getField()) {
        setField(new kernel::Field);
    }
    return kernel_controller_->getField();
}

events::EventsController *GameMediator::getEventsController() {
    return events_controller_;
}

void GameMediator::update() {
    kernel_controller_->update();
}

GameStateController::State GameMediator::getState() {
    return game_state_controller_->getState();
}

IGameState *GameMediator::getStateController() {
    return game_state_controller_;
}

void GameMediator::setState(GameStateController::State state) {
    game_state_controller_->setState(state);
}

void GameMediator::setField(kernel::IField *field) {
    // При изменении навешиваем логирование на поле
    kernel_controller_->setField(logger_controller_->getProxy(field));
}

std::string GameMediator::askUser(const std::string &question, const std::vector<std::string> &answers) {
    return view_controller_->ask(question, answers);
}

void GameMediator::addCellEvent(
    Point point, events::EventChainLink *event, kernel::Cell::Tileset tileset, const std::function<bool()> &is_able
) {
    // События реализованы цепочкой обязанностей (см. папку events),
    // поэтому добавляем событие в конец цепочки
    kernel::Cell *cell = kernel_controller_->getField()->getCell(point);
    events::EventChainLink *listener = cell->getListener();
    if (listener) {
        listener->setTransmitChecker(is_able);
        listener->addToEnd(event);
    } else {
        // Навешиваем логирование, если это первое событие в данной клетке
        cell->addListener(
            logger_controller_->getProxy(events::EventsController::getEmptyEvent())
                ->setTransmitChecker(is_able)
                ->addNext(event)
                ->getFirst()
        );
    }
    cell->setTileset(tileset);
}

mapmaker::MapGenerator *GameMediator::getMapGenerator() {
    return map_generator_;
}

GameMediator::~GameMediator() {
    delete game_state_controller_;
}

void GameMediator::rotateCreature(kernel::ICreature *creature, kernel::ICreature::Direction direction) {
    kernel_controller_->rotateCreature(creature, direction);

}

void GameMediator::moveCreature(kernel::ICreature *creature, Point point) {
    try {
        kernel_controller_->moveCreature(creature, point);
    } catch (std::exception &e) {
        // Если перешло сюда, значит, скорее всего, клетка непроходима
        logger_controller_->catchException(e);
    }
}

void GameMediator::save() {
    memento_controller_->save();
}

void GameMediator::load(const std::string& filename) {
    memento_controller_->load(filename);
}
