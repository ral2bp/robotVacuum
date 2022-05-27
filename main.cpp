#include <iostream>
#include "Room.h"
#include "RobotVacuum.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Room room = Room();

    room.initialize();

    //TV stand on the left wall
    room.addObstacle(Coordinate(0,3), 2,4);

    //Small table in front of couch
    room.addObstacle(Coordinate(5,4), 2,2);

    //Couch
    room.addObstacle(Coordinate(9,3), 4,4);

    //Chair top
    room.addObstacle( Coordinate(4,1), 3,2);

    //Chair bottom
    room.addObstacle( Coordinate(4,7), 3,2);

    RobotVacuum robot = RobotVacuum(room, Coordinate(0,0));

    while(!robot.isFinished()) {
        robot.move();
        room.draw();
    }

    return 0;
}
