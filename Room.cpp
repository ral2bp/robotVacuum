//
// Created by ravas on 2022. 05. 23..
//

#include "Room.h"

void Room::initialize(){
    for(auto& row : this->room)
        for(auto& tile : row ) {
            tile = 'D';
        }

}
void Room::draw() const{
    std::cout << "WWWWWWWWWWWWWWWW" << std::endl;
    for(auto row : room) {
        std::cout << "W";
        for (auto tile: row) {
            std::cout << tile;
        }
        std::cout << "W" << std::endl;
    }
    std::cout << "WWWWWWWWWWWWWWWW";
}

//vertical alignment, (0,5) shall be 0 to the right, 5 down, 0,0 is in the top left, 14, 14 in the top right.
void Room::addObstacle(Coordinate position, int width, int height){
    for(int i = position.getX(); i < position.getX() + width; i++)
        for(int j = position.getY(); j < position.getY() + height; j++)
            room[j][i] = 'F';
}
