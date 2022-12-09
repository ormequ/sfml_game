//
// Created by User on 06.12.2022.
//

#ifndef GAME_EVENTSSERIALIZER_H
#define GAME_EVENTSSERIALIZER_H

namespace memento {
    class EventsSerializer;
}

#include "../events/EventsController.h"
#include "MementoException.h"

namespace memento {
    class EventsSerializer {
    public:
        explicit EventsSerializer(events::EventsController *events_controller);

        std::string serialize(events::EventChainLink *event);

        events::EventChainLink *deserialize(const std::string &string);

        ~EventsSerializer();
    private:
        events::EventsController *events_controller_;
        std::map<std::string, events::FactoryName> string_to_factory_;
        std::map<events::FactoryName, std::string> factory_to_string_{
                {events::FactoryName::CELLS,      "cells"},
                {events::FactoryName::PLAYER,     "player"},
                {events::FactoryName::MAP,        "map"},
                {events::FactoryName::GAME_STATE, "game_state"}
        };
    };
}


#endif //GAME_EVENTSSERIALIZER_H
