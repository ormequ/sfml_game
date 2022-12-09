//
// Created by ilyab on 14.11.2022.
//

#include "CommandCreator.h"

namespace view {
    CommandCreator::CommandCreator(GameMediator *game_mediator) : game_mediator_(game_mediator) {
        commands_from_string_ = {
                {"MoveUp",    new MoveUpCommand(game_mediator_)},
                {"MoveDown",  new MoveDownCommand(game_mediator_)},
                {"MoveLeft",  new MoveLeftCommand(game_mediator_)},
                {"MoveRight", new MoveRightCommand(game_mediator_)},
                {"Load",      new LoadCommand(game_mediator_)},
                {"Save",      new SaveCommand(game_mediator_)},
        };
    }

    ICommand *CommandCreator::getCommand(const std::string &key) {
        if (keymap_.count(key) == 0) {
            return nullptr;
        }
        return keymap_[key];
    }

    void CommandCreator::read(IHandlerReader *reader) {
        std::map<std::string, std::string> str_commands = reader->read();
        for (const auto &pair: str_commands) {
            keymap_[pair.first] = commands_from_string_[pair.second];
        }
    }

    CommandCreator::~CommandCreator() {
        for (const auto &it: commands_from_string_) {
            delete it.second;
        }
    }
}