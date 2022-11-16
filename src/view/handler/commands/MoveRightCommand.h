//
// Created by ilyab on 14.11.2022.
//

#ifndef GAME_MOVERIGHTCOMMAND_H
#define GAME_MOVERIGHTCOMMAND_H

namespace view {
    class MoveRightCommand;
}

#include "ICommand.h"
#include "../../GameMediator.h"

namespace view {
    class MoveRightCommand : public ICommand {
    public:
        explicit MoveRightCommand(GameMediator *game_mediator);

        void execute() override;
    protected:
        GameMediator *game_mediator_;
    };
}

#endif //GAME_MOVERIGHTCOMMAND_H
