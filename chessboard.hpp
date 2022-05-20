#ifndef CHESSBOARD_HPP_INCLUDED
#define CHESSBOARD_HPP_INCLUDED
#include "tile.hpp"
class tile;
class chessboard: public Widget{
    tile tiles[8][8];
    piece *_selectedPiece=0;
    bool onTurn=true;
public:
    chessboard(yWindow *w,std::string name,int x, int y, int sx, int sy);
    virtual void draw();
    virtual void handle(genv::event ev);
    virtual std::vector<std::string> getVal();
    void set_selectedPiece(piece *p);
    piece *get_selectedPiece();
    bool inCheck(piece *p);
    bool getonTurn();
    void changeTurn();
    std::vector<std::vector<tile>> getTiles();
};

#endif // CHESSBOARD_HPP_INCLUDED
