//
// Created by ravasz on 2022. 05. 23..
//

#include "Room.h"

void Room::initialize(){
    for(auto& row : this->room)
        for(auto& tile : row ) {
            tile = 176; //soft dirt ░
        }

}
void Room::draw() const{
    std::cout << std::endl;
    std::cout << ((char)201); //top left corner
    for(int i = 0; i < 14; i++)
        std::cout << ((char)205); //horizontal wall
    std::cout << ((char)187); //top right corner
    std::cout << std::endl;
    for(auto row : room) {
        std::cout << ((char)186); //vertical wall on left
        for (auto tile: row) {
            std::cout << tile;
        }
        std::cout << ((char)186) << std::endl; //vertical wall on right
    }
    std::cout << ((char)200); //bottom left corner
    for(int i = 0; i < 14; i++)
        std::cout << ((char)205); //horizontal wall
    std::cout << ((char)188); //bottom right corner
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

//vertical alignment, (0,5) shall be 0 to the right, 5 down, 0,0 is in the top left, 14, 14 in the top right.
void Room::addObstacle(Coordinate position, int width, int height){
    for(int i = position.getX(); i < position.getX() + width; i++)
        for(int j = position.getY(); j < position.getY() + height; j++)
            room[j][i] = furniture;
}

void Room::updateRobotPosition(Coordinate location) {
    room[robotPosition.getX()][robotPosition.getY()] = ' ';
    robotPosition = location;
    room[location.getX()][location.getY()] = 254; // small filled rectange ■

}

Room::Room() : robotPosition(Coordinate(0,0)) {
}

bool Room::nextTileTraversableIn(Direction direction) {
    if(requestedTileIsOutOfBounds(direction))
        return false;

    switch(direction)
    {
        case(Direction::UP):
            return room[robotPosition.getX()-1][robotPosition.getY()] != furniture;
        case(Direction::RIGHT):
            return room[robotPosition.getX()][robotPosition.getY()+1] != furniture;
        case(Direction::DOWN):
            return room[robotPosition.getX()+1][robotPosition.getY()] != furniture;
        case(Direction::LEFT):
            return room[robotPosition.getX()][robotPosition.getY()-1] != furniture;
        default:
            return false;
    }
}

bool Room::requestedTileIsOutOfBounds(Direction direction) {
    switch(direction)
    {
        case(Direction::UP):
            return robotPosition.getX()-1 < 0;
        case(Direction::RIGHT):
            return robotPosition.getY()+1 > 13;
        case(Direction::DOWN):
            return robotPosition.getX()+1 > 9;
        case(Direction::LEFT):
            return robotPosition.getY()-1 < 0;
        default:
            return true;
    }
}

