//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_HUDDRAWER_H
#define GAME_HUDDRAWER_H

#include <vector>
#include "../IDrawer.h"
#include "../TextureManager.h"
#include "../../../GameMediator.h"

namespace view {
    class HudDrawer : public IDrawer {
    public:
        HudDrawer(sf::RenderWindow& window, TextureManager& texture_manager, GameMediator* game_mediator);

        void draw(const sf::View& view);

        ~HudDrawer() = default;
    private:
        sf::RenderWindow& window_;
        TextureManager& texture_manager_;
        GameMediator* game_mediator_;
    };
}


#endif //GAME_HUDDRAWER_H
