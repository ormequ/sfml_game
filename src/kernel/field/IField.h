//
// Created by ilyab on 22.10.2022.
//

#ifndef GAME_IFIELD_H
#define GAME_IFIELD_H

namespace kernel {
    class IField;
}

#include <vector>
#include "Cell.h"

namespace kernel {
    /// Интерфейс поля. Нужен для прокси логирования
    class IField {
    public:
        virtual const Cell *readCell(Point point) const = 0;

        ///@return клетка с учетом границ карты (карта зациклена)
        virtual Point getPreservedPoint(Point point) const = 0;

        virtual Cell *getCell(Point point) = 0;

        // Вместо перегрузки оператора присваивания, так как должно быть логирование
        virtual void change(const IField &obj) = 0;

        virtual void change(IField &&obj) = 0;

        virtual int getWidth() const = 0;

        virtual int getHeight() const = 0;

        virtual std::vector<std::vector<Cell *>> &getAllCells() = 0;

        ///@return клетка с учетом границ карты и проходимости клеток
        virtual Point getMoving(Point from, Point to) const = 0;

        virtual ~IField() = default;
    };
}

#endif //GAME_IFIELD_H
