//
// Created by ilyab on 16.09.2022.
//

#include "ViewController.h"

namespace view {
    ViewController::ViewController(GameMediator *game_mediator) {
        game_mediator_ = game_mediator;
        command_creator_ = new CommandCreator(game_mediator);
        command_creator_->read(new HandlerFileReader);
        keyboard_handler_ = new KeyboardHandler(command_creator_);
        draw_manager_ = new DrawManager(game_mediator_, window_);
    }

    void ViewController::start() {
        window_.setVerticalSyncEnabled(true);
        while (window_.isOpen()) {
            game_mediator_->update();
            if (game_mediator_->getState() == GameStateController::State::WIN) {
                std::cout << "Wow! You win!\n";
                window_.close();
            } else if (game_mediator_->getState() == GameStateController::State::LOSE) {
                std::cout << "Oops.. You lose...\n";
                window_.close();
            }

            sf::Event event{};
            while (window_.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    std::cout << "Bye!\n";
                    window_.close();
                }
                if (event.type == sf::Event::KeyPressed) {
                    keyboard_handler_->handle(event.key.code);
                }
            }

            window_.clear();
            draw_manager_->draw();
            window_.display();
        }
    }

    ViewController::~ViewController() {
        delete command_creator_;
        delete keyboard_handler_;
        delete draw_manager_;
    }

    std::string ViewController::ask(const std::string &question, const std::vector<std::string> &answers) {
        return "console errors";
        std::string printable_ans;
        for (const auto& answer : answers) {
            printable_ans += "|" + answer;
        }
        printable_ans[0] = ' ';
        std::cout << question << " Variants:"<< printable_ans << "\n";
        std::string res;
        std::getline(std::cin, res);
        return res;
    }
}