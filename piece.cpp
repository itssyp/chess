#include "piece.hpp"
#include <iostream>

piece::piece(bool w, int x, int y): _isWhite(w), _x(x), _y(y){}

void piece::draw(int x, int y){}

void piece::setPos(int x, int y){
    this->_x=x;
    this->_y=y;
}

void piece::getPos(){
    std::cout << _x << "," << _y << std::endl;
}

bool piece::getWhite(){
    return _isWhite;
}
