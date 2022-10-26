//
// Created by ilyab on 21.10.2022.
//

#ifndef GAME_IOBJECT_H
#define GAME_IOBJECT_H


#include "../../Point.h"

namespace kernel {
    class IObject {
    public:
        virtual void setPoint(Point point) = 0;

        virtual Point getPoint() = 0;

        virtual ~IObject() = default;
    };
}

#endif //GAME_IOBJECT_H
