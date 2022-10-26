//
// Created by ilyab on 12.10.2022.
//

#include "GameStateEvent.h"
namespace events {
    GameStateEvent::GameStateEvent(IGameState *game_state_controller) : game_state_controller_(game_state_controller) {}
}