//
// Created by ilyab on 21.10.2022.
//

#ifndef GAME_EVENTPROXY_H
#define GAME_EVENTPROXY_H

#include "../../../events/EventChainLink.h"
#include "../../AbstractObserver.h"

namespace logger {
    class EventProxy : public events::EventChainLink, public AbstractObserver {
    public:
        explicit EventProxy(events::IEvent *event);

        void dispatch(Point position) override;

        std::pair<events::FactoryName, std::string> serialize() override;

        ~EventProxy() override;

    protected:
        LogLevel getLogLevel() override;

        events::IEvent *event_;
        Point call_point_{-1, -1};
    };
}


#endif //GAME_EVENTPROXY_H
