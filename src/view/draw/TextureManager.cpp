//
// Created by ilyab on 20.09.2022.
//

#include "TextureManager.h"

namespace view {
    sf::Texture *TextureManager::getTexture(const std::string& file_path) {
        auto it = loaded_textures_.find(file_path);
        if (it == loaded_textures_.end()) {
            return loadTexture(file_path);
        }
        return it->second;
    }

    sf::Texture *TextureManager::loadTexture(const std::string& file_path) {
        auto *loaded = new sf::Texture();
        loaded->loadFromFile(file_path);
        loaded_textures_[file_path] = loaded;
        return loaded;
    }

    sf::Sprite TextureManager::getSprite(std::string file_path, sf::IntRect rect) {
        sf::Sprite sprite;
        sprite.setTexture(*getTexture(file_path));
        sprite.setTextureRect(rect);
        return sprite;
    }
}