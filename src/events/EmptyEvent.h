//
// Created by ilyab on 12.10.2022.
//

#ifndef GAME_EMPTYEVENT_H
#define GAME_EMPTYEVENT_H

namespace events {
    class EmptyEvent;
}

#include "EventChainLink.h"

namespace events {

    class EmptyEvent final : public  EventChainLink {
    public:
        void dispatch(Point point) final;
    };

}


#endif //GAME_EMPTYEVENT_H
