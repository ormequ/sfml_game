//
// Created by ilyab on 21.10.2022.
//

#ifndef GAME_ILOGGER_H
#define GAME_ILOGGER_H

namespace logger {
    class ILogger {
    public:
        virtual void log() = 0;
    };
}

#endif //GAME_ILOGGER_H
