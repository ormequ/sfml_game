//
// Created by ilyab on 21.10.2022.
//

#ifndef GAME_LOGGERMESSAGE_H
#define GAME_LOGGERMESSAGE_H

#include <string>
#include <iostream>
#include <utility>
#include <ctime>

#include "LogLevel.h"

namespace logger {
    class LoggerMessage {
    public:
        explicit LoggerMessage(std::string message, LogLevel level);

        friend std::ostream& operator<<(std::ostream& stream, const LoggerMessage& message);

        explicit operator std::string() const;

        LogLevel getLevel() const;

        ~LoggerMessage();
    protected:
        std::string getPrefix();

        std::string message_;
        LogLevel lvl_;
    };
}


#endif //GAME_LOGGERMESSAGE_H
