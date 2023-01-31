//
// Created by ilyab on 21.09.2022.
//

#ifndef GAME_CREATUREMANAGER_H
#define GAME_CREATUREMANAGER_H

#include <vector>
#include <stdexcept>

#include "Player.h"
#include "../../Point.h"

namespace kernel {
    /// Хранит всех созданий
    class CreatureManager {
    public:
        unsigned int addCreature(ICreature *creature);

        ICreature *getCreature(unsigned int index);

        std::vector<ICreature *> getAllCreatures();

        ~CreatureManager();

    protected:
        std::vector<ICreature *> creatures_;
    };
}


#endif //GAME_CREATUREMANAGER_H
