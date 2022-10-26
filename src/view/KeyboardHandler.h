//
// Created by ilyab on 19.09.2022.
//

#ifndef GAME_KEYBOARDHANDLER_H
#define GAME_KEYBOARDHANDLER_H

namespace view {
    class KeyboardHandler;
}
#include <SFML/Graphics.hpp>

#include "../../GameMediator.h"

namespace view {
    class KeyboardHandler {
    public:
        explicit KeyboardHandler(GameMediator* game_mediator);

        void handle(sf::Keyboard::Key key);
    protected:
        GameMediator* game_mediator_;
    };
}


#endif //GAME_KEYBOARDHANDLER_H
