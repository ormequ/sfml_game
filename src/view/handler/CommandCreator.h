//
// Created by ilyab on 14.11.2022.
//

#ifndef GAME_COMMANDCREATOR_H
#define GAME_COMMANDCREATOR_H

namespace view {
    class CommandCreator;
}

#include "commands/MoveUpCommand.h"
#include "commands/MoveDownCommand.h"
#include "commands/MoveLeftCommand.h"
#include "commands/MoveRightCommand.h"
#include "commands/LoadCommand.h"
#include "commands/SaveCommand.h"
#include "reader/IHandlerReader.h"
#include "../../GameMediator.h"

namespace view {
    class CommandCreator {
    public:
        CommandCreator(GameMediator *game_mediator);

        void read(IHandlerReader *reader);

        ICommand *getCommand(const std::string &key);

        ~CommandCreator();

    protected:
        GameMediator *game_mediator_;
        std::map<std::string, ICommand *> keymap_;

        std::map<std::string, ICommand *> commands_from_string_;
    };
}


#endif //GAME_COMMANDCREATOR_H
