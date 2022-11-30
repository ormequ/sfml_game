//
// Created by ilyab on 11.10.2022.
//

#include "PlayerHealEvent.h"

namespace events {
    void PlayerHealEvent::dispatch(Point point) {
        player_->heal(40);
        dispatchNext(point);
    }
}