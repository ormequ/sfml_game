//
// Created by ilyab on 20.09.2022.
//

#ifndef GAME_TEXTUREMANAGER_H
#define GAME_TEXTUREMANAGER_H

#include <map>
#include <string>
#include <SFML/Graphics.hpp>

namespace view {
    /// Загрузчик текстур и спрайтов (чтобы не загружать повторно один файл)
    class TextureManager {
    public:
        sf::Texture* getTexture(const std::string& file_path);

        sf::Sprite getSprite(std::string file_path, sf::IntRect rect);

    protected:
        sf::Texture* loadTexture(const std::string& file_path);

        std::map<std::string, sf::Texture*> loaded_textures_;
    };
}


#endif //GAME_TEXTUREMANAGER_H
