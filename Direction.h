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

Direction& operator++(Direction& d);

Direction& operator--(Direction& d);

Direction operator+(const Direction d, int i);

Direction operator-(const Direction d, int i);

#endif //ROBOTVACUUM_DIRECTION_H
