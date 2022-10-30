//
// Created by ilyab on 21.10.2022.
//

#ifndef GAME_LOGLEVEL_H
#define GAME_LOGLEVEL_H

#include <string>
#include <map>

namespace logger {
    class LogLevel {
    public:
        enum class Level {
            EVENTS, GAME_STATE, ERRORS, DEFAULT
        };

        LogLevel(Level lvl);

        explicit operator std::string() const;

        bool operator==(const LogLevel &p) const;
    protected:
        Level lvl_;
    };
}

#endif //GAME_LOGLEVEL_H
