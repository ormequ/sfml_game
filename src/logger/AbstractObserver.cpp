//
// Created by ilyab on 21.10.2022.
//

#include "AbstractObserver.h"

namespace logger {
    void AbstractObserver::subscribe(ISubscriber *subscriber) {
        subscribers_.push_back(subscriber);
    }

    void AbstractObserver::notify(const std::string& message) {
        for (auto subscriber : subscribers_) {
            subscriber->notify(LoggerMessage{message, getLogLevel()});
        }
    }
}