//
// Created by ilyab on 23.10.2022.
//

#include "FileLogger.h"

namespace logger {
    FileLogger::FileLogger(const std::string& filename, const std::vector<LogLevel> &log_lvl) : log_lvl_(log_lvl) {
        file_.open(filename);
        file_ << LoggerMessage("Logging has been started");
    }

    void FileLogger::notify(const LoggerMessage& message) {
        if (std::find(log_lvl_.begin(), log_lvl_.end(), message.getLevel()) != log_lvl_.end()) {
            file_ << message;
        }
    }

    FileLogger::~FileLogger() {
        file_.close();
    }
}