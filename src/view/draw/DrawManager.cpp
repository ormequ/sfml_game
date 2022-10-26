//
// Created by ilyab on 19.09.2022.
//

#include "DrawManager.h"
#include <iostream>

namespace view {
    DrawManager::DrawManager(GameMediator* game_mediator, sf::RenderWindow& window) :
            game_mediator_(game_mediator), window_(window) {
        drawers_.push_back(new FieldDrawer(window_, texture_manager_, game_mediator_));
        drawers_.push_back(new HudDrawer(window_, texture_manager_, game_mediator_));
    }

    void DrawManager::draw() {
        sf::View view;
        view.setSize((float) window_.getSize().x / 2, (float) window_.getSize().y / 2);

        Point player_position = game_mediator_->getPlayer()->getPoint();

        float center_x = view.getSize().x / 2;
        float center_y = view.getSize().y / 2;
        while (((float)player_position.x + 1) * CELL_SIZE_ - center_x > view.getSize().x / 2) {
            center_x += view.getSize().x - CELL_SIZE_ / 2;
        }
        while (((float)player_position.y + 1) * CELL_SIZE_ - center_y > view.getSize().y / 2) {
            center_y += view.getSize().y - CELL_SIZE_ / 2;
        }
        view.setCenter(center_x, center_y);
        window_.setView(view);

        for (auto drawer : drawers_) {
            drawer->draw(view);
        }
    }
}