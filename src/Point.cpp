//
// Created by ilyab on 19.09.2022.
//

#include "Point.h"

bool Point::operator==(const Point &p) const {
    return x == p.x && y == p.y;
}

bool Point::operator<(const Point &p) const {
    return x < p.x || (x == p.x && y < p.y);
}

bool Point::operator!=(const Point& p) const {
    return x != p.x || y != p.y;
}

Point::operator std::string() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
