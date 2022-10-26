//
// Created by ilyab on 25.10.2022.
//

#ifndef GAME_GAMESTATEPROXY_H
#define GAME_GAMESTATEPROXY_H

namespace logger {
    class GameStateProxy;
}

#include "../../../IGameState.h"
#include "../../AbstractObserver.h"

namespace logger {
    class GameStateProxy : public IGameState, public AbstractObserver {
    public:
        explicit GameStateProxy(IGameState *game_state);

        State getState() override;

        void setState(State state) override;

        ~GameStateProxy() override;
    protected:
        LogLevel getLogLevel() override;

        IGameState *game_state_;
    };
}



#endif //GAME_GAMESTATEPROXY_H
