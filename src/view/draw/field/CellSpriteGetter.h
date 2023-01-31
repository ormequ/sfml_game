//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_CELLSPRITEGETTER_H
#define GAME_CELLSPRITEGETTER_H

#include "../TextureManager.h"
#include "../../../kernel/field/Cell.h"

namespace view {
    /// Так как у клеток могут быть объекты разного размера, эта структура приводит их к нужному
    struct InnerSpriteWrapper {
        float cell_percentage;
        sf::Sprite sprite;
    };

    /// Класс, необходимый для получения внешнего вида клетки по ее содержимому
    class CellSpriteGetter {
    public:
        explicit CellSpriteGetter(TextureManager& texture_manager);

        sf::Sprite getCellSprite(const kernel::Cell *cell);

        InnerSpriteWrapper getInnerSprite(const kernel::Cell *cell);
    private:
        TextureManager& texture_manager_;
    };
}


#endif //GAME_CELLSPRITEGETTER_H
