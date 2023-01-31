//
// Created by ilyab on 16.09.2022.
//


#ifndef GAME_VIEWCONTROLLER_H
#define GAME_VIEWCONTROLLER_H

namespace view {
    class ViewController;
}

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "../GameMediator.h"
#include "../Point.h"
#include "src/view/handler/KeyboardHandler.h"
#include "src/view/handler/CommandCreator.h"
#include "draw/DrawManager.h"
#include "handler/reader/HandlerFileReader.h"

namespace view {
    class ViewController {
    public:
        explicit ViewController(GameMediator *game_mediator);

        void start();

        /**
         * Этот метод вызывает GameMediator, чтобы задать пользователю вопрос
         * */
        std::string ask(const std::string &question, const std::vector<std::string> &answers);

        ~ViewController();

    protected:
        sf::RenderWindow window_{
                sf::VideoMode(800, 600),
                "Ninja Adventure",
                sf::Style::Default
        };
        GameMediator *game_mediator_;
        KeyboardHandler *keyboard_handler_;
        CommandCreator *command_creator_;
        DrawManager *draw_manager_;
    };

}
#endif
