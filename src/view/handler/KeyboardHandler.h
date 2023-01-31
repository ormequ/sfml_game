//
// Created by ilyab on 19.09.2022.
//

#ifndef GAME_KEYBOARDHANDLER_H
#define GAME_KEYBOARDHANDLER_H

namespace view {
    class KeyboardHandler;
}
#include <SFML/Graphics.hpp>

#include "CommandCreator.h"

namespace view {
    /// Обработчик нажатий клавиатуры
    class KeyboardHandler {
    public:
        explicit KeyboardHandler(CommandCreator* command_creator);

        void handle(sf::Keyboard::Key key);
    protected:
        CommandCreator* command_creator_;
    };
}


#endif //GAME_KEYBOARDHANDLER_H
