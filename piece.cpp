#include "piece.hpp"
#include <iostream>

piece::piece(bool w, int x, int y): _isWhite(w), _x(x), _y(y){}

void piece::draw(int x, int y){}

void piece::setPos(int x, int y){
    this->_x=x;
    this->_y=y;
}

std::pair<int,int> piece::getPos(){
    return std::pair<int,int>(_x,_y);
}

int piece::getPosx(){
    return _x;
}
int piece::getPosy(){
    return _y;
}

bool piece::getWhite(){
    return _isWhite;
}
