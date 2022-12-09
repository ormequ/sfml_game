//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_CELLSIMPRISONEVENT_H
#define GAME_CELLSIMPRISONEVENT_H

#include "CellsEvent.h"

namespace events {
    class CellsImprisonEvent : public CellsEvent {
    public:
//        explicit CellsImprisonEvent(kernel::Field *field);
        using CellsEvent::CellsEvent;

        void dispatch(Point point) override;

        std::pair<FactoryName, std::string> serialize() override;

        ~CellsImprisonEvent() override = default;
    };
}


#endif //GAME_CELLSIMPRISONEVENT_H
