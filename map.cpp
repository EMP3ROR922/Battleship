#include "graphics.hpp"
#include "map.hpp"
#include<math.h>
#include<iostream>

using namespace genv;




Sector::Sector(int x,int y) : Ocean(x,y)
{
    r = 0;
    g = 0;
    b = 255;
}


void Sector::szinez(event ev)
{
    int xk = x + 15;
    int yk = y + 15;
    if(ev.button == btn_left && sqrt(pow(ev.pos_x - xk,2)+pow(ev.pos_y - yk,2)) < 15 && ship)
    {
        r = 255;
        g = 0;
        b = 0;
        /*std::cout << 30*sqrt(2)/2 << std::endl;
        std::cout << sqrt(pow(ev.pos_x - xk,2)+pow(ev.pos_y - yk,2)) << std::endl;*/
    }
    if(ev.button == btn_right && sqrt(pow(ev.pos_x - xk,2)+pow(ev.pos_y - yk,2)) < 15)
    {
        r = 0;
        g = 255;
        b = 0;
    }
}

void Sector::rajzol()
{
    gout << move_to(x,y) << color(r,g,b) << box(30,30);
    gout << move_to(x,y) << color(0,0,0) << line_to(x, 399);
    gout << move_to(x,y) << color(0,0,0) << line_to(399, y);
}
