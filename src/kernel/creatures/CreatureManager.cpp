//
// Created by ilyab on 21.09.2022.
//

#include "CreatureManager.h"

namespace kernel {

    CreatureManager::~CreatureManager() {
        for (auto c: creatures_) {
            delete c;
        }
        creatures_.clear();
    }

    unsigned int CreatureManager::addCreature(ICreature *creature) {
        creatures_.push_back(creature);
        return creatures_.size() - 1;
    }

    ICreature *CreatureManager::getCreature(unsigned int index) {
        return creatures_[index];
    }

    std::vector<ICreature *> CreatureManager::getAllCreatures() {
        return creatures_;
    }

}