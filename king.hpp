#ifndef KING_HPP_INCLUDED
#define KING_HPP_INCLUDED
#include "piece.hpp"
#include "widgets.hpp"
#include "tile.hpp"
class tile;
class king: public piece{
public:
    king(bool w,int x, int y);
    ~king();
    virtual void draw(int x, int y);
    virtual bool canMove(tile *t,std::vector<std::vector<tile>> tilesv);
    bool inCheck(std::vector<std::vector<tile>> tilesv);
};

#endif // KING_HPP_INCLUDED
