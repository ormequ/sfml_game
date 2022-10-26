//
// Created by ilyab on 21.10.2022.
//

#include "LoggerMessage.h"

namespace logger {
    LoggerMessage::LoggerMessage(std::string message, LogLevel level) : message_(std::move(message)), lvl_(level) {
        message_ = getPrefix() + message_;
        if (message_[message_.length() - 1] != '\n') {
            message_.push_back('\n');
        }
    }

    std::ostream &operator<<(std::ostream &stream, const LoggerMessage &message) {
        stream << (std::string) message;
        return stream;
    }

    LoggerMessage::operator std::string() const {
        return message_;
    }

    LogLevel LoggerMessage::getLevel() const {
        return lvl_;
    }

    LoggerMessage::~LoggerMessage() {
        message_.clear();
    }

    std::string LoggerMessage::getPrefix() {
        time_t t;
        tm *tm;
        time(&t);
        tm = localtime(&t);
        char time_prefix[100];
        strftime(time_prefix, sizeof(time_prefix), "[%d.%m.%Y %H:%M:%S] ", tm);
        std::string str(time_prefix);

        switch (lvl_) {
            case LogLevel::EVENTS:
                str += "[EVENT] ";
                break;
            case LogLevel::ERRORS:
                str += "[ERROR] ";
                break;
            case LogLevel::GAME_STATE:
                str += "[GAME_STATE] ";
                break;
            case LogLevel::DEFAULT:
                str += "[DEFAULT] ";
                break;
            default:
                str += "[UNKNOWN] ";

        }
        return str;
    }
}