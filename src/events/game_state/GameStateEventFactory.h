//
// Created by ilyab on 12.10.2022.
//

#ifndef GAME_GAMESTATEEVENTFACTORY_H
#define GAME_GAMESTATEEVENTFACTORY_H

namespace events {
    class GameStateEventFactory;
}

#include "../IEventFactory.h"
#include "../../GameMediator.h"
#include "GameWinEvent.h"

namespace events {
    class GameStateEventFactory : public IEventFactory {
    public:
        explicit GameStateEventFactory(GameMediator *game_mediator);

        EventChainLink *produce(const std::string& type) override;

        ~GameStateEventFactory() override = default;
    protected:
        GameMediator *game_mediator_;
    };
}
#endif //GAME_GAMESTATEEVENTFACTORY_H
