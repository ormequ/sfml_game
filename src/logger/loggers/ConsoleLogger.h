//
// Created by ilyab on 21.10.2022.
//

#ifndef GAME_CONSOLELOGGER_H
#define GAME_CONSOLELOGGER_H

#include "../ISubscriber.h"
#include <iostream>
#include <algorithm>
#include <vector>

namespace logger {
    /// Записывает в консоль логи по переданным уровням
    class ConsoleLogger : public ISubscriber {
    public:
        explicit ConsoleLogger(const std::vector<LogLevel> &log_lvl_);

        void notify(const LoggerMessage &message) override;
    private:
        const std::vector<LogLevel> &log_lvl_;
    };
}


#endif //GAME_CONSOLELOGGER_H
