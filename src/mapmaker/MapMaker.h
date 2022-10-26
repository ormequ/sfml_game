//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_MAPMAKER_H
#define GAME_MAPMAKER_H

namespace mapmaker {
    class MapMaker;
}

#include "../kernel/field/Field.h"
#include "../GameMediator.h"
#include "../events/EventsController.h"
#include "../events/EventChainLink.h"

namespace mapmaker {
    class MapMaker {
    public:
        explicit MapMaker(GameMediator *game_mediator);

        void generate();

        void generateByEvent();
    protected:
        typedef kernel::Cell::Tileset Cell_Tileset;
        GameMediator *game_mediator_;
    };
}

#endif //GAME_MAPMAKER_H
