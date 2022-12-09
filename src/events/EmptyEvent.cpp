//
// Created by ilyab on 12.10.2022.
//

#include "EmptyEvent.h"

namespace events {
    void EmptyEvent::dispatch(Point point) {
        dispatchNext(point);
    }

    std::pair<FactoryName, std::string> EmptyEvent::serialize() {
        return {};
    }
}