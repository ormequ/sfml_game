//
// Created by ilyab on 21.10.2022.
//

#include "ConsoleLogger.h"

namespace logger {

    void ConsoleLogger::notify(const LoggerMessage& message) {
        if (std::find(log_lvl_.begin(), log_lvl_.end(), message.getLevel()) != log_lvl_.end()) {
            std::cout << message;
        }
    }

    ConsoleLogger::ConsoleLogger(const std::vector<LogLevel> &log_lvl) : log_lvl_(log_lvl) {}
}