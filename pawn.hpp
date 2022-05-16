#ifndef PAWN_HPP_INCLUDED
#define PAWN_HPP_INCLUDED
#include "widgets.hpp"
#include "tile.hpp"
#include "piece.hpp"
class tile;
class pawn: public piece{
public:
    pawn(bool w,int x, int y);
    virtual void draw(int x, int y);
    virtual bool canMove(tile *t,std::vector<std::vector<tile>> tilesv);
};

#endif // PAWN_HPP_INCLUDED
