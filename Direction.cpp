//
// Created by ravas on 2022. 05. 26..
//
#include "Direction.h"

Direction& operator++(Direction& d)
{
    using IntType = typename std::underlying_type<Direction>::type;
    if (d == Direction::LEFT )
        d = static_cast<Direction>(0);
    else
        d = static_cast<Direction>(static_cast<IntType>(d) + 1 );
    return d;
}

Direction& operator--(Direction& d)
{
    using IntType = typename std::underlying_type<Direction>::type;
    if (d == Direction::UP )
        d = static_cast<Direction>(3);
    else
        d = static_cast<Direction>(static_cast<IntType>(d) - 1 );
    return d;
}

Direction operator+(const Direction d, int i)
{
    Direction result;
    using IntType = typename std::underlying_type<Direction>::type;
    if (d == Direction::LEFT )
        result = static_cast<Direction>(0);
    else
        result = static_cast<Direction>(static_cast<IntType>(d) + 1 );
    return result;
}

Direction operator-(const Direction d, int i)
{
    Direction result;
    using IntType = typename std::underlying_type<Direction>::type;
    if (d == Direction::UP )
        result = static_cast<Direction>(3);
    else
        result = static_cast<Direction>(static_cast<IntType>(d) - 1 );
    return result;
}