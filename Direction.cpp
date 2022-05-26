//
// Created by ravas on 2022. 05. 26..
//
#include "Direction.h"

Direction& operator++(Direction& c)
{
    using IntType = typename std::underlying_type<Direction>::type;
    if ( c == Direction::LEFT )
        c = static_cast<Direction>(0);
    else
        c = static_cast<Direction>(static_cast<IntType>(c) + 1 );
    return c;
}

Direction& operator--(Direction& c)
{
    using IntType = typename std::underlying_type<Direction>::type;
    if ( c == Direction::UP )
        c = static_cast<Direction>(3);
    else
        c = static_cast<Direction>(static_cast<IntType>(c) - 1 );
    return c;
}