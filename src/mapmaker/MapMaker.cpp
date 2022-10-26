//
// Created by ilyab on 11.10.2022.
//

#include "MapMaker.h"

namespace mapmaker {
    MapMaker::MapMaker(GameMediator *game_mediator) : game_mediator_(game_mediator) {}

    void MapMaker::generate() {
        typedef events::EventsController::Factory FactoryName;
        auto events_controller = game_mediator_->getEventsController();
        auto field = new kernel::Field(10, 10);
        game_mediator_->setField(field);

        game_mediator_->addCellEvent(
                {2,2},
                events_controller->produce(FactoryName::CELLS, "imprison")
                ->addNext(events_controller->produce(FactoryName::PLAYER, "beat"))->getFirst(),
                Cell_Tileset::BUTTON
        );

        game_mediator_->addCellEvent(
                {5, 5},
                events_controller->getFactory(FactoryName::PLAYER)->produce("beat"),
                Cell_Tileset::HOLE
        );

        game_mediator_->addCellEvent(
                {3, 5},
                events_controller->getFactory(FactoryName::PLAYER)->produce("heal"),
                Cell_Tileset::HEART
        );

        std::function<bool()> checker = [this]() {
            return this->game_mediator_->getPlayer()->getHp().value > 150;
        };

        game_mediator_->addCellEvent(
                {9, 5},
                events::EventsController::getEmptyEvent()->setTransmitChecker(checker)
                        ->addNext(events_controller->getFactory(FactoryName::GAME_STATE)->produce("win"))
                        ->getFirst(),
                Cell_Tileset::TORII
        );

        game_mediator_->addCellEvent(
                {1, 7},
                events_controller->produce(FactoryName::MAP, "forest"),
                Cell_Tileset::TUNNEL
        );
    }

    void MapMaker::generateByEvent() {
        auto field = game_mediator_->getField();
        field->change(kernel::Field(51, 38));

        for (int i = 0; i < field->getWidth(); i++) {
            for (int j = 0; j < field->getHeight(); j++) {
                kernel::Cell *cell = field->getCell({i, j});
                if (Point{i, j} == game_mediator_->getPlayer()->getPoint()) {
                    cell->setTileset(kernel::Cell::Tileset::TUNNEL);
                    continue;
                }
                int random = rand() % 15;
                if (random == 1) {
                    cell->setTileset(kernel::Cell::Tileset::WATER_GLARE);
                    cell->changeState(false);
                } else if (random == 2) {
                    cell->setTileset(kernel::Cell::Tileset::WATER_FISH);
                    cell->changeState(false);
                } else if (random < 4) {
                    cell->setTileset(kernel::Cell::Tileset::TREE_OAK);
                    cell->changeState(false);
                } else if (random < 6) {
                    cell->setTileset(kernel::Cell::Tileset::TREE_SPRUCE);
                    cell->changeState(false);
                }
            }
        }

    }
}
