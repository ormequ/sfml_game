//
// Created by ilyab on 14.11.2022.
//

#include "MoveRightCommand.h"

namespace view {
    MoveRightCommand::MoveRightCommand(GameMediator *game_mediator): game_mediator_(game_mediator) {}

    void MoveRightCommand::execute() {
        kernel::ICreature *player = game_mediator_->getPlayer();
        Point point = player->getPoint();
        point.x++;
        game_mediator_->rotateCreature(player, kernel::ICreature::Direction::RIGHT);
        game_mediator_->moveCreature(player, point);
    }
}