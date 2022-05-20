#include "knight.hpp"
using namespace genv;

knight::knight(bool w,int x, int y):piece(w,x,y){}

void knight::draw(int x, int y){
    if (_isWhite)
        gout<< move_to(x+25,y+25) << color(204,0,204) << box(50,50);
    else
        gout<< move_to(x+25,y+25) << color(0,255,255) << box(50,50);
}

bool knight::canMove(tile *t, std::vector<std::vector<tile>> tilesv){
    int x=t->getx()/100;
    int y=t->gety()/100;
    if (x==_x && y==_y) return true;
    if (t->getPiece() && t->getPiece()->getWhite()==getWhite()) return false;
    if ((_x+1==x &&_y+2==y) ||
        (_x-1==x &&_y+2==y) ||
        (_x+1==x &&_y-2==y) ||
        (_x-1==x &&_y-2==y) ||
        (_x+2==x &&_y+1==y) ||
        (_x-2==x &&_y+1==y) ||
        (_x+2==x &&_y-1==y) ||
        (_x-2==x &&_y-1==y)
        ) return true;

    return false;
}

