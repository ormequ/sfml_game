//
// Created by ilyab on 20.09.2022.
//

#ifndef GAME_IEVENT_H
#define GAME_IEVENT_H

namespace events {
    class IEvent;
}

#include "../Point.h"

namespace events {
    class IEvent {
    public:
        virtual void dispatch(Point position) = 0;
        virtual ~IEvent() = default;
    };
}

#endif //GAME_IEVENT_H
