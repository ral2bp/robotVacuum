//
// Created by ravas on 2022. 05. 26..
//

#include "RobotVacuum.h"


RobotVacuum::RobotVacuum(Room &roomToClean, Coordinate location) : roomToClean(roomToClean), location(location),
                                                                   direction(Direction::DOWN), lastUTurn(Direction::RIGHT) {
    roomToClean.updateRobotPosition(location);
}

bool RobotVacuum::isFinished() {
    if (location.getX() < 10)
        return false;
    else
        return true;
}

void RobotVacuum::move() {
        resolveCollisionWithUTurns();
}

void RobotVacuum::resolveCollisionWithUTurns() {
    if (roomToClean.nextTileTraversableIn(direction)) //if no collision detected
        moveInDirection(); //move forward
    else{//if collision was detected
        if (lastUTurn == Direction::LEFT) {//if the last U-turn was left, follow the plow pattern and turn right!
            if (roomToClean.nextTileTraversableIn(getDirectionAfterRightTurn())) {//is right turn possible?
                turnRight();//turn right
                moveInDirection();//move forward
                if (roomToClean.nextTileTraversableIn(getDirectionAfterRightTurn())) {//is a complete U-turn to the right possible?
                    turnRight();//complete U-turn
                    lastUTurn = Direction::RIGHT;//store completed U-turn
                }
            } else {
                turnLeft();//cannot go right, cannot go forward, try going left!
            }
        } else {//if the last U-turn was right, follow the plow pattern to the left!
            if (roomToClean.nextTileTraversableIn(getDirectionAfterLeftTurn())) {
                turnLeft();
                moveInDirection();
                if (roomToClean.nextTileTraversableIn(getDirectionAfterLeftTurn())) {
                    turnLeft();
                    lastUTurn = Direction::LEFT;
                }
            } else {
                turnRight();
            }
        }
    }
}

void RobotVacuum::moveInDirection() {
    switch (direction) {
        case (Direction::UP):
            location.setX(location.getX() - 1);
            break;
        case (Direction::RIGHT):
            location.setY(location.getY() + 1);
            break;
        case (Direction::DOWN):
            location.setX(location.getX() + 1);
            break;
        case (Direction::LEFT):
            location.setY(location.getY() - 1);
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

Direction RobotVacuum::getDirectionAfterRightTurn() {
    return direction + 1;
}

Direction RobotVacuum::getDirectionAfterLeftTurn() {
    return direction - 1;
}


