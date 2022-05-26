//
// Created by ravas on 2022. 05. 26..
//

#include "RobotVacuum.h"



RobotVacuum::RobotVacuum(Room& roomToClean, Coordinate location) : roomToClean(roomToClean), location(location), direction(Direction::DOWN) {
    roomToClean.updateRobotPosition(location);
}

bool RobotVacuum::isFinished() {
    if(location.getX() < 10)
        return false;
    else
        return true;
}

void RobotVacuum::move() {
    if(roomToClean.nextTileTraversableIn(direction))
        moveInDirection();
    else
        turnLeft();
}

void RobotVacuum::moveInDirection() {
    switch(direction)
    {
        case(Direction::UP):
            location.setX(location.getX()-1);
            break;
        case(Direction::RIGHT):
            location.setY(location.getY()+1);
            break;
        case(Direction::DOWN):
            location.setX(location.getX()+1);
            break;
        case(Direction::LEFT):
            location.setY(location.getY()-1);
            break;
        default:
            break;
    }
    roomToClean.updateRobotPosition(location);
}

void RobotVacuum::turnLeft() {
    --direction;
}

void RobotVacuum::turnRight() {
    ++direction;
}
