//
// Created by ravas on 2022. 05. 26..
//

#include "RobotVacuum.h"


RobotVacuum::RobotVacuum(Room &roomToClean, Coordinate location) : roomToClean(roomToClean), location(location),
                                                                   direction(Direction::DOWN) {
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
    if (roomToClean.nextTileTraversableIn(direction))
        moveInDirection();
    else{
        if (lastUTurn == Direction::LEFT) {
            if (roomToClean.nextTileTraversableIn(getDirectionAfterRightTurn())) {
                turnRight();
                moveInDirection();
                turnRight();
            } else {
                turnLeft();
            }
            lastUTurn = Direction::RIGHT;
        } else {
            if (roomToClean.nextTileTraversableIn(getDirectionAfterLeftTurn())) {
                turnLeft();
                moveInDirection();
                turnLeft();
            } else {
                turnRight();
            }
            lastUTurn = Direction::LEFT;
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

void RobotVacuum::turnRightUntilNotAvailableOrStuck() {
    if(roomToClean.nextTileTraversableIn(getDirectionAfterRightTurn()))
    {
        turnRight();
    }
    else if(roomToClean.nextTileTraversableIn(getDirectionAfterLeftTurn()))
    {
        turnLeft();
    }
    else//neither left, forward or right is available, move back
    {
        turnRight();
        turnRight();
    }

    moveInDirection();
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


