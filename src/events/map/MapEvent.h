//
// Created by ilyab on 25.10.2022.
//

#ifndef GAME_MAPEVENT_H
#define GAME_MAPEVENT_H

namespace events {
    class MapEvent;
}

#include "../EventChainLink.h"
#include "../../mapmaker/MapMaker.h"

namespace events {
    class MapEvent : public EventChainLink {
    public:
        explicit MapEvent(mapmaker::MapMaker *map_maker);
    protected:
        mapmaker::MapMaker *map_maker_;
    };
}

#endif //GAME_MAPEVENT_H
