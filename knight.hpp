#ifndef KNIGHT_HPP_INCLUDED
#define KNIGHT_HPP_INCLUDED
#include "piece.hpp"
#include "widgets.hpp"
#include "tile.hpp"
class tile;
class knight: public piece{
public:

    knight(bool w,int x, int y);
    virtual void draw(int x, int y);
    virtual bool canMove(tile *t,std::vector<std::vector<tile>> tilesv);
};

#endif // KNIGHT_HPP_INCLUDED
