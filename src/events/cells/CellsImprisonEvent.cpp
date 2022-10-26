//
// Created by ilyab on 11.10.2022.
//

#include "CellsImprisonEvent.h"

namespace events {

//    CellsImprisonEvent::CellsImprisonEvent(kernel::Field *field) : CellsEvent(field) {}

    void CellsImprisonEvent::dispatch(Point point) {
        typedef kernel::Cell::Tileset Tileset;
//        std::vector<Tileset> tilesets = {
//                Tileset::WATER_GLARE, Tileset::WATER_LILY, Tileset::WATER_FISH
//        };
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i || j) {
                    kernel::Cell* cell = field_->getCell(
                            field_->getPreservedPoint({point.x + i, point.y + j})
                    );
                    cell->changeState(false);
                    cell->setTileset(Tileset::SMALL_IRON_PILLAR);
                    /*if (fabs((double)i) != fabs((double)j)) {
                        if (j != 0) {
                        } else {
                            cell->setTileset(Tileset::FENCE_VERTICAL);
                        }
                    } else {
                        cell->setTileset(Tileset::ROCK);
                    }*/
                }
            }
        }
        /*for (int i = 0; i < field_->getWidth(); i++) {
            for (int j = 0; j < field_->getHeight(); j++) {
                if (Point{i,j} != point) {
                }
            }
        }*/
        dispatchNext(point);
    }
}