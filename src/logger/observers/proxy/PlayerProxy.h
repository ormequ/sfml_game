//
// Created by ilyab on 21.10.2022.
//

#ifndef GAME_PLAYERPROXY_H
#define GAME_PLAYERPROXY_H

#include "../../../kernel/creatures/Player.h"
#include "../../AbstractObserver.h"
#include <exception>

namespace logger {
    class PlayerProxy : public kernel::ICreature, public AbstractObserver {
    public:
        explicit PlayerProxy(kernel::ICreature *player);

        void setPoint(Point point) override;

        void setDamage(int damage) override;

        void takeHit(int damage) override;

        void heal(int hp) override;

        void setDirection(kernel::ICreature::Direction direction) override;

        kernel::CreatureParam getHp() override;

        kernel::ICreature::Direction getDirection() override;

        int attack() override;

        Point getPoint() override;

        ~PlayerProxy() override;

    protected:
        LogLevel getLogLevel() override;

        kernel::ICreature *player_;
    };
}


#endif //GAME_PLAYERPROXY_H
