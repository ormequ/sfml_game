//
// Created by ilyab on 21.10.2022.
//

#include "PlayerProxy.h"

namespace logger {
    PlayerProxy::PlayerProxy(kernel::ICreature *player) : player_(player) {
        if (player_ == nullptr) {
            throw std::invalid_argument("Logger Exception: Incorrect player for the player proxy");
        }
    }


    void PlayerProxy::setPoint(Point point) {
        if (point != player_->getPoint()) {
            notify("The player has moved to " + (std::string)point);
        }
        player_->setPoint(point);
    }

    void PlayerProxy::setDamage(int damage) {
        notify("The player damage has changed to " + std::to_string(damage));
        player_->setDamage(damage);
    }

    kernel::CreatureParam PlayerProxy::getHp() {
        return player_->getHp();
    }

    void PlayerProxy::takeHit(int damage) {
        notify( "The player has been hit with damage " + std::to_string(damage));
        player_->takeHit(damage);
    }

    void PlayerProxy::heal(int hp) {
        notify("The player hp has been increased by " + std::to_string(hp));
        player_->heal(hp);
    }

    void PlayerProxy::setDirection(kernel::ICreature::Direction direction) {
        player_->setDirection(direction);
    }

    kernel::ICreature::Direction PlayerProxy::getDirection() {
        return player_->getDirection();
    }

    int PlayerProxy::attack() {
        notify("The player has attacked someone");
        return player_->attack();
    }

    Point PlayerProxy::getPoint() {
        return player_->getPoint();
    }

    PlayerProxy::~PlayerProxy() {
        delete player_;
    }

    LogLevel PlayerProxy::getLogLevel() {
        return LogLevel::EVENTS;
    }
}