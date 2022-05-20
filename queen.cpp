#include "queen.hpp"
#include <iostream>
using namespace genv;

queen::queen(bool w,int x, int y):piece(w,x,y){}

void queen::draw(int x, int y){
    if (_isWhite)
        gout<< move_to(x+25,y+25) << color(255,255,50) << box(50,50);
    else
        gout<< move_to(x+25,y+25) << color(0,51,51) << box(50,50);
}

bool queen::canMove(tile *t, std::vector<std::vector<tile>> tilesv){
    int x=t->getx()/100;
    int y=t->gety()/100;
    if (x==_x && y==_y) return true;
    bool bishop=true;
    if (y==_y || x==_x) bishop=false;

    if (!bishop){

        if (x+1==_x && y+1==_y) return true;

        for (int i=_x; i<x ;i++) if(tilesv[_y][i].getPiece()) return false;
        for (int i=_x; i>x ;i--) if(tilesv[_y][i].getPiece()) return false;
        for (int i=_y; i<y ;i++) if(tilesv[i][_x].getPiece()) return false;
        for (int i=_y; i>y ;i--) if(tilesv[i][_x].getPiece()) return false;

        if ((y==_y || x==_x) && !t->getPiece())  return true;
        if ((y==_y || x==_x) && !t->getPiece()) return true;
        if ((y==_y || x==_x) && t->getPiece()->getWhite() && !_isWhite) return true;
        if ((y==_y || x==_x) && !t->getPiece()->getWhite() && _isWhite) return true;

    }
    if (bishop){

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

    }

    return false;
}
