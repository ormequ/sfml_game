//
// Created by ilyab on 19.09.2022.
//

#ifndef GAME_DRAWMANAGER_H
#define GAME_DRAWMANAGER_H

namespace view {
    class DrawManager;
}

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "../../GameMediator.h"
#include "TextureManager.h"
#include "field/FieldDrawer.h"
#include "HUD/HudDrawer.h"

namespace view {
    /// Отвечает за отображение всего
    class DrawManager {
    public:
        explicit DrawManager(GameMediator* game_mediator, sf::RenderWindow& window);

        void draw();
    protected:
        std::vector<IDrawer *> drawers_;

        GameMediator* game_mediator_;
        sf::RenderWindow& window_;
        TextureManager texture_manager_;
        const float CELL_SIZE_=30.f;
    };
}


#endif //GAME_DRAWMANAGER_H
