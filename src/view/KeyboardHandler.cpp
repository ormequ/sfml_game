//
// Created by ilyab on 19.09.2022.
//

#include "KeyboardHandler.h"
#include <iostream>

namespace view {

    void KeyboardHandler::handle(sf::Keyboard::Key key) {
        std::map<sf::Keyboard::Key, kernel::ICreature::Direction> dir {
                {sf::Keyboard::W, kernel::ICreature::Direction::UP},
                {sf::Keyboard::A, kernel::ICreature::Direction::LEFT},
                {sf::Keyboard::S, kernel::ICreature::Direction::DOWN},
                {sf::Keyboard::D, kernel::ICreature::Direction::RIGHT},
        };
        if (dir.count(key) != 0) {
            game_mediator_->movePlayer(dir[key]);
        }
    }

    KeyboardHandler::KeyboardHandler(GameMediator* game_mediator) : game_mediator_(game_mediator) {}
}