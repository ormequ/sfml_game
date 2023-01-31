//
// Created by ilyab on 29.11.2022.
//

#ifndef GAME_CHANGEMAPRULE_H
#define GAME_CHANGEMAPRULE_H

#include "../../GameMediator.h"

namespace mapmaker {
    /// Правило добавления события изменения карты на лес
    template<unsigned int x, unsigned int y>
    class ChangeMapRule {
    public:
        explicit ChangeMapRule(GameMediator *game_mediator) : game_mediator_(game_mediator) {};

        void operator()() {
            game_mediator_->addCellEvent(
                {x, y},
                game_mediator_->getEventsController()->produce(events::FactoryName::MAP, "forest"),
                kernel::Cell::Tileset::TUNNEL
            );
        }
    private:
        GameMediator *game_mediator_;
    };
}

#endif //GAME_CHANGEMAPRULE_H
