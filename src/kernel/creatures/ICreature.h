//
// Created by ilyab on 21.10.2022.
//

#ifndef GAME_ICREATURE_H
#define GAME_ICREATURE_H

namespace kernel {
    class ICreature;
}

#include "IObject.h"
#include "CreatureParam.h"

namespace kernel {
    class ICreature : public IObject {
    public:
        enum class Direction {
            UP, LEFT, DOWN, RIGHT
        };

        virtual CreatureParam getHp() = 0;

        virtual void takeHit(int damage) = 0;

        virtual void heal(int hp) = 0;

        virtual void setDirection(Direction direction) = 0;

        virtual int attack() = 0;

        virtual void setDamage(int damage) = 0;

        virtual Direction getDirection() = 0;
    };
}

#endif //GAME_ICREATURE_H
