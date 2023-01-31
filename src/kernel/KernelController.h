//
// Created by ilyab on 11.10.2022.
//

#ifndef GAME_KERNELCONTROLLER_H
#define GAME_KERNELCONTROLLER_H

namespace kernel {
    class KernelController;
}

#include "creatures/Player.h"
#include "creatures/CreatureManager.h"
#include "../GameMediator.h"
#include "field/Field.h"
#include "../Point.h"

namespace kernel {
    /// Контролирует главные элементы игры -- ядро
    class KernelController {
    public:
        explicit KernelController(GameMediator *game_mediator);

        void setField(IField *field);

        void setPlayer(ICreature *new_player, bool delete_prev = true);

        /// Определяет, что нужно делать на текущей итерации игры
        void update();

        ICreature *getPlayer();

        IField *getField();

        void moveCreature(ICreature *creature, Point point, bool dispatch = true);

        void rotateCreature(ICreature *creature, ICreature::Direction direction);

        CreatureManager *getCreatureManager();
    protected:
        CreatureManager *creature_manager_;
        GameMediator *game_mediator_;
        ICreature *player_;
        IField *field_;
    };
}


#endif //GAME_KERNELCONTROLLER_H
