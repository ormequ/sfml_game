//
// Created by ilyab on 21.10.2022.
//

#include "LoggerController.h"

namespace logger {
    LoggerController::LoggerController(GameMediator *game_mediator) : game_mediator_(game_mediator) {
        errors_observer_ = new ErrorsObserver;
    }

    EventProxy *LoggerController::getProxy(events::EventChainLink *event) {
        auto proxy = new EventProxy(event);
        subscribeObserver(proxy);
        return proxy;
    }

    PlayerProxy *LoggerController::getProxy(kernel::ICreature *player) {
        auto proxy = new PlayerProxy(player);
        subscribeObserver(proxy);
        return proxy;
    }

    FieldProxy *LoggerController::getProxy(kernel::IField *field) {
        auto proxy = new FieldProxy(field);
        subscribeObserver(proxy);
        return proxy;
    }

    GameStateProxy *LoggerController::getProxy(IGameState *game_state) {
        auto proxy = new GameStateProxy(game_state);
        subscribeObserver(proxy);
        return proxy;
    }

    void LoggerController::catchException(std::exception &error) {
        errors_observer_->catchException(error);
    }

    void LoggerController::startLogging() {
        auto lvl = game_mediator_->askUser(
                "What do you want to log?", {"events", "errors", "state", "nothing"}
        );
        if (lvl.find("nothing") != std::string::npos) {
            return;
        }
        if (lvl.find("events") != std::string::npos) {
            log_lvl_.push_back(LogLevel(LogLevel::Level::EVENTS));
        }
        if (lvl.find("errors") != std::string::npos) {
            log_lvl_.push_back(LogLevel(LogLevel::Level::ERRORS));
        }
        if (lvl.find("state") != std::string::npos) {
            log_lvl_.push_back(LogLevel(LogLevel::Level::GAME_STATE));
        }
        if (log_lvl_.empty()) {
            return;
        }

        auto where = game_mediator_->askUser("Where do you want to log?", {"console", "file"});
        if (where.find("console") != std::string::npos) {
            loggers_.push_back(new ConsoleLogger{log_lvl_});
        }
        if (where.find("file") != std::string::npos) {
            size_t start = where.find("file=\"");
            std::string log_file = "../log.txt";
            if (start != std::string::npos) {
                size_t end = where.find('"', start + 6);
                if (end != std::string::npos) {
                    log_file = where.substr(start + 6, end - start - 6);
                    std::cout << log_file << '\n';
                }
            }
            loggers_.push_back(new FileLogger{log_file, log_lvl_});
        }

        subscribeObserver(errors_observer_);
    }

    void LoggerController::subscribeObserver(AbstractObserver *observer) {
        for (auto logger : loggers_) {
            observer->subscribe(logger);
        }
    }

    LoggerController::~LoggerController() {
        for (auto it : loggers_) {
            delete it;
        }
        loggers_.clear();
        log_lvl_.clear();
        delete errors_observer_;
    }

}