//
// Created by User on 08.12.2022.
//

#ifndef GAME_SAVECOMMAND_H
#define GAME_SAVECOMMAND_H

namespace view {
    class SaveCommand;
}

#include "ICommand.h"
#include "../../GameMediator.h"

namespace view {
    class SaveCommand : public ICommand {
    public:
        explicit SaveCommand(GameMediator *game_mediator);

        void execute() override;
    protected:
        GameMediator *game_mediator_;
    };
}


#endif //GAME_SAVECOMMAND_H
