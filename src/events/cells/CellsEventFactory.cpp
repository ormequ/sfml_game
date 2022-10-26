//
// Created by ilyab on 11.10.2022.
//

#include "CellsEventFactory.h"

namespace events {

    EventChainLink *CellsEventFactory::produce(const std::string& type) {
        if (type == "imprison") {
            return new CellsImprisonEvent(game_mediator_->getField());
        }
        return nullptr;
    }

    CellsEventFactory::CellsEventFactory(GameMediator *game_mediator) : game_mediator_(game_mediator) {

    }

}