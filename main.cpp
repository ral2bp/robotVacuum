#include <iostream>
#include "Room.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Room room = Room();

    room.initialize();

    //TV stand on the left wall
    room.addObstacle(Coordinate(0,3), 1,5);

    //Small table in front of couch
    room.addObstacle(Coordinate(4,4), 2,3);

    //Couch
    room.addObstacle(Coordinate(7,2), 3,7);

    room.draw();

    std::cin.get();

    return 0;
}
