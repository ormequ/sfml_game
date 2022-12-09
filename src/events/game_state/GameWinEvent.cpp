//
// Created by ilyab on 12.10.2022.
//

#include "GameWinEvent.h"
namespace events {
    void GameWinEvent::dispatch(Point point) {
        game_state_controller_->setState(GameStateController::State::WIN);
//        a->getPlayer()->getHp();
//        if (hp.max == hp.value) {
//            game_mediator_->setState(GameMediator::GameState::WIN);
//        }
    }

    std::pair<FactoryName, std::string> GameWinEvent::serialize() {
        return {FactoryName::GAME_STATE, "win"};
    }
}