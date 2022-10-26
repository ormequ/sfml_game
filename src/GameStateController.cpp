//
// Created by ilyab on 12.10.2022.
//

#include "GameStateController.h"

void GameStateController::setState(GameStateController::State state) {
    state_ = state;
}

GameStateController::State GameStateController::getState() {
    return state_;
}
