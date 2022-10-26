//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_PLAYERBEATEVENT_H
#define GAME_PLAYERBEATEVENT_H

#include "PlayerEvent.h"

namespace events {
    class PlayerBeatEvent : public PlayerEvent {
    public:
        using PlayerEvent::PlayerEvent;

        void dispatch(Point point) override;

        ~PlayerBeatEvent() override = default;
    };
}


#endif //GAME_PLAYERBEATEVENT_H
