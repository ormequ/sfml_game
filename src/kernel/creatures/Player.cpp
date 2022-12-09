//
// Created by ilyab on 17.09.2022.
//

#include "Player.h"

namespace kernel {
    int Player::attack() {
//        if (stamina_.value < beat_price_) {
//            stamina_.value = 0;
//            return damage_ * stamina_.value / beat_price_;
//        }
//        stamina_.value -= beat_price_;
        return damage_;
    }

    Player::Player(Point point, int damage) : point_(point), damage_(damage){
        direction_ = Direction::DOWN;
//        beat_price_ = 10;
    }

    void Player::takeHit(int hit) {
        hp_.value = (int)fmax(hp_.value - hit, 0);
    }

    void Player::heal(int hp) {
        hp_.value = (int)fmin(hp_.max, hp_.value + hp);
    }

    void Player::setDamage(int damage) {
        damage_ = damage;
    }

    void Player::setDirection(Player::Direction direction) {
        direction_ = direction;
    }

    Player::Direction Player::getDirection() {
        return direction_;
    }

    Point Player::getPoint() {
        return point_;
    }

    void Player::setPoint(Point point) {
        point_ = point;
    }

    CreatureParam Player::getHp() {
        return hp_;
    }

    void Player::setHpParams(CreatureParam hp) {
        hp_.max = hp.max;
        hp_.value = hp.value;
    }
}