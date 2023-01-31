//
// Created by ilyab on 27.11.2022.
//

#ifndef GAME_PLAYERPOSITIONRULE_H
#define GAME_PLAYERPOSITIONRULE_H

#include "../../GameMediator.h"

namespace mapmaker {
    /// Правило смены позиции игрока
    template<unsigned int x, unsigned int y>
    class PlayerPositionRule {
    public:
        explicit PlayerPositionRule(GameMediator *game_mediator) : game_mediator_(game_mediator) {};

        void operator()() {
            if (game_mediator_->getField()->getCell({x, y})->isPassable()) {
                game_mediator_->getPlayer()->setPoint({x, y});
            }
        }
    private:
        GameMediator *game_mediator_;
    };
}


#endif //GAME_PLAYERPOSITIONRULE_H
