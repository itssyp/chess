#include "rook.hpp"
using namespace genv;

rook::rook(bool w,int x, int y):piece(w,x,y){}

void rook::draw(int x, int y){
    if (_isWhite)
        gout<< move_to(x+25,y+25) << color(200,50,0) << box(50,50);
    else
        gout<< move_to(x+25,y+25) << color(100,0,200) << box(50,50);
}

bool rook::canMove(tile *t, std::vector<std::vector<tile>> tilesv){
    int x=t->getx()/100;
    int y=t->gety()/100;
    for (int i=_x; i<x ;i++) if(tilesv[_y][i].getPiece()) return false;
    for (int i=_x; i>x ;i--) if(tilesv[_y][i].getPiece()) return false;
    for (int i=_y; i<y ;i++) if(tilesv[i][_x].getPiece()) return false;
    for (int i=_y; i>y ;i--) if(tilesv[i][_x].getPiece()) return false;
    if ((y==_y || x==_x) && !t->getPiece())  return true;
    if ((y==_y || x==_x) && !t->getPiece()) return true;
    if ((y==_y || x==_x) && t->getPiece()->getWhite() && !_isWhite) return true;
    if ((y==_y || x==_x) && !t->getPiece()->getWhite() && _isWhite) return true;
    return false;
}
