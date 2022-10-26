//
// Created by ilyab on 12.10.2022.
//

#ifndef GAME_GAMESTATECONTROLLER_H
#define GAME_GAMESTATECONTROLLER_H

#include "IGameState.h"

class GameStateController : public IGameState {
public:
    void setState(State state) override;

    State getState() override;
private:
    State state_ = State::UNKNOWN;
};


#endif //GAME_GAMESTATECONTROLLER_H
