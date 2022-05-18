#ifndef QUEEN_HPP_INCLUDED
#define QUEEN_HPP_INCLUDED
#include "piece.hpp"
#include "widgets.hpp"
#include "tile.hpp"
class tile;
class queen: public piece{
public:

    queen(bool w,int x, int y);
    virtual void draw(int x, int y);
    virtual bool canMove(tile *t,std::vector<std::vector<tile>> tilesv);
};

#endif // QUEEN_HPP_INCLUDED
