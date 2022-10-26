//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_CELLSEVENTFACTORY_H
#define GAME_CELLSEVENTFACTORY_H

#include "../IEventFactory.h"
#include "../../GameMediator.h"
#include "CellsImprisonEvent.h"

namespace events {
    class CellsEventFactory : public IEventFactory {
    public:
        explicit CellsEventFactory(GameMediator *game_mediator);

        EventChainLink *produce(const std::string& type) override;

        ~CellsEventFactory() override = default;
    private:
        GameMediator *game_mediator_;
    };
}


#endif //GAME_CELLSEVENTFACTORY_H
