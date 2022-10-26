//
// Created by ilyab on 17.09.2022.
//

#ifndef GAME_FIELD_H
#define GAME_FIELD_H

namespace kernel {
    class Field;
}

#include <random>
#include <cmath>
#include <map>
#include <stdexcept>
#include <utility>

#include "IField.h"

namespace kernel {
    class Field : public IField {
    public:
        explicit Field(int width = 50, int height = 50);

        Field(const Field &obj);

        Field(Field &&obj);

        void change(const IField &obj) override;

        void change(IField &&obj) override;

        const Cell *readCell(Point point) const override;

        Point getPreservedPoint(Point point) const override;

        Cell *getCell(Point point) override;

        int getWidth() const override;

        int getHeight() const override;

        Point getMoving(Point from, Point to) const override;

        std::vector<std::vector<Cell *>> &getAllCells() override;

        ~Field() override;

    protected:
        std::vector<std::vector<Cell *>> cells_;
        int width_;
        int height_;
    };
}


#endif //GAME_FIELD_H
