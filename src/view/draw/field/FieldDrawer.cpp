//
// Created by ilyab on 05.10.2022.
//

#include "FieldDrawer.h"
#include <iostream>

namespace view {

    FieldDrawer::FieldDrawer(sf::RenderWindow& window, TextureManager& texture_manager, GameMediator* game_mediator) :
            texture_manager_(texture_manager), game_mediator_(game_mediator), window_(window) {
        cell_sprite_getter_ = new CellSpriteGetter(texture_manager_);
    }

    void FieldDrawer::draw(const sf::View& view) {
        const kernel::IField* field = game_mediator_->readField();

        for (int i = 0; i < field->getWidth(); i++) {
            for (int j = 0; j < field->getHeight(); j++) {
                auto cell = field->readCell({i, j});
//                kernel::CreatureWrapper creature_wrapper = game_mediator_->getCreature({i, j});
                drawCell(cell);
//                if (creature_wrapper.creature != nullptr) {
//                    drawCreature({i, j}, creature_wrapper);
//                }
            }
        }
        for (auto creature : game_mediator_->getCreatures()) {
            drawCreature(creature);
        }
    }

    void FieldDrawer::setCellSize(float cell_size) {
        cell_size_ = cell_size;
    }

    void FieldDrawer::drawCell(const kernel::Cell* cell) {
        Point point = cell->getPoint();
        sf::Sprite cell_sprite = cell_sprite_getter_->getCellSprite(cell);
        moveToCellCenter(cell_sprite, point, 1);
        cell_sprite.setPosition((float) point.x * cell_size_, (float) point.y * cell_size_);
        window_.draw(cell_sprite);

        InnerSpriteWrapper wrapper = cell_sprite_getter_->getInnerSprite(cell);
        moveToCellCenter(wrapper.sprite, point, wrapper.cell_percentage);
        window_.draw(wrapper.sprite);
    }

    void FieldDrawer::moveToCellCenter(sf::Sprite& sprite, Point point, float cell_percent) {
        auto size = fmax(sprite.getGlobalBounds().height, sprite.getGlobalBounds().width);
        auto scale = cell_percent * cell_size_ / size;
        sprite.setScale(sf::Vector2f((float) scale, (float) scale));
        float x = cell_size_ * (float) point.x + (cell_size_ - sprite.getGlobalBounds().width) / 2;
        float y = cell_size_ * (float) point.y + (cell_size_ - sprite.getGlobalBounds().height) / 2;
        sprite.setPosition(x, y);
    }


    void FieldDrawer::drawCreature(kernel::ICreature *creature) {
        std::string path;
        if (dynamic_cast<kernel::Player*>(creature) != nullptr) {
            path = "../src/resources/images/characters/BlueNinja.png";
        }
        int rectLeft;

        switch (creature->getDirection()) {
            case kernel::ICreature::Direction::UP:
                rectLeft = 16;
                break;
            case kernel::ICreature::Direction::LEFT:
                rectLeft = 32;
                break;
            case kernel::ICreature::Direction::DOWN:
                rectLeft = 0;
                break;
            case kernel::ICreature::Direction::RIGHT:
                rectLeft = 48;
                break;
        }

        sf::Sprite creature_sprite = texture_manager_.getSprite(
                path, sf::IntRect(rectLeft, 0, 16, 16)
        );
        moveToCellCenter(creature_sprite, creature->getPoint(), 0.8);
        window_.draw(creature_sprite);

    }

    FieldDrawer::~FieldDrawer() {

    }
}