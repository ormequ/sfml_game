//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_CELLSEVENT_H
#define GAME_CELLSEVENT_H

#include "../EventChainLink.h"
#include "../../kernel/field/Field.h"

namespace events {
    class CellsEvent : public EventChainLink {
    public:
        explicit CellsEvent(kernel::IField *field);
    protected:
        kernel::IField *field_;
    };
}


#endif //GAME_CELLSEVENT_H
