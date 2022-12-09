//
// Created by ilyab on 11.10.2022.
//

#include "PlayerHealEvent.h"

namespace events {
    void PlayerHealEvent::dispatch(Point point) {
        player_->heal(40);
        dispatchNext(point);
    }

    std::pair<FactoryName, std::string> PlayerHealEvent::serialize() {
        return {FactoryName::PLAYER, "heal"};
    }
}