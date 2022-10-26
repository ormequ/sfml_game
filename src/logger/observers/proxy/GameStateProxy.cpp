//
// Created by ilyab on 25.10.2022.
//

#include "GameStateProxy.h"

namespace logger {
    GameStateProxy::GameStateProxy(IGameState *game_state) : game_state_(game_state) {}

    IGameState::State GameStateProxy::getState() {
        return game_state_->getState();
    }

    void GameStateProxy::setState(IGameState::State state) {
        switch (state) {
            case State::START:
                notify("The game has been started");
                break;
            case State::LOSE:
                notify("GAME OVER! You lose");
                break;
            case State::WIN:
                notify("GAME OVER! You win");
                break;
            default:
                notify("Unknown game state!");
        }
        game_state_->setState(state);
    }

    GameStateProxy::~GameStateProxy() {
        delete game_state_;
    }

    LogLevel GameStateProxy::getLogLevel() {
        return LogLevel::GAME_STATE;
    }
}