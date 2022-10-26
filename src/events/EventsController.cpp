//
// Created by ilyab on 11.10.2022.
//

#include "EventsController.h"

namespace events {

    EventsController::EventsController(GameMediator *game_mediator): game_mediator_(game_mediator) {}

    IEventFactory *EventsController::getFactory(Factory factory_name) {
        IEventFactory *factory = nullptr;
        if (factories_.count(factory_name)) {
            return factories_[factory_name];
        }
        switch (factory_name) {
            case Factory::CELLS:
                factory = new CellsEventFactory(game_mediator_);
                break;
            case Factory::PLAYER:
                factory = new PlayerEventFactory(game_mediator_);
                break;
            case Factory::GAME_STATE:
                factory = new GameStateEventFactory(game_mediator_);
                break;
            case Factory::MAP:
                factory = new MapEventFactory(game_mediator_);
                break;
        }
        factories_[factory_name] = factory;
        return factory;
    }

    EventsController::~EventsController() {
        for (auto factory : factories_) {
            delete factory.second;
        }
        factories_.clear();
    }

    EventChainLink *EventsController::produce(EventsController::Factory factory_name, const std::string& type) {
        IEventFactory *factory = getFactory(factory_name);
        if (factory != nullptr) {
            return factory->produce(type);
        } else {
            return nullptr;
        }
    }

    EventChainLink *EventsController::getEmptyEvent() {
        return new EmptyEvent;
    }
}