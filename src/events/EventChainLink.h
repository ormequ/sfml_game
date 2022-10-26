//
// Created by ilyab on 12.10.2022.
//

#ifndef GAME_EVENTCHAINLINK_H
#define GAME_EVENTCHAINLINK_H

namespace events {
    class EventChainLink;
}

#include <functional>
#include "IEvent.h"

namespace events {
    class EventChainLink : public IEvent {
    public:
        EventChainLink *addNext(EventChainLink *next, bool delete_previous = false);

        EventChainLink *getFirst();

        void setPrevious(EventChainLink *previous);

        void dispatchNext(Point point);

        EventChainLink *setTransmitChecker(std::function<bool()> transmit_checker);

        virtual ~EventChainLink();

    protected:
        EventChainLink *prev_chain_link_ = nullptr;
        EventChainLink *next_chain_link_ = nullptr;
        std::function<bool()> transmit_checker_ = []() { return true; };
    };
}


#endif //GAME_EVENTCHAINLINK_H
