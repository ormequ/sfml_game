//
// Created by ilyab on 19.09.2022.
//

#include "KeyboardHandler.h"
#include <iostream>

namespace view {

    void KeyboardHandler::handle(sf::Keyboard::Key key) {
        std::map<sf::Keyboard::Key, std::string> keys {
                {sf::Keyboard::A, "a"},
                {sf::Keyboard::B, "b"},
                {sf::Keyboard::C, "c"},
                {sf::Keyboard::D, "d"},
                {sf::Keyboard::E, "e"},
                {sf::Keyboard::F, "f"},
                {sf::Keyboard::G, "g"},
                {sf::Keyboard::H, "h"},
                {sf::Keyboard::I, "i"},
                {sf::Keyboard::J, "j"},
                {sf::Keyboard::K, "k"},
                {sf::Keyboard::L, "l"},
                {sf::Keyboard::M, "m"},
                {sf::Keyboard::N, "n"},
                {sf::Keyboard::O, "o"},
                {sf::Keyboard::P, "p"},
                {sf::Keyboard::Q, "q"},
                {sf::Keyboard::R, "r"},
                {sf::Keyboard::S, "s"},
                {sf::Keyboard::T, "t"},
                {sf::Keyboard::U, "u"},
                {sf::Keyboard::V, "v"},
                {sf::Keyboard::W, "w"},
                {sf::Keyboard::X, "x"},
                {sf::Keyboard::Y, "y"},
                {sf::Keyboard::Z, "z"},
                {sf::Keyboard::Up, "up"},
                {sf::Keyboard::Down, "down"},
                {sf::Keyboard::Left, "left"},
                {sf::Keyboard::Right, "right"},
                {sf::Keyboard::Escape, "escape"},
                {sf::Keyboard::Space, "space"},
                {sf::Keyboard::Enter, "enter"},
        };
        if (keys.count(key) != 0) {
            ICommand *command = command_creator_->getCommand(keys[key]);
            if (command) {
                command->execute();
            }
        }
    }

    KeyboardHandler::KeyboardHandler(CommandCreator* command_creator) : command_creator_(command_creator) {}
}