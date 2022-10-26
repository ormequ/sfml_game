//
// Created by ilyab on 05.10.2022.
//

#ifndef GAME_FIELDDRAWER_H
#define GAME_FIELDDRAWER_H

#include "../IDrawer.h"
#include "../TextureManager.h"
#include "../../GameMediator.h"
#include "../../kernel/creatures/ICreature.h"
#include "CellSpriteGetter.h"

namespace view {
    class FieldDrawer : public IDrawer {
    public:
        FieldDrawer(sf::RenderWindow& window, TextureManager& texture_manager, GameMediator* game_mediator);

        void draw(const sf::View& view);

        void setCellSize(float cell_size);

        ~FieldDrawer();
    protected:
        void drawCreature(kernel::ICreature *creature);

        void drawCell(const kernel::Cell* cell);

        void moveToCellCenter(sf::Sprite& sprite, Point point, float cell_percent);

        TextureManager& texture_manager_;
        GameMediator* game_mediator_;
        sf::RenderWindow& window_;

        CellSpriteGetter *cell_sprite_getter_;

        float cell_size_=30.f;
    };
}


#endif //GAME_FIELDDRAWER_H
