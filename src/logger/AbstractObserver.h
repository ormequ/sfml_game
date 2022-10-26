//
// Created by ilyab on 21.10.2022.
//

#ifndef GAME_ABSTRACTOBSERVER_H
#define GAME_ABSTRACTOBSERVER_H

#include <vector>
#include "LoggerMessage.h"
#include "ISubscriber.h"

namespace logger {
    class AbstractObserver {
    public:
        void subscribe(ISubscriber *subscriber);

        void notify(const std::string &message);

        virtual ~AbstractObserver() = default;

    protected:
        virtual LogLevel getLogLevel() = 0;

        std::vector<ISubscriber *> subscribers_;
    };
}


#endif //GAME_ABSTRACTOBSERVER_H
