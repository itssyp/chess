#include "king.hpp"
using namespace genv;

king::king(bool w,int x, int y):piece(w,x,y){}

void king::draw(int x, int y){
    if (_isWhite)
        gout<< move_to(x+25,y+25) << color(20,0,2) << box(50,50);
    else
        gout<< move_to(x+25,y+25) << color(100,200,200) << box(50,50);
}

bool king::canMove(tile *t, std::vector<std::vector<tile>> tilesv){
    int x=t->getx()/100;
    int y=t->gety()/100;
    if (x==_x && y==_y) return true;
    if (t->getPiece() && t->getPiece()->getWhite()==getWhite()) return false;

    for (int j=_y-1; j<=_y+1; j++){
        for (int i=_x-1; i<=_x+1; i++){
            if (x==i && y==j) return true;
        }
    }

    return false;
}
