//
// Created by User on 08.12.2022.
//

#include "LoadCommand.h"

namespace view {

    LoadCommand::LoadCommand(GameMediator *game_mediator) : game_mediator_(game_mediator) {}

    void LoadCommand::execute() {
        std::cout << "What save do you want to load?\n";
        std::string filename;
        std::cin >> filename;
        try {
            game_mediator_->load(filename);
            std::cout << "Done!\n";
        } catch (std::exception &exception) {
            std::cout << "Cannot load the save. Error: " << exception.what() << "\n";
        }
    }
}