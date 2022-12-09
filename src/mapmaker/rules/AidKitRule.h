//
// Created by ilyab on 27.11.2022.
//

#ifndef GAME_AIDKITRULE_H
#define GAME_AIDKITRULE_H

#include "../../GameMediator.h"

namespace mapmaker {
    template<unsigned int x, unsigned int y>
    class AidKitRule {
    public:
        explicit AidKitRule(GameMediator *game_mediator) : game_mediator_(game_mediator) {};

        void operator()() {
            game_mediator_->addCellEvent(
                {x, y},
                game_mediator_->getEventsController()->produce(events::FactoryName::PLAYER, "heal"),
                kernel::Cell::Tileset::AID_KIT
            );
        }
    private:
        GameMediator *game_mediator_;
    };
}

#endif //GAME_AIDKITRULE_H
