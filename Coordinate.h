//
// Created by ravas on 2022. 05. 23..
//

#ifndef ROBOTVACUUM_COORDINATE_H
#define ROBOTVACUUM_COORDINATE_H


class Coordinate {
public:
    Coordinate(int x, int y) : x(x), y(y){

    }

    void setCoordinate(int x, int y){
        this->x = x;
        this->y = y;
    }

    int getX() const{
        return x;
    }

    int getY() const{
        return y;
    }

private:
int x;
int y;


};


#endif //ROBOTVACUUM_COORDINATE_H
