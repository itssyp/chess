#include "pawn.hpp"
#include <iostream>
using namespace genv;

pawn::pawn(bool w, int x, int y): piece(w,x,y){}

void pawn::draw(int x, int y){
    if (_isWhite)
    gout<< move_to(x+25,y+25) << color(200,0,0) << box(50,50);
    else
    gout<< move_to(x+25,y+25) << color(0,0,200) << box(50,50);
}

bool pawn::canMove(tile *t, std::vector<std::vector<tile>> tilesv){
//    std::cout << i << "," << j << "," << _x <<"," << _y << std::endl;
//    if (t->getPiece()->getWhite()==this->getWhite()) return false;
    int x=t->getx()/100;
    int y=t->gety()/100;
    if (x==_x && y==_y) return true;
    if (t->getPiece()){
        if (_isWhite && y==_y-1 && (_x-1==x || x==_x+1)) return true;
        if (!_isWhite && y==_y+1 && (_x-1==x || x==_x+1)) return true;
    }
//    || (y==_y-1 && t->getPiece()->getWhite()==false) || (y==_y+1 && t->getPiece()->getWhite()==false)))
    if (_isWhite && y==_y-1 && x==_x && !t->getPiece())  return true;
    if (!_isWhite && y==_y+1 && x==_x && !t->getPiece()) return true;
    return false;
}
