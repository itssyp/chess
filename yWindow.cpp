#include "yWindow.h"
#include "graphics.hpp"
#include <fstream>
using namespace genv;

void torol(){
    gout << move_to(0,0) << color(0,0,0) << box_to(399,399);
}

yWindow::yWindow(){}

void yWindow::event_loop(){
    event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode!=key_escape) {
        bool was_event=false;
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                        was_event=true;
                }
            }
        }
        if (ev.keycode==key_tab) focus++;
        if (focus>=widgets.size()) focus=0;
        if (ev.type==ev_timer){
            torol();
            for (Widget * w : widgets) {
                w->draw();
            }
        }
            if (focus!=-1) {
                widgets[focus]->handle(ev);
            }

        gout << refresh;
    }
}
void yWindow::registerWidget(Widget *w){widgets.push_back(w);}
void yWindow::_event(){};

