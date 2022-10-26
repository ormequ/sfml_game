//
// Created by ilyab on 12.10.2022.
//

#ifndef GAME_GAMESTATEEVENT_H
#define GAME_GAMESTATEEVENT_H


namespace events {
    class GameStateEvent;
}
#include "../EventChainLink.h"
#include "../../GameStateController.h"

namespace events {
    class GameStateEvent : public EventChainLink {
    public:
        explicit GameStateEvent(IGameState *game_state_controller);
    protected:
        IGameState *game_state_controller_;
    };
}

#endif //GAME_GAMESTATEEVENT_H
