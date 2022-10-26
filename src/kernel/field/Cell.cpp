//
// Created by ilyab on 17.09.2022.
//

#include "Cell.h"
#include <iostream>

namespace kernel {

    Cell::Cell(Point point, bool passable): point_(point), passable_(passable) {
        listener_ = nullptr;
        tileset_ = Tileset::GRASS;
    }

    bool Cell::isPassable() const  {
        return passable_;
    }

    void Cell::changeState(bool passable) {
        passable_ = passable;
    }

    void Cell::dispatchListener() {
        if (listener_ != nullptr) {
            listener_->dispatch(point_);
        }
    }

    void Cell::addListener(events::IEvent* listener, bool delete_previous) {
        if (listener == nullptr) {
            throw std::invalid_argument("Kernel Exception: Incorrect event listener in the cell");
        }
        if (listener_ != nullptr && delete_previous) {
            delete listener_;
        }
        listener_ = listener;
    }

    void Cell::removeListener() {
        delete listener_;
        listener_ = nullptr;
    }

    Point Cell::getPoint() const {
        return point_;
    }

    Cell::Cell(const Cell& cell) {
        passable_ = cell.passable_;
        listener_ = cell.listener_;
        point_ = cell.point_;
        tileset_ = cell.tileset_;
    }

   /* Cell& Cell::operator=(const Cell& cell) {
        passable_ = cell.passable_;
        point_ = cell.point_;
        listener_ = cell.listener_;
        tileset_ = cell.tileset_;
        return *this;
    }*/

    Cell::~Cell() {
        // if (listener_ != nullptr) {
        delete listener_;
        // }
    }

    Cell::Tileset Cell::getTileset() const {
        return tileset_;
    }

    void Cell::setTileset(Cell::Tileset tileset) {
        tileset_ = tileset;
    }
}