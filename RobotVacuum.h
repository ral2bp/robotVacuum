//
// Created by ravas on 2022. 05. 26..
//

#ifndef ROBOTVACUUM_ROBOTVACUUM_H
#define ROBOTVACUUM_ROBOTVACUUM_H

#include "Direction.h"
#include "Coordinate.h"
#include "Room.h"

class RobotVacuum {
public:
    void move();
    RobotVacuum(Room& roomToClean, Coordinate location);
    bool isFinished();

private:
    void moveInDirection();
    Room& roomToClean;
    Coordinate location;

    void turnLeft();

    Direction direction;

    void turnRight();

    Direction getDirectionAfterRightTurn();

    Direction getDirectionAfterLeftTurn();

    Direction lastUTurn;

    void resolveCollisionWithUTurns();

    void turnRightUntilNotAvailableOrStuck();
};


#endif //ROBOTVACUUM_ROBOTVACUUM_H
