//
// Created by ilyab on 27.11.2022.
//

#ifndef GAME_TRAPBUTTONRULE_H
#define GAME_TRAPBUTTONRULE_H

#include "../../GameMediator.h"

namespace mapmaker {
    /// Правило ловушки
    template<unsigned int x, unsigned int y>
    class TrapButtonRule {
    public:
        explicit TrapButtonRule(GameMediator *game_mediator) : game_mediator_(game_mediator) {};

        void operator()() {
            game_mediator_->addCellEvent(
                {x, y},
                game_mediator_->getEventsController()->produce(events::FactoryName::CELLS, "imprison"),
                kernel::Cell::Tileset::BUTTON
            );
            game_mediator_->addCellEvent(
                {x, y},
                game_mediator_->getEventsController()->produce(events::FactoryName::PLAYER, "heal"),
                kernel::Cell::Tileset::BUTTON,
                []() {
                    std::random_device dev;
                    std::mt19937 rng(dev());
                    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1);
                    return (bool) dist(rng);
                }
            );
            game_mediator_->getField()->getCell({x, y})->changeState(true);
        }

    private:
        GameMediator *game_mediator_;
    };
}


#endif //GAME_TRAPBUTTONRULE_H
