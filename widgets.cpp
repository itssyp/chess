#include "widgets.hpp"
#include "graphics.hpp"
#include "yWindow.h"
using namespace genv;

Widget::Widget(yWindow *w,std::string name,int x, int y, int sx, int sy) : _w(w),_name(name), _x(x), _y(y), _size_x(sx), _size_y(sy)
{
    w->registerWidget(this);
}
Widget::Widget(int x, int y, int sx, int sy):  _x(x), _y(y), _size_x(sx), _size_y(sy){}
Widget::Widget(){}
bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}






