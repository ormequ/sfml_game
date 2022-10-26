//
// Created by ilyab on 25.10.2022.
//

#include "MapMakeForestEvent.h"

namespace events {

    MapMakeForestEvent::MapMakeForestEvent(mapmaker::MapMaker *map_maker) : map_maker_(map_maker) {}

    void MapMakeForestEvent::dispatch(Point point) {
        map_maker_->generateByEvent();
    }

}