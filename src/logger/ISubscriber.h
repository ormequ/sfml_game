//
// Created by ilyab on 21.10.2022.
//

#ifndef GAME_ISUBSCRIBER_H
#define GAME_ISUBSCRIBER_H

#include "LoggerMessage.h"

namespace logger {
    class ISubscriber {
    public:
        virtual void notify(const LoggerMessage &message) = 0;

        virtual ~ISubscriber() = default;
    };
}

#endif //GAME_ISUBSCRIBER_H
