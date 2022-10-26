//
// Created by ilyab on 24.10.2022.
//

#ifndef GAME_ERRORSOBSERVER_H
#define GAME_ERRORSOBSERVER_H

#include "../AbstractObserver.h"

namespace logger {
    class ErrorsObserver : public AbstractObserver {
    public:
        void catchException(const std::exception &error);

        ~ErrorsObserver() override = default;
    private:
        LogLevel getLogLevel() override;
    };
}


#endif //GAME_ERRORSOBSERVER_H
