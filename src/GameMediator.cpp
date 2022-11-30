//
// Created by ilyab on 21.09.2022.
//

#include "GameMediator.h"

void GameMediator::init(
    kernel::KernelController *kernel_controller, view::ViewController *view_controller,
    mapmaker::MapGenerator *map_generator, events::EventsController *events_controller,
    logger::LoggerController *logger_controller
) {
    kernel_controller_ = kernel_controller;
    view_controller_ = view_controller;
    map_generator_ = map_generator;
    events_controller_ = events_controller;
    logger_controller_ = logger_controller;

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

/*void GameMediator::moveCreature(kernel::ICreature::Direction direction) {
    kernel::ICreature *player = kernel_controller_->getPlayer();
    Point pos = player->getPoint();
    switch (direction) {
        case kernel::ICreature::Direction::UP:
            pos.y--;
            break;
        case kernel::ICreature::Direction::LEFT:
            pos.x--;
            break;
        case kernel::ICreature::Direction::DOWN:
            pos.y++;
            break;
        case kernel::ICreature::Direction::RIGHT:
            pos.x++;
            break;
        default:
            return;
    }
    try {
        kernel_controller_->moveCreature(player, pos);
    } catch (std::exception &e) {
        logger_controller_->catchException(e);
    }
    kernel_controller_->rotateCreature(player, direction);
}*/

kernel::IField *GameMediator::getField() {
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
    kernel_controller_->setField(logger_controller_->getProxy(field));
}

std::string GameMediator::askUser(const std::string &question, const std::vector<std::string> &answers) {
    // return "console errors";
    return view_controller_->ask(question, answers);
}

void GameMediator::addCellEvent(
    Point point, events::EventChainLink *event, kernel::Cell::Tileset tileset, const std::function<bool()> &is_able
) {
    kernel::Cell *cell = kernel_controller_->getField()->getCell(point);
    events::EventChainLink *listener = cell->getListener();
    if (listener) {
        listener->addToEnd(event);
        /*cell->addListener(
            listener
                ->setTransmitChecker(is_able)
                ->addNext(logger_controller_->getProxy(event))
                ->getFirst(),
            false
        );*/
        // auto *l2 = cell->getListener();
        // l2->getFirst();
        // cell->addListener(listener);
    } else {
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
        logger_controller_->catchException(e);
    }
}
