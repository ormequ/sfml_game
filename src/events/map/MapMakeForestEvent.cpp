//
// Created by ilyab on 25.10.2022.
//

#include "MapMakeForestEvent.h"
#include "src/mapmaker/rules/CreateFieldRule.h"
#include "src/mapmaker/rules/ObstaclesRule.h"
#include "src/mapmaker/rules/WinRule.h"
#include "src/mapmaker/rules/PlayerPositionRule.h"
#include "src/mapmaker/rules/FallRule.h"
#include "src/mapmaker/rules/AidKitRule.h"
#include "src/mapmaker/rules/TrapButtonRule.h"

namespace events {

    MapMakeForestEvent::MapMakeForestEvent(mapmaker::MapGenerator *map_generator) : map_generator_(map_generator) {}

    void MapMakeForestEvent::dispatch(Point point) {
        map_generator_->generate<
            mapmaker::CreateFieldRule<20, 20>,
            mapmaker::PlayerPositionRule<0, 0>,
            mapmaker::ObstaclesRule<mapmaker::ObstacleType::FOREST>,
            mapmaker::WinRule<4, 4>,
            mapmaker::FallRule<2, 1>,
            mapmaker::AidKitRule<2, 2>,
            mapmaker::TrapButtonRule<0, 1>,
            mapmaker::TrapButtonRule<1, 0>
        >();
    }

    std::pair<FactoryName, std::string> MapMakeForestEvent::serialize() {
        return {FactoryName::MAP, "forest"};
    }

}