#ifndef TILE_HPP_INCLUDED
#define TILE_HPP_INCLUDED
#include "widgets.hpp"
#include <functional>
#include "piece.hpp"
class tile{
    int _x,_y,_size_x,_size_y;
    bool _black;
    piece *_piece;
    std::function<void(tile &t)> _f;
public:
    tile();
    tile(int x, int y, int sx, int sy, bool b, piece *p,std::function<void(tile &t)> f);
    void draw();
    void handle(genv::event ev);
    piece *getPiece();
    bool setPiece(piece *p,std::vector<std::vector<tile>> tilesv);
    int getx();
    int gety();
};

#endif // TILE_HPP_INCLUDED
