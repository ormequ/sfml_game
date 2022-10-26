//
// Created by ilyab on 12.10.2022.
//

#ifndef GAME_GAMEWINEVENT_H
#define GAME_GAMEWINEVENT_H


class GameWinEvent {

};
namespace events {
    class GameWinEvent;
}

//#include "../EventChainLink.h"
#include "GameStateEvent.h"

namespace events {
    class GameWinEvent : public GameStateEvent {
    public:
        using GameStateEvent::GameStateEvent;

        void dispatch(Point point) override;

        ~GameWinEvent() override = default;
    };
}

#endif //GAME_GAMEWINEVENT_H
