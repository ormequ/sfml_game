//
// Created by ilyab on 27.11.2022.
//

#ifndef GAME_OBSTACLESRULE_H
#define GAME_OBSTACLESRULE_H

#include <cmath>
#include "../../GameMediator.h"

namespace mapmaker {
    enum class ObstacleType {
        FOREST, LAKE
    };

    /// Правило расстановки препятствий (озеро или лес)
    template<ObstacleType Type>
    class ObstaclesRule {
    public:
        explicit ObstaclesRule(GameMediator *game_mediator) : game_mediator_(game_mediator) {};

        void operator()() {
            kernel::IField *field = game_mediator_->getField();
            Point player_pos = game_mediator_->getPlayer()->getPoint();
            if (Type == ObstacleType::LAKE) {
                Point lake_center = {field->getWidth() / 2, field->getHeight() / 2};
                createLake(
                    field,
                    lake_center,
                    {abs(lake_center.x - player_pos.x) * 4/5, abs(lake_center.y - player_pos.y) * 4/5}
                );
            }
            if (Type == ObstacleType::FOREST) {
                createForest(
                    field,
                    {(int)(field->getWidth() - player_pos.x-1) / 5, (int)(field->getHeight() - player_pos.y-1) / 5},
                    {(int)(field->getWidth() - player_pos.x-1) * 4/5, (int)(field->getHeight() - player_pos.y-1) * 4/5}
                );
            }
        }

    private:
        GameMediator* game_mediator_;

        void createLake(kernel::IField *field, Point center, Point size) {
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist(0,2);
            for (int x = -size.x+1; x < size.x; x++) {
                for (int y = -size.y+1; y < size.y; y++) {
                    if (game_mediator_->getPlayer()->getPoint() == Point{x,y}) {
                        continue;
                    }
                    int x_2 = x * x * size.y * size.y;
                    int y_2 = y * y * size.x * size.x;
                    int size_2 = size.y * size.y * size.x * size.x;
                    if (x_2 + y_2 <= size_2) {
                        kernel::Cell *cell = field->getCell({center.x + x, center.y + y});
                        unsigned int rand = dist(rng);
                        if (!rand) {
                            cell->setTileset(kernel::Cell::Tileset::WATER_GLARE);
                        } else if (rand == 1) {
                            cell->setTileset(kernel::Cell::Tileset::WATER_LILY);
                        } else {
                            cell->setTileset(kernel::Cell::Tileset::WATER_FISH);
                        }
                        cell->changeState(false);

                    }
                }
            }
        }

        void createForest(kernel::IField *field, Point start, Point end) {
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<std::mt19937::result_type> dist(0,3);
            for (int x = start.x; x <= end.x; x++) {
                for (int y = start.y; y <= end.y; y++) {
                    if (game_mediator_->getPlayer()->getPoint() == Point{x,y}) {
                        continue;
                    }
                    if (!dist(rng)) continue;
                    kernel::Cell *cell = field->getCell({x, y});
                    if (dist(rng) == 1) {
                        cell->setTileset(kernel::Cell::Tileset::TREE_OAK);
                    } else {
                        cell->setTileset(kernel::Cell::Tileset::TREE_SPRUCE);
                    }
                    cell->changeState(false);

                }
            }
        }
    };
}

#endif //GAME_OBSTACLESRULE_H
