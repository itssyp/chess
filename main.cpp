#include "yWindow.h"
#include "pawn.hpp"
#include "widgets.hpp"
#include <iostream>
#include "chessboard.hpp"
using namespace genv;

enum {_pawn, _king, _queen, _rook, _bishop, _knight};

struct Window : public yWindow{
    chessboard *Board;
    Window(){
        Board= new chessboard(this,"board",0,0,800,800);
        for (Widget * wg : widgets) {
            wg->draw();
        }
        gout << refresh;
    }
};




int main()
{
    gout.open(800,800);
    gin.timer(40);
    Window nm;
    gout.load_font("LiberationSans-Regular.ttf",36,true);
    nm.event_loop();
    return 0;
}
