//
// Created by ilyab on 14.11.2022.
//

#ifndef GAME_MOVEDOWNCOMMAND_H
#define GAME_MOVEDOWNCOMMAND_H

namespace view {
    class MoveDownCommand;
}

#include "ICommand.h"
#include "../../GameMediator.h"

namespace view {
    class MoveDownCommand : public ICommand {
    public:
        explicit MoveDownCommand(GameMediator *game_mediator);

        void execute() override;
    protected:
        GameMediator *game_mediator_;
    };
}


#endif //GAME_MOVEDOWNCOMMAND_H
