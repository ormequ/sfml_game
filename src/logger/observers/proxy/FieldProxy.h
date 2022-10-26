//
// Created by ilyab on 22.10.2022.
//

#ifndef GAME_FIELDPROXY_H
#define GAME_FIELDPROXY_H

namespace logger {
    class FieldProxy;
}

#include "../../../kernel/field/Field.h"
#include "../../AbstractObserver.h"

namespace logger {
    class FieldProxy : public kernel::IField, public AbstractObserver {
    public:
        explicit FieldProxy(kernel::IField *field);

        void change(const kernel::IField& obj) override;

        void change(kernel::IField&& obj) override;

        const kernel::Cell *readCell(Point point) const override;

        Point getPreservedPoint(Point point) const override;

        kernel::Cell *getCell(Point point) override;

        int getWidth() const override;

        int getHeight() const override;

        Point getMoving(Point from, Point to) const override;

        std::vector<std::vector<kernel::Cell *>> &getAllCells() override;

        ~FieldProxy() override;
    protected:
        LogLevel getLogLevel() override;

        kernel::IField *field_;
    };
}

#endif //GAME_FIELDPROXY_H
