//
// Created by ilyab on 21.10.2022.
//

#include "EventProxy.h"

namespace logger {
    void EventProxy::dispatch(Point position) {
        call_point_ = position;
        notify("Something has happened at the point " + (std::string)call_point_);
        event_->dispatch(position);
    }

    EventProxy::EventProxy(events::IEvent *event) : event_(event) {
        if (event_ == nullptr) {
            throw std::invalid_argument("Logger Exception: Incorrect event for the event proxy");
        }
    }

    EventProxy::~EventProxy() {
        delete event_;
    }

    LogLevel EventProxy::getLogLevel() {
        return LogLevel(LogLevel::Level::EVENTS);
    }
}