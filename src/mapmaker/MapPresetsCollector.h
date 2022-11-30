//
// Created by ilyab on 29.11.2022.
//

#ifndef GAME_MAPPRESETSCOLLECTOR_H
#define GAME_MAPPRESETSCOLLECTOR_H

#include "src/GameMediator.h"
#include "src/mapmaker/rules/CreateFieldRule.h"
#include "src/mapmaker/rules/ObstaclesRule.h"
#include "src/mapmaker/rules/WinRule.h"
#include "src/mapmaker/rules/PlayerPositionRule.h"
#include "src/mapmaker/rules/FallRule.h"
#include "src/mapmaker/rules/AidKitRule.h"
#include "src/mapmaker/rules/TrapButtonRule.h"
#include "src/mapmaker/rules/ChangeMapRule.h"

namespace mapmaker {
    class MapPresetsCollector {
    public:
        explicit MapPresetsCollector(GameMediator *game_mediator);

        void generate();
    private:
        GameMediator *game_mediator_;
    };
}


#endif //GAME_MAPPRESETSCOLLECTOR_H
