//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_PLAYEREVENTFACTORY_H
#define GAME_PLAYEREVENTFACTORY_H

#include "../IEventFactory.h"
#include "../../GameMediator.h"
#include "PlayerHealEvent.h"
#include "PlayerBeatEvent.h"
//#include "CellsImprisonEvent.h"

namespace events {
    class PlayerEventFactory : public IEventFactory {
    public:
        explicit PlayerEventFactory(GameMediator *game_mediator);

        EventChainLink *produce(const std::string& type) override;

        ~PlayerEventFactory() override = default;
    private:
        GameMediator *game_mediator_;
    };
}


#endif //GAME_PLAYEREVENTFACTORY_H
