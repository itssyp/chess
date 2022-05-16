#ifndef ROOK_HPP_INCLUDED
#define ROOK_HPP_INCLUDED
#include "widgets.hpp"
#include "tile.hpp"
#include "piece.hpp"
//class tile;
class rook: public piece{
public:
    rook(bool w,int x, int y);
    virtual void draw(int x, int y);
    virtual bool canMove(tile *t,std::vector<std::vector<tile>> tilesv);
};

#endif // ROOK_HPP_INCLUDED
