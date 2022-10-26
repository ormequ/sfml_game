//
// Created by ilyab on 18.09.2022.
//

#ifndef GAME_POINT_H
#define GAME_POINT_H

#include <string>

struct Point {
    int x;
    int y;
    bool operator==(const Point &p) const;
    bool operator!=(const Point &p) const;
    bool operator<(const Point &p) const;
    explicit operator std::string() const;
};

#endif //GAME_POINT_H
