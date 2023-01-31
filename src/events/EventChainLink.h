//
// Created by ilyab on 12.10.2022.
//

#ifndef GAME_EVENTCHAINLINK_H
#define GAME_EVENTCHAINLINK_H

namespace events {
    class EventChainLink;
}

#include <functional>
#include "IEvent.h"

namespace events {
    /// "Звено" цепочки обязанностей
    class EventChainLink : public IEvent {
    public:
        /**
         * Добавление следующего звена в цепочку
         * @param next звено, которое будет следующим
         * @param delete_previous нужно ли удалять следующее звено (до изменений) перед вставкой при его наличии
         * */
        EventChainLink *addNext(EventChainLink *next, bool delete_previous = false);

        /// Добавление звена в конец цепочки
        EventChainLink *addToEnd(EventChainLink *event);

        /// Получение следующего звена
        EventChainLink *getNext();

        /// Получение первого звена
        EventChainLink *getFirst();

        /// Изменение предыдущего звена (для удаления события из середины)
        void setPrevious(EventChainLink *previous);

        /// Вызов следующего звена цепочки
        void dispatchNext(Point point);

        /// Установка проверки для вызова следующего звена
        EventChainLink *setTransmitChecker(std::function<bool()> transmit_checker);

        virtual ~EventChainLink();

    protected:
        EventChainLink *prev_chain_link_ = nullptr;
        EventChainLink *next_chain_link_ = nullptr;
        std::function<bool()> transmit_checker_ = []() { return true; };
    };
}


#endif //GAME_EVENTCHAINLINK_H
