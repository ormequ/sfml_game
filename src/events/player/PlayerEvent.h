//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_PLAYEREVENT_H
#define GAME_PLAYEREVENT_H

#include "../EventChainLink.h"
#include "../../kernel/creatures/Player.h"

namespace events {
    class PlayerEvent : public EventChainLink {
    public:
        explicit PlayerEvent(kernel::ICreature *player);
    protected:
        kernel::ICreature *player_;
    };
}


#endif //GAME_PLAYEREVENT_H
