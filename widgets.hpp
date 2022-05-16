#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include <vector>
struct yWindow;

class Widget {
protected:
    yWindow *_w;
    std::string _name;
    int _x, _y, _size_x, _size_y;
public:
    Widget(yWindow *w,std::string name,int x, int y, int sx, int sy);
    Widget(int x, int y, int sx, int sy);
    Widget();
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual std::vector<std::string> getVal() = 0;
};



#endif // WIDGETS_HPP_INCLUDED
