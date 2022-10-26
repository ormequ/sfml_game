//
// Created by ilyab on 11.10.2022.
//

#include "HudDrawer.h"

namespace view {

    HudDrawer::HudDrawer(sf::RenderWindow& window, TextureManager& texture_manager, GameMediator *game_mediator) :
            texture_manager_(texture_manager), game_mediator_(game_mediator), window_(window) {}


    void HudDrawer::draw(const sf::View& view) {
        kernel::CreatureParam hp = game_mediator_->getPlayer()->getHp();
        for (int i = 0; i < hp.max; i += 40) {
            int heart_hp = (int)ceil(fmax(hp.value - i, 0) / 10);
            int rectLeft = 0;
            while (heart_hp < 4) {
                rectLeft += 16;
                heart_hp++;
            }
            sf::Sprite heart_sprite = texture_manager_.getSprite(
                    "../src/resources/images/HUD/Heart.png", sf::IntRect(rectLeft, 0, 16, 16)
            );
            auto left = (unsigned int)(view.getCenter().x + view.getSize().x / 2);
            unsigned int x = left - (5 + (hp.max - i) / 40 * 18);
            float y = view.getCenter().y - view.getSize().y / 2 + 5;
            heart_sprite.setPosition((float) x, y);
            window_.draw(heart_sprite);
        }
    }
}