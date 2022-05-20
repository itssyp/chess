#include "bishop.hpp"
#include <iostream>
using namespace genv;

bishop::bishop(bool w,int x, int y):piece(w,x,y){}

void bishop::draw(int x, int y){
    if (_isWhite)
        gout<< move_to(x+25,y+25) << color(200,50,100) << box(50,50);
    else
        gout<< move_to(x+25,y+25) << color(100,100,200) << box(50,50);
}

bool bishop::canMove(tile *t, std::vector<std::vector<tile>> tilesv){
    int x=t->getx()/100;
    int y=t->gety()/100;
    if (x==_x && y==_y) return true;
//    if (x+1==_x && y+1==_y) return true;
    if (tilesv[y][x].getPiece() && tilesv[y][x].getPiece()->getWhite() && getWhite()) return false;
    if (tilesv[y][x].getPiece() && !tilesv[y][x].getPiece()->getWhite() && !getWhite()) return false;
    for (int i=0; _y+i<y && _x+i<x; i++){
        if(tilesv[_y+i][_x+i].getPiece()) return false;
        if(_y+i+1==y  && _x+i+1==x) return true;
    }
    for (int i=0; _y+i<y && _x-i>x; i++){
        if(tilesv[_y+i][_x-i].getPiece()) return false;
        if(_y+i+1==y  && _x-i-1==x) return true;
    }
    for (int i=0; _y-i>y && _x-i>x; i++){
        if(tilesv[_y-i][_x-i].getPiece()) return false;
        if(_y-i-1==y  && _x-i-1==x) return true;
    }
    for (int i=0; _y-i>y && _x+i<x; i++){
        if(tilesv[_y-i][_x+i].getPiece()) return false;
        if(_y-i-1==y  && _x+i+1==x) return true;
    }


//    for (int i=0; _y+i<y ; i++){
//        std::cout << _x-i << "," << _y+i << "  " << x<< ","<< y << std::endl;
//        if(tilesv[_y+i][_x-i].getPiece() && tilesv[_y+i][_x-i].getPiece()->getWhite()==getWhite()) return false;
//        if(_y+i+1==y  && _x-i-1==x) return true;
//    }
//    for (int i=0; _y-i<y && _x+i<x; i++){
//        if(tilesv[_y-i][_x+i].getPiece() && tilesv[_y-i][_x+i].getPiece()->getWhite()==getWhite()) return false;
//        if(_y-i-1==y  && _x+i+1==x) return true;
//    }
//    for (int i=0; _y-i<y && _x-i<x; i++){
//        if(tilesv[_y-i][_x-i].getPiece() && tilesv[_y-i][_x-i].getPiece()->getWhite()==getWhite()) return false;
//        if(_y-i-1==y  && _x-i-1==x) return true;
//    }


    return false;
}
