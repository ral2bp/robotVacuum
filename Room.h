//
// Created by ravas on 2022. 05. 23..
//

#ifndef ROBOTVACUUM_ROOM_H
#define ROBOTVACUUM_ROOM_H

#include <iostream>
#include <array>
#include <thread>
#include "Coordinate.h"
#include "Direction.h"

class Room {
public:
    void initialize();
    void draw() const;
    void addObstacle(Coordinate position, int width, int height);

    void updateRobotPosition(Coordinate location);
    Room();

    bool nextTileTraversableIn(Direction direction);

private:
    static constexpr int roomWidth = 14;
    static constexpr int roomHeigth = 10;
    //this is a Y,X coordinate system, with 0-0 on top left, Y increasing to the right, and X increasing to the bottom
    std::array<std::array<char, roomWidth>,roomHeigth> room{};
    Coordinate robotPosition;

    bool tileIsWall(char tileContent);

    bool requestedTileIsOutOfBounds(Direction direction);

    static constexpr char furniture = 178;
};


#endif //ROBOTVACUUM_ROOM_H
