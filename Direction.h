//
// Created by ravas on 2022. 05. 26..
//

#ifndef ROBOTVACUUM_DIRECTION_H
#define ROBOTVACUUM_DIRECTION_H
#include <type_traits>

enum class Direction{
    UP,
    RIGHT,
    DOWN,
    LEFT
};

Direction& operator++(Direction& c);

Direction& operator--(Direction& c);

#endif //ROBOTVACUUM_DIRECTION_H
