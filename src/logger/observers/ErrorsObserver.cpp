//
// Created by ilyab on 24.10.2022.
//

#include "ErrorsObserver.h"

namespace logger {
    void ErrorsObserver::catchException(const std::exception &error) {
        notify(error.what());
    }

    LogLevel ErrorsObserver::getLogLevel() {
        return LogLevel(LogLevel::Level::ERRORS);
    }
}