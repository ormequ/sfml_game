//
// Created by ilyab on 25.10.2022.
//

#include "MapEventFactory.h"

namespace events {

    EventChainLink *MapEventFactory::produce(const std::string& type) {
        if (type == "forest") {
            return new MapMakeForestEvent(game_mediator_->getMapMaker());
        }
        return nullptr;
    }

    MapEventFactory::MapEventFactory(GameMediator *game_mediator) : game_mediator_(game_mediator) {}

}