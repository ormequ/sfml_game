//
// Created by User on 08.12.2022.
//

#include "SaveCommand.h"

namespace view {

    SaveCommand::SaveCommand(GameMediator *game_mediator) : game_mediator_(game_mediator) {}

    void SaveCommand::execute() {
        try {
            game_mediator_->save();
            std::cout << "Game has been saved successfully\n";
        } catch (...) {
            std::cout << "Sorry, you cannot save the game right now\n";
        }
    }
}