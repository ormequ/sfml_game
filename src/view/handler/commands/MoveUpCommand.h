//
// Created by ilyab on 14.11.2022.
//

#ifndef GAME_MOVEUPCOMMAND_H
#define GAME_MOVEUPCOMMAND_H

namespace view {
    class MoveUpCommand;
}

#include "ICommand.h"
#include "../../GameMediator.h"

namespace view {
    class MoveUpCommand : public ICommand {
    public:
        explicit MoveUpCommand(GameMediator *game_mediator);

        void execute() override;
    protected:
        GameMediator *game_mediator_;
    };
}


#endif //GAME_MOVEUPCOMMAND_H
