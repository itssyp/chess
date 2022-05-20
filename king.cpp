#include "king.hpp"
#include <iostream>
using namespace genv;

king::king(bool w,int x, int y):piece(w,x,y){}
king::~king(){
    std::cout<<"Game over";
}

void king::draw(int x, int y){
    if (_isWhite)
        gout<< move_to(x+25,y+25) << color(20,0,2) << box(50,50);
    else
        gout<< move_to(x+25,y+25) << color(100,200,200) << box(50,50);
}

bool king::canMove(tile *t, std::vector<std::vector<tile>> tilesv){
    int x=t->getx()/100;
    int y=t->gety()/100;
//    if ()
//    std::cout <<inCheck(tilesv) << std::endl;
    if (x==_x && y==_y) return true;
    if (t->getPiece() && t->getPiece()->getWhite()==getWhite()) return false;

    for (int j=_y-1; j<=_y+1; j++){
        for (int i=_x-1; i<=_x+1; i++){
            if (x==i && y==j) return true;
        }
    }

    return false;
}

bool king::inCheck(std::vector<std::vector<tile>> tilesv){
    tile *t = &tilesv[_y][_x];
    for(int j=0; j<8; j++){
        for(int i=0; i<8; i++){
            if (i!=_x && j!=_y && tilesv[j][i].getPiece() && tilesv[j][i].getPiece()->getWhite()!= getWhite() && tilesv[j][i].getPiece()->canMove(t, tilesv) ){
                std::cout << "check" << 1 <<std::endl;
                return true;
            }
        }
    }
    std::cout << "check" << 0 <<std::endl;
    return false;
}
