//
// Created by ilyab on 21.10.2022.
//
#include "LogLevel.h"

namespace logger {
    LogLevel::LogLevel(Level lvl) : lvl_(lvl) {}
    
    LogLevel::operator std::string() const {
        std::map<Level, std::string> m = {
            {Level::EVENTS, "EVENT"},
            {Level::ERRORS, "ERROR"},
            {Level::GAME_STATE, "GAME_STATE"},
            {Level::DEFAULT, "DEFAULT"},
        };
        if (m.count(lvl_)) {
            return m.at(lvl_);
        }
        return "UNKNOWN";
    }

    bool LogLevel::operator==(const LogLevel &p) const {
        return lvl_ == p.lvl_;
    }
}