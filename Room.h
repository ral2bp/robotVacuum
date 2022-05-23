//
// Created by ravas on 2022. 05. 23..
//

#ifndef ROBOTVACUUM_ROOM_H
#define ROBOTVACUUM_ROOM_H

#include <iostream>
#include <array>
#include "Coordinate.h"

class Room {
public:
    void initialize();
    void draw() const;
    void addObstacle(Coordinate position, int width, int height);

private:
    int height;
    int width;
    std::array<std::array<char, 14>,10> room;
};


#endif //ROBOTVACUUM_ROOM_H
