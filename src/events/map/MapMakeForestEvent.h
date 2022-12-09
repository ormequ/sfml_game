//
// Created by ilyab on 25.10.2022.
//

#ifndef GAME_MAPMAKEFORESTEVENT_H
#define GAME_MAPMAKEFORESTEVENT_H

namespace events {
    class MapMakeForestEvent;
}

#include "../EventChainLink.h"
#include "../../mapmaker/MapGenerator.h"

namespace events {
    class MapMakeForestEvent : public EventChainLink {
    public:
        explicit MapMakeForestEvent(mapmaker::MapGenerator *map_generator);

        void dispatch(Point point) override;

        std::pair<FactoryName, std::string> serialize() override;

        ~MapMakeForestEvent() override = default;
    protected:
        mapmaker::MapGenerator *map_generator_;
    };
}


#endif //GAME_MAPMAKEFORESTEVENT_H
