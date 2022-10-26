//
// Created by ilyab on 25.10.2022.
//

#ifndef GAME_MAPMAKEFORESTEVENT_H
#define GAME_MAPMAKEFORESTEVENT_H

namespace events {
    class MapMakeForestEvent;
}

#include "../EventChainLink.h"
#include "../../mapmaker/MapMaker.h"

namespace events {
    class MapMakeForestEvent : public EventChainLink {
    public:
        explicit MapMakeForestEvent(mapmaker::MapMaker *map_maker);

        void dispatch(Point point) override;

        ~MapMakeForestEvent() override = default;
    protected:
        mapmaker::MapMaker *map_maker_;
    };
}


#endif //GAME_MAPMAKEFORESTEVENT_H
