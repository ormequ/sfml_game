//
// Created by ilyab on 11.10.2022.
//

#include "PlayerEventFactory.h"

namespace events {

    EventChainLink *PlayerEventFactory::produce(const std::string& type) {
        if (type == "beat") {
            return new PlayerBeatEvent(game_mediator_->getPlayer());
        }
        if (type == "heal") {
            return new PlayerHealEvent(game_mediator_->getPlayer());
        }
        return nullptr;
    }

    PlayerEventFactory::PlayerEventFactory(GameMediator *game_mediator) : game_mediator_(game_mediator) {}

}