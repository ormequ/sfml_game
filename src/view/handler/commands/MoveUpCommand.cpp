//
// Created by ilyab on 14.11.2022.
//

#include "MoveUpCommand.h"

namespace view {
    MoveUpCommand::MoveUpCommand(GameMediator *game_mediator): game_mediator_(game_mediator) {}

    void MoveUpCommand::execute() {
        kernel::ICreature *player = game_mediator_->getPlayer();
        Point point = player->getPoint();
        point.y--;
        game_mediator_->rotateCreature(player, kernel::ICreature::Direction::UP);
        game_mediator_->moveCreature(player, point);
    }
}