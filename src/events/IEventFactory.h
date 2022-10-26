//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_IEVENTFACTORY_H
#define GAME_IEVENTFACTORY_H

namespace events {
    class IEventFactory;
}

#include <string>
#include "EventChainLink.h"

namespace events {
    class IEventFactory {
    public:
        virtual EventChainLink *produce(const std::string& type) = 0;

        virtual ~IEventFactory() = default;
    };
}

#endif //GAME_IEVENTFACTORY_H
