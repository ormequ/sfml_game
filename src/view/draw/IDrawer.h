//
// Created by ilyab on 05.10.2022.
//

#ifndef GAME_IDRAWER_H
#define GAME_IDRAWER_H

#include <SFML/Graphics.hpp>

namespace view {
    class IDrawer {
    public:
        virtual void draw(const sf::View&) = 0;
        virtual ~IDrawer() = default;
    };
}

#endif //GAME_IDRAWER_H
