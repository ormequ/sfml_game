//
// Created by ilyab on 17.09.2022.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

namespace kernel {
    class Player;
}

#include <cmath>
#include "ICreature.h"

namespace kernel {
    class Player : public ICreature {
    public:
        explicit Player(Point point, int damage = 25);

        void setDamage(int damage) override;

        CreatureParam getHp() override;

        void takeHit(int damage) override;

        void heal(int hp) override;

        void setDirection(Direction direction) override;

        Direction getDirection() override;

        Point getPoint() override;

        void setPoint(Point point) override;

        int attack() override;

        ~Player() override = default;
    protected:
        CreatureParam hp_{200, 200};
        int damage_;
        Direction direction_;
        Point point_;
    };
}


#endif //GAME_PLAYER_H
