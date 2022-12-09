//
// Created by ilyab on 11.10.2022.
//

#include "CellsImprisonEvent.h"

namespace events {

//    CellsImprisonEvent::CellsImprisonEvent(kernel::Field *field) : CellsEvent(field) {}

    void CellsImprisonEvent::dispatch(Point point) {
        typedef kernel::Cell::Tileset Tileset;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i || j) {
                    kernel::Cell* cell = field_->getCell(
                            field_->getPreservedPoint({point.x + i, point.y + j})
                    );
                    cell->changeState(false);
                    cell->setTileset(Tileset::SMALL_IRON_PILLAR);
                }
            }
        }
        dispatchNext(point);
    }

    std::pair<FactoryName, std::string> CellsImprisonEvent::serialize() {
        return {FactoryName::CELLS, "imprison"};
    }
}