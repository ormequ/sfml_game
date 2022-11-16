//
// Created by ilyab on 14.11.2022.
//

#include "MoveDownCommand.h"

namespace view {
    MoveDownCommand::MoveDownCommand(GameMediator *game_mediator): game_mediator_(game_mediator) {}

    void MoveDownCommand::execute() {
        kernel::ICreature *player = game_mediator_->getPlayer();
        Point point = player->getPoint();
        point.y++;
        game_mediator_->rotateCreature(player, kernel::ICreature::Direction::DOWN);
        game_mediator_->moveCreature(player, point);
    }
}