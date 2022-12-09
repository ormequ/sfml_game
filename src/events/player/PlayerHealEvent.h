//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_PLAYERHEALEVENT_H
#define GAME_PLAYERHEALEVENT_H

#include "PlayerEvent.h"

namespace events {
    class PlayerHealEvent : public  PlayerEvent {
    public:
        using PlayerEvent::PlayerEvent;

        void dispatch(Point point) override;

        std::pair<FactoryName, std::string> serialize() override;

        ~PlayerHealEvent() override = default;
    };
}


#endif //GAME_PLAYERHEALEVENT_H
