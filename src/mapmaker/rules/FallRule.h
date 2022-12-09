//
// Created by ilyab on 27.11.2022.
//

#ifndef GAME_FALLRULE_H
#define GAME_FALLRULE_H

#include "../../GameMediator.h"

namespace mapmaker {
    template<unsigned int x, unsigned int y>
    class FallRule {
    public:
        explicit FallRule(GameMediator *game_mediator) : game_mediator_(game_mediator) {};

        void operator()() {
            game_mediator_->addCellEvent(
                {x, y},
                game_mediator_->getEventsController()->produce(events::FactoryName::PLAYER, "beat"),
                kernel::Cell::Tileset::HOLE,
                []() {
                    std::random_device dev;
                    std::mt19937 rng(dev());
                    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 2);
                    return (bool) dist(rng);
                }
            );
        }
    private:
        GameMediator *game_mediator_;
    };
}

#endif //GAME_FALLRULE_H
