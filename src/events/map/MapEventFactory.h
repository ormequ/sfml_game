//
// Created by ilyab on 25.10.2022.
//

#ifndef GAME_MAPEVENTFACTORY_H
#define GAME_MAPEVENTFACTORY_H

namespace events {
    class MapEventFactory;
}

#include "MapEvent.h"
#include "../IEventFactory.h"
#include "../../GameMediator.h"
#include "MapMakeForestEvent.h"

namespace events {
    class MapEventFactory : public IEventFactory {
    public:
        explicit MapEventFactory(GameMediator *game_mediator);

        EventChainLink *produce(const std::string& type) override;

        ~MapEventFactory() override = default;
    protected:
        GameMediator *game_mediator_;
    };
}



#endif //GAME_MAPEVENTFACTORY_H
