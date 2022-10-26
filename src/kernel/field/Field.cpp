//
// Created by ilyab on 17.09.2022.
//

#include "Field.h"

namespace kernel {
    Field::Field(int width, int height) : width_(width), height_(height) {
        if (width_ <= 0 || height_ <= 0) {
            throw std::invalid_argument("Kernel Exception: Incorrect field size.");
        }
//        width_ = width_ <= 0 ? 10 : width_;
//        height_ = height_ <= 0 ? 10 : height_;
        cells_ = std::vector<std::vector<Cell *>>(
                width_, std::vector<Cell *>(height_, nullptr)
        );
        for (int i = 0; i < width_; i++) {
            cells_.emplace_back(height_);
            for (int j = 0; j < height_; j++) {
//                if (i + j == fmax(height_, width_)) {
//                    cells_[i][j] = new Cell({i, j}, false);
//                } else {
                cells_[i][j] = new Cell({i, j});
//                }
            }
        }
    }

    int Field::getWidth() const {
        return width_;
    }

    int Field::getHeight() const {
        return height_;
    }

    Point Field::getMoving(Point from, Point to) const {
        to = getPreservedPoint(to);
        if (!cells_[to.x][to.y]->isPassable()) {
            return from;
        }
        return to;
    }

    const Cell *Field::readCell(Point point) const {
        return cells_[point.x][point.y];
    }

//    Cell *Field::getCell(Point point) {
//        return cells_[point.x][point.y];
//    }

    Field::Field(const Field& obj) : height_(obj.height_), width_(obj.width_) {
        cells_ = std::vector<std::vector<Cell *>>(
                width_, std::vector<Cell *>(height_, nullptr)
        );

        for (int i = 0; i < width_; i++) {
            for (int j = 0; j < height_; j++) {
                cells_[i][j] = new Cell({i, j});
                *cells_[i][j] = *obj.cells_[i][j];
            }
        }

    }

    Field::Field(Field&& obj) : height_(obj.height_), width_(obj.width_) {
        std::swap(cells_, obj.cells_);
    }

    void Field::change(const IField& obj) {
        if (this != &obj) {
            for (auto vec: cells_) {
                for (auto it: vec) {
                    delete it;
                }
                vec.clear();
            }
            cells_.clear();

            height_ = obj.getHeight();
            width_ = obj.getWidth();
            // cells_ = std::vector<std::vector<Cell *>>(
            //         width_, std::vector<Cell *>(height_, nullptr)
            // );

            for (int i = 0; i < width_; i++) {
                cells_.emplace_back(height_, nullptr);
                for (int j = 0; j < height_; j++) {
                    cells_[i][j] = new Cell(*obj.readCell({i, j}));
                }
            }

        }
    }

    void Field::change(IField&& obj) {
        if (this != &obj) {
            for (auto vec: cells_) {
                for (auto it: vec) {
                    delete it;
                }
                vec.clear();
            }
            cells_.clear();

            height_ = obj.getHeight();
            width_ = obj.getWidth();
            std::swap(cells_, obj.getAllCells());
        }
    }

    Field::~Field() {
        for (auto vec: cells_) {
            for (auto it: vec) {
                delete it;
            }
            vec.clear();
        }
        cells_.clear();
    }

    Point Field::getPreservedPoint(Point point) const {
        if (point.x >= getWidth()) {
            point.x = 0;
        }
        if (point.y >= getHeight()) {
            point.y = 0;
        }
        if (point.x < 0) {
            point.x = getWidth() - 1;
        }
        if (point.y < 0) {
            point.y = getHeight() - 1;
        }
        return point;
    }

    Cell *Field::getCell(Point point) {
        return cells_[point.x][point.y];
    }

    std::vector<std::vector<Cell *>>& Field::getAllCells() {
        return cells_;
    }
}