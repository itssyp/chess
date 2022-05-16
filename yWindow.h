#ifndef YNOTMAIN_H_INCLUDED
#define YNOTMAIN_H_INCLUDED
#include "vector"
#include "widgets.hpp"
class yWindow {
protected:
    std::vector<Widget*> widgets;
public:
    yWindow();
    void event_loop();
    void registerWidget(Widget *w);
    virtual void _event();
};

#endif // YNOTMAIN_H_INCLUDED
