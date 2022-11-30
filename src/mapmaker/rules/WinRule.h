//
// Created by ilyab on 26.11.2022.
//

#ifndef GAME_WINRULE_H
#define GAME_WINRULE_H

#include "../../GameMediator.h"

namespace mapmaker {
    template<unsigned int x, unsigned int y>
    class WinRule {
    public:
        explicit WinRule(GameMediator *game_mediator) : game_mediator_(game_mediator) {};

        void operator()() {
            game_mediator_->addCellEvent(
                {x, y},
                game_mediator_->getEventsController()->produce(
                    events::EventsController::Factory::GAME_STATE,
                    "win"
                ),
                kernel::Cell::Tileset::TORII,
                [this]() {
                    kernel::CreatureParam hp = game_mediator_->getPlayer()->getHp();
                    return hp.max / hp.value < 2;
                }
            );
            game_mediator_->getField()->getCell({x, y})->changeState(true);
        }
    private:
        GameMediator *game_mediator_;
    };
}

#endif //GAME_WINRULE_H
