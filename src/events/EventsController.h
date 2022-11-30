//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_EVENTSCONTROLLER_H
#define GAME_EVENTSCONTROLLER_H

namespace events {
    class EventsController;
}

#include <string>
#include <map>
#include "../GameMediator.h"
#include "cells/CellsEventFactory.h"
#include "player/PlayerEventFactory.h"
#include "game_state/GameStateEventFactory.h"
#include "map/MapEventFactory.h"
#include "EmptyEvent.h"

namespace events {
    class EventsController {
    public:
        enum class Factory {
            CELLS, PLAYER, GAME_STATE, MAP
        };

        explicit EventsController(GameMediator *game_mediator);

        IEventFactory *getFactory(Factory factory);

        EventChainLink *produce(Factory factory_name, const std::string& type);

        static EventChainLink *getEmptyEvent();

        ~EventsController();
    protected:
        GameMediator *game_mediator_;
        std::map<Factory, IEventFactory *> factories_;
    };
}


#endif //GAME_EVENTSCONTROLLER_H
