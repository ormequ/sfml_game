//
// Created by ilyab on 23.10.2022.
//

#ifndef GAME_FILELOGGER_H
#define GAME_FILELOGGER_H

namespace logger {
    class FileLogger;
}


#include "../ISubscriber.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

namespace logger {
    class FileLogger : public ISubscriber {
    public:
        explicit FileLogger(const std::string& filename, const std::vector<LogLevel> &log_lvl);

        void notify(const LoggerMessage& message) override;

        ~FileLogger() override;

    protected:
        std::ofstream file_;
        const std::vector<LogLevel> &log_lvl_;
    };
}
#endif //GAME_FILELOGGER_H
