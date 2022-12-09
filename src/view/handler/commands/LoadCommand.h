//
// Created by User on 08.12.2022.
//

#ifndef GAME_LOADCOMMAND_H
#define GAME_LOADCOMMAND_H


namespace view {
    class LoadCommand;
}

#include "ICommand.h"
#include "../../GameMediator.h"

namespace view {
    class LoadCommand : public ICommand {
    public:
        explicit LoadCommand(GameMediator *game_mediator);

        void execute() override;
    protected:
        GameMediator *game_mediator_;
    };
}


#endif //GAME_LOADCOMMAND_H
