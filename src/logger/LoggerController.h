//
// Created by ilyab on 21.10.2022.
//

#ifndef GAME_LOGGERCONTROLLER_H
#define GAME_LOGGERCONTROLLER_H

namespace logger {
    class LoggerController;
}

#include <map>
#include <string>
#include <vector>
#include "../GameMediator.h"
#include "observers/proxy/EventProxy.h"
#include "observers/proxy/PlayerProxy.h"
#include "observers/proxy/FieldProxy.h"
#include "observers/proxy/GameStateProxy.h"
#include "observers/ErrorsObserver.h"
#include "loggers/ConsoleLogger.h"
#include "loggers/FileLogger.h"

namespace logger {
    /// Отвечает за логирование, реализовано по паттернам "Прокси" и "Наблюдатель"
    class LoggerController {
    public:
        explicit LoggerController(GameMediator *game_mediator);

        void startLogging();

        // Перегрузка методов получения прокси для всех возможных
        EventProxy *getProxy(events::EventChainLink *event);

        PlayerProxy *getProxy(kernel::ICreature *player);

        FieldProxy *getProxy(kernel::IField *field);

        GameStateProxy *getProxy(IGameState *game_state);

        /// Обработка ошибки
        void catchException(std::exception &error);

        /// Подписывает всех логеров на наблюдателя
        void subscribeObserver(AbstractObserver *observer);

        ~LoggerController();
    protected:
        GameMediator *game_mediator_;
        std::vector<ISubscriber *> loggers_;
        ErrorsObserver *errors_observer_;
        std::vector<LogLevel> log_lvl_;
    };
}


#endif //GAME_LOGGERCONTROLLER_H
