//
// Created by ilyab on 14.11.2022.
//

#include "MoveLeftCommand.h"

namespace view {
    MoveLeftCommand::MoveLeftCommand(GameMediator *game_mediator): game_mediator_(game_mediator) {}

    void MoveLeftCommand::execute() {
        kernel::ICreature *player = game_mediator_->getPlayer();
        Point point = player->getPoint();
        point.x--;
        game_mediator_->rotateCreature(player, kernel::ICreature::Direction::LEFT);
        game_mediator_->moveCreature(player, point);
    }
}