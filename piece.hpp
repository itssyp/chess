#ifndef PIECE_HPP_INCLUDED
#define PIECE_HPP_INCLUDED
#include <vector>
class tile;
class piece{
protected:
    bool _isKilled=false;
    bool _isWhite;
    int _x,_y;
public:
    piece(bool w, int x, int y);
    virtual void draw(int x, int y) =0;
    virtual bool canMove(tile *t,std::vector<std::vector<tile>> tilesv) =0;
    void setPos(int x, int y);
    void getPos();
    bool getWhite();
};

#endif // PIECE_HPP_INCLUDED
