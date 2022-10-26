//
// Created by ilyab on 25.10.2022.
//

#ifndef GAME_IGAMESTATE_H
#define GAME_IGAMESTATE_H

class IGameState {
public:
    enum class State {
        START, WIN, LOSE, UNKNOWN
    };

    virtual State getState() = 0;

    virtual void setState(State state) = 0;

    virtual ~IGameState() = default;
};

#endif //GAME_IGAMESTATE_H
