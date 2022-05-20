#include "tile.hpp"
#include <iostream>
using namespace genv;

tile::tile(int x, int y, int sx, int sy, bool b, piece *p,std::function<void(tile &t)> f):_x(x),_y(y),_size_x(sx),_size_y(sy),_black(b),_piece(p), _f(f){}
tile::tile(){}

void tile::draw(){
    if (!_black)
    gout<< move_to(_x,_y) << color(255,255,255) << box(_size_x,_size_y);
    else
    gout<< move_to(_x,_y) << color(0,0,0) << box(_size_x,_size_y);
    if (_piece!=nullptr)
    _piece->draw(_x,_y);
}

void tile::handle(genv::event ev){
    if (ev.button==btn_left){
        _f(*this);
    }
}


bool tile::setPiece(piece *p,std::vector<std::vector<tile>> tilesv){
    if(p){
        if (p->canMove(this,tilesv)){
            p->setPos(_x/100,_y/100);
            _piece=p;            return true;
        }
    } else _piece=p;
    return false;
}

piece *tile::getPiece(){
    return _piece;
}

int tile::getx(){
    return _x;
}

int tile::gety(){
    return _y;
}
