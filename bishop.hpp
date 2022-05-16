#ifndef BISHOP_HPP_INCLUDED
#define BISHOP_HPP_INCLUDED
#include "piece.hpp"
#include "widgets.hpp"
#include "tile.hpp"
class tile;
class bishop: public piece{
public:
    bishop(bool w,int x, int y);
    virtual void draw(int x, int y);
    virtual bool canMove(tile *t,std::vector<std::vector<tile>> tilesv);
};

#endif // BISHOP_HPP_INCLUDED
