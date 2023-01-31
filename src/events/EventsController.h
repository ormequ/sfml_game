//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_EVENTSCONTROLLER_H
#define GAME_EVENTSCONTROLLER_H

namespace events {
    class EventsController;
}

#include <string>
#include <map>
#include "../GameMediator.h"
#include "cells/CellsEventFactory.h"
#include "player/PlayerEventFactory.h"
#include "game_state/GameStateEventFactory.h"
#include "map/MapEventFactory.h"
#include "EmptyEvent.h"
#include "FactoryNames.h"

namespace events {
    /// Отвечает за события и их фабрики. Реализовано, ориентируясь на паттерны "Цепочка обязанностей" и "Фабрика"
    class EventsController {
    public:

        explicit EventsController(GameMediator *game_mediator);

        IEventFactory *getFactory(FactoryName factory);

        /// Обертка над методом getFactory
        EventChainLink *produce(FactoryName factory_name, const std::string& type);

        ///@return пустое событие, необходимое для добавления проверки возможности вызова перед первым событием
        static EventChainLink *getEmptyEvent();

        ~EventsController();
    protected:
        GameMediator *game_mediator_;
        std::map<FactoryName, IEventFactory *> factories_;
    };
}


#endif //GAME_EVENTSCONTROLLER_H
