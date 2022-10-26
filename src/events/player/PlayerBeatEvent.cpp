//
// Created by ilyab on 11.10.2022.
//

#include "PlayerBeatEvent.h"

namespace events {
        void PlayerBeatEvent::dispatch(Point point) {
            player_->takeHit(100);
            dispatchNext(point);
        }
}