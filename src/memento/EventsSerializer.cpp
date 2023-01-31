//
// Created by User on 06.12.2022.
//

#include "EventsSerializer.h"

namespace memento {
    std::string EventsSerializer::serialize(events::EventChainLink *event) {
        // События реализованы в виде цепочки обязанностей
        std::pair<events::FactoryName, std::string> serialized = event->serialize();
        if (serialized.second.empty()) {
            if (event->getNext() != nullptr) {
                return serialize(event->getNext());
            }
            return "";
        }
        // Из двух событий получим строку FactoryName1::EventType1->FactoryName2::EventType2
        std::string string = factory_to_string_[serialized.first] + "::" + serialized.second;
        if (event->getNext() != nullptr) {
            string += "->" + serialize(event->getNext());
        }
        return string;
    }

    events::EventChainLink *EventsSerializer::deserialize(const std::string &string) {
        std::string input = string;
        std::string events_delim = "->";
        std::string factory_delim = "::";
        size_t pos;
        events::EventChainLink *result_event = events::EventsController::getEmptyEvent();
        // Чтобы не писать дважды один и тот же код, сделал лябмду
        auto deserialize_single = [&]() -> void {
            std::string event_str = input.substr(0, pos);
            size_t delim_pos = event_str.find(factory_delim);
            // Обрабатываем строку в формате FactoryName1::EventType1->FactoryName2::EventType2
            if (delim_pos != std::string::npos && event_str.length() > delim_pos + 1) {
                auto factory = event_str.substr(0, delim_pos);
                auto type = event_str.substr(delim_pos + factory_delim.length(), event_str.length());
                if (string_to_factory_.count(factory)) {
                    auto event = events_controller_->produce(string_to_factory_[factory], type);
                    if (event) {
                        result_event->addToEnd(event);
                    }
                }
            }
            input.erase(0, pos + events_delim.length());

        };
        while ((pos = input.find(events_delim)) != std::string::npos) {
            deserialize_single();
        }
        deserialize_single();
        return result_event;
    }

    EventsSerializer::EventsSerializer(events::EventsController *events_controller) : events_controller_(
            events_controller) {
        for (const auto &it: factory_to_string_) {
            string_to_factory_[it.second] = it.first;
        }
    }

    EventsSerializer::~EventsSerializer() {
        string_to_factory_.clear();
        factory_to_string_.clear();
    }
}