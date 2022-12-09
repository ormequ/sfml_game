//
// Created by ilyab on 11.10.2022.
//

#include "PlayerBeatEvent.h"

namespace events {
        void PlayerBeatEvent::dispatch(Point point) {
            player_->takeHit(60);
            dispatchNext(point);
        }

    std::pair<FactoryName, std::string> PlayerBeatEvent::serialize() {
        return {FactoryName::PLAYER, "beat"};
    }
}