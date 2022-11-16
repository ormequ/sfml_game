//
// Created by ilyab on 14.11.2022.
//

#ifndef GAME_MOVELEFTCOMMAND_H
#define GAME_MOVELEFTCOMMAND_H

namespace view {
    class MoveLeftCommand;
}

#include "ICommand.h"
#include "../../GameMediator.h"

namespace view {
    class MoveLeftCommand : public ICommand {
    public:
        explicit MoveLeftCommand(GameMediator *game_mediator);

        void execute() override;
    protected:
        GameMediator *game_mediator_;
    };
}


#endif //GAME_MOVELEFTCOMMAND_H
