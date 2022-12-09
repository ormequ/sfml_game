//
// Created by ilyab on 29.11.2022.
//

#include "MapPresetsCollector.h"

namespace mapmaker {

    MapPresetsCollector::MapPresetsCollector(GameMediator *game_mediator) : game_mediator_(game_mediator) {}

    void MapPresetsCollector::generate() {
        std::string map_type = game_mediator_->askUser("What map do you want?", {"lake", "forest", "empty"});
        MapGenerator *map_generator = game_mediator_->getMapGenerator();
        if (map_type == "lake") {
            map_generator->generate<
                mapmaker::CreateFieldRule<60, 21>,
                mapmaker::ObstaclesRule<mapmaker::ObstacleType::LAKE>,
                mapmaker::WinRule<4, 4>,
                mapmaker::ChangeMapRule<2, 2>,
                mapmaker::AidKitRule<7, 1>,
                mapmaker::TrapButtonRule<8, 0>
            >();
        } else if (map_type == "forest") {
            map_generator->generate<
                mapmaker::CreateFieldRule<38, 19>,
                mapmaker::ObstaclesRule<mapmaker::ObstacleType::FOREST>,
                mapmaker::WinRule<19, 4>,
                mapmaker::TrapButtonRule<17, 3>,
                mapmaker::TrapButtonRule<18, 3>,
                mapmaker::TrapButtonRule<19, 3>,
                mapmaker::TrapButtonRule<20, 3>,
                mapmaker::TrapButtonRule<21, 3>
            >();
        } else {
            map_generator->generate<
                mapmaker::CreateFieldRule<100, 100>,
                mapmaker::WinRule<2, 2>
            >();
        }
    }
}