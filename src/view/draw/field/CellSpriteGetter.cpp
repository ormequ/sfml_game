//
// Created by ilyab on 11.10.2022.
//

#include "CellSpriteGetter.h"

namespace view {

    CellSpriteGetter::CellSpriteGetter(TextureManager& texture_manager) : texture_manager_(texture_manager) {}

    sf::Sprite CellSpriteGetter::getCellSprite(const kernel::Cell *cell) {
        typedef kernel::Cell::Tileset Tileset;
        switch (cell->getTileset()) {
            case Tileset::HOLE:
                return texture_manager_.getSprite(
                        "resources/images/backgrounds/TilesetHole.png",
                        sf::IntRect(0, 0, 48, 48)
                );
            case Tileset::WATER_GLARE:
                return texture_manager_.getSprite(
                        "resources/images/backgrounds/TilesetWater.png",
                        sf::IntRect(176, 32, 16, 16)
                );
            case Tileset::WATER_LILY:
                return texture_manager_.getSprite(
                        "resources/images/backgrounds/TilesetWater.png",
                        sf::IntRect(176, 50, 16, 16)
                );
            case Tileset::WATER_FISH:
                return texture_manager_.getSprite(
                        "resources/images/backgrounds/TilesetWater.png",
                        sf::IntRect(176, 64, 16, 16)
                );
            case Tileset::TUNNEL:
                return texture_manager_.getSprite(
                        "resources/images/backgrounds/TilesetReliefDetail.png",
                        sf::IntRect(16, 0, 16, 16)
                );
            default:
                return texture_manager_.getSprite(
                        "resources/images/backgrounds/TilesetField.png",
                        sf::IntRect(49, 49, 30, 30)
                );
        }
    }

    InnerSpriteWrapper CellSpriteGetter::getInnerSprite(const kernel::Cell *cell) {
        typedef kernel::Cell::Tileset Tileset;
        InnerSpriteWrapper result;
        result.cell_percentage = 0.8;
        switch (cell->getTileset()) {
            case Tileset::ROCK:
                result.sprite = texture_manager_.getSprite(
                        "resources/images/backgrounds/TilesetNature.png",
                        sf::IntRect(0, 194, 32, 32)
                );
                break;
            case Tileset::BUTTON:
                result.sprite = texture_manager_.getSprite(
                        "resources/images/backgrounds/TilesetDungeon.png",
                        sf::IntRect(0, 16, 16, 16)
                );
                break;
            case Tileset::FENCE_HORIZONTAL:
                result.sprite = texture_manager_.getSprite(
                        "resources/images/backgrounds/TilesetHouse.png",
                        sf::IntRect(161, 64, 15, 16)
                );
                break;
            case Tileset::FENCE_VERTICAL:
                result.sprite = texture_manager_.getSprite(
                        "resources/images/backgrounds/TilesetHouse.png",
                        sf::IntRect(176, 64, 15, 16)
                );
                break;
            case Tileset::SMALL_IRON_PILLAR:
                result.sprite = texture_manager_.getSprite(
                        "resources/images/backgrounds/TilesetHouse.png",
                        sf::IntRect(32, 352, 16, 16)
                );
                break;
            case Tileset::TORII:
                result.sprite = texture_manager_.getSprite(
                        "resources/images/backgrounds/TilesetHouse.png",
                        sf::IntRect(7, 82, 34, 28)
                );
                result.cell_percentage = 1;
                break;
            case Tileset::TREE_OAK:
                result.sprite = texture_manager_.getSprite(
                        "resources/images/backgrounds/TilesetNature.png",
                        sf::IntRect(0, 0, 32, 32)
                );
                result.cell_percentage = 1;
                break;
            case Tileset::TREE_SPRUCE:
                result.sprite = texture_manager_.getSprite(
                        "resources/images/backgrounds/TilesetNature.png",
                        sf::IntRect(33, 0, 32, 32)
                );
                result.cell_percentage = 1;
                break;
            case Tileset::AID_KIT:
                result.sprite = texture_manager_.getSprite(
                        "resources/images/items/Medipack.png",
                        sf::IntRect(0, 0, 10, 10)
                );
                result.cell_percentage = 0.5;
                break;
        }
        return result;
    }

}