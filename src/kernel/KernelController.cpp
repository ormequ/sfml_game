//
// Created by ilyab on 11.10.2022.
//

#include "KernelController.h"

namespace kernel {
    void KernelController::update() {
        if (player_->getHp().value == 0) {
            game_mediator_->setState(GameStateController::State::LOSE);
        }
    }

    KernelController::KernelController(GameMediator *game_mediator) :
            game_mediator_(game_mediator) {
        creature_manager_ = new CreatureManager();
        field_ = new Field();
        player_ = new Player({0, 0});
        creature_manager_->addCreature(player_);
    }

    ICreature *KernelController::getPlayer() {
        return player_;
    }

    IField *KernelController::getField() {
        return field_;
    }


    CreatureManager *KernelController::getCreatureManager() {
        return creature_manager_;
    }

    void KernelController::moveCreature(ICreature *creature, Point point, bool dispatch) {
        Point pos_before = creature->getPoint();
        point = field_->getMoving(creature->getPoint(), point);
        creature->setPoint(point);
        if (dispatch) {
            if (pos_before == creature->getPoint()) {
                throw std::runtime_error("Kernel Exception: The creature has tried to move into the impassable cell");
            }
            field_->getCell(creature->getPoint())->dispatchListener();
        }
    }

    void KernelController::rotateCreature(ICreature *creature, ICreature::Direction direction) {
        creature->setDirection(direction);
    }

    void KernelController::setField(IField *field) {
        delete field_;
        field_ = field;
    }

    void KernelController::setPlayer(ICreature *new_player, bool delete_prev) {
        if (delete_prev) {
            delete player_;
        }
        player_ = new_player;
    }


}