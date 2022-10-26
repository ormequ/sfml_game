//
// Created by ilyab on 12.10.2022.
//

#include "GameStateEventFactory.h"

namespace events {

    EventChainLink *GameStateEventFactory::produce(const std::string& type) {
        if (type == "win") {
            return new GameWinEvent(game_mediator_->getStateController());
        }
        return nullptr;
    }

    GameStateEventFactory::GameStateEventFactory(GameMediator *game_mediator) : game_mediator_(game_mediator) {}

}