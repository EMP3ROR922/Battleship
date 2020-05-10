#include "graphics.hpp"
#include "map.hpp"
#include "gamemaster.hpp"
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
    if(ev.button == btn_left && xk - 15 < ev.pos_x && ev.pos_x < xk + 15 && yk - 15 < ev.pos_y && ev.pos_y < yk + 15 && ship_present)
    {
        r = 255;
        g = 0;
        b = 0;
        std::cout << 30*sqrt(2)/2 << std::endl;
        std::cout << sqrt(pow(ev.pos_x - xk,2)+pow(ev.pos_y - yk,2)) << std::endl;
    }
    if(ev.button == btn_left && xk - 15 < ev.pos_x && ev.pos_x < xk + 15 && yk - 15 < ev.pos_y && ev.pos_y < yk + 15 && !ship_present)
    {
        r = 0;
        g = 255;
        b = 0;
    }
}

void Sector::rajzol()
{
    if(ship_present)
    {
        gout << move_to(x,y) << color(151,151,151) << box(30,30);
        gout << move_to(x,y) << color(0,0,0) << line_to(x, 399);
        gout << move_to(x,y) << line_to(399, y);
    }else
    {
        gout << move_to(x,y) << color(r,g,b) << box(30,30);
        gout << move_to(x,y) << color(0,0,0) << line_to(x, 399);
        gout << move_to(x,y) << line_to(399, y);
    }

}
void Sector::rajzol_game()
{
    gout << move_to(x,y) << color(r,g,b) << box(30,30);
    gout << move_to(x,y) << color(0,0,0) << line_to(x, 399);
    gout << move_to(x,y) << line_to(399, y);
}
pair<int,int> Sector::setshipsstatus(int shipx,int shipy)
{
    if(sqrt(pow(shipx-x-15,2)+pow(shipy-y-15,2)) < 15)
    {
        ship_present = true;
        return make_pair(x+15,y+15);
    }
    return make_pair(-1,-1);
}

const bool Sector::getshipstatus()
{
    return ship_present;
}
