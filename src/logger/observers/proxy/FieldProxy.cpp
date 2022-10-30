//
// Created by ilyab on 22.10.2022.
//

#include "FieldProxy.h"

namespace logger {
    FieldProxy::FieldProxy(kernel::IField *field) : field_(field) {
        if (field_ == nullptr) {
            throw std::invalid_argument("Logger Exception: Incorrect field for the field proxy");
        }
    }

    void FieldProxy::change(const kernel::IField& obj) {
        field_->change((const kernel::IField&) obj);
        notify("The field has been changed");
    }

    void FieldProxy::change(kernel::IField&& obj) {
        field_->change((kernel::IField&&) obj);
        notify("The field has been changed");
    }

    const kernel::Cell *FieldProxy::readCell(Point point) const {
        return field_->readCell(point);
    }

    Point FieldProxy::getPreservedPoint(Point point) const {
        return field_->getPreservedPoint(point);
    }

    kernel::Cell *FieldProxy::getCell(Point point) {
        return field_->getCell(point);
    }

    int FieldProxy::getWidth() const {
        return field_->getWidth();
    }

    int FieldProxy::getHeight() const {
        return field_->getHeight();
    }

    Point FieldProxy::getMoving(Point from, Point to) const {
        return field_->getMoving(from, to);
    }

    FieldProxy::~FieldProxy() {
        delete field_;
    }

    LogLevel FieldProxy::getLogLevel() {
        return LogLevel(LogLevel::Level::EVENTS);
    }

    std::vector<std::vector<kernel::Cell *>> &FieldProxy::getAllCells() {
        return field_->getAllCells();
    }
}