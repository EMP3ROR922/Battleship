#include "graphics.hpp"
#include "warship.hpp"
#include "math.h"
#include<iostream>

using namespace genv;


Warship::Warship()
{

}


void Warship::damage(int ex, int ey,int &t)
{

}
bool Warship::getgrabbed()
{
    return grabbed;
}
void Warship::grab(int ex, int ey)
{
    if(kx - 15 < ex && ex < kx+15 && ky-15 < ey && ey < ky+15 && grabbed == false && !down )
    {
        grabbed = true;
        kattx = ex;
        katty = ey;
        ox = kx;
        oy = ky;
    }

}
void Warship::mozog(int ex, int ey)
{


}
void Warship::rajzol()
{

}
bool Warship::elhelyez(int ex, int ey)
{
    return true;
}
void Warship::setxy(int kx,int ky)
{

}
const int Warship::getkx()
{
    return kx;
}
const int Warship::getky()
{
    return ky;
}
const int Warship::returntype()
{
    return parts;
}

const bool Warship::returndestroyed()
{
    return destroyed;
}
void Warship::setdownvalue_false(int ex, int ey)
{
    down = false;
    grab(ex,ey);
}





void Destroyer::rajzol()
{

    gout << move_to(kx-15,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx,ky) << color(0,0,0) << dot;
}
void Destroyer::damage(int ex, int ey,int &t)
{
    if(kx - 15 < ex && ex < kx + 15 && ky - 15 < ey && ey <ky + 15 && t == 0  )
    {
        hits++;
        t++;
    }
    if(hits == parts)
    {
        destroyed = true;
    }
}
void Destroyer::mozog(int ex, int ey)
{
    if(ox+ex-kattx - 45 > 0 && ox+ex-kattx + 45 < 399 && oy+ey-katty -45 > 0 && oy+ey-katty + 45 < 399)
    {
        kx = ox+ex-kattx;
        ky = oy+ey-katty;
    }

}


bool Destroyer::elhelyez(int ex, int ey)
{

    if(sqrt(pow(ex-kx,2)+pow(ey-ky,2)) < 15)
    {
        grabbed = false;
        down = true;
        return true;
    }
    else
    {
        return false;
    }

}
void Destroyer::setxy(int kx, int ky)
{
    parts = 1;
    this->kx = kx;
    this->ky = ky;
}




void Cruiser::rajzol()
{

        gout << move_to(kx-45,ky-15) << color(151,151,151) << box(30,30);
        gout << move_to(kx-15,ky-15) << color(151,151,151) << box(30,30);
        gout << move_to(kx+15,ky-15) << color(151,151,151) << box(30,30);
        gout << move_to(kx,ky) << color(0,0,0) << dot;
}
void Cruiser::damage(int ex, int ey,int &t)
{
    if(kx - 45 < ex && ex < kx + 45 && ky - 45 < ey && ey <ky + 45 &&t == 0 )
    {
        hits++;
        t++;
    }
    if(hits == parts)
    {
        destroyed = true;
    }
}
void Cruiser::mozog(int ex, int ey)
{
    if(ox+ex-kattx - 75 > 0 && ox+ex-kattx + 75 < 399 && oy+ey-katty -45 > 0 && oy+ey-katty + 45 < 399)
    {
        kx = ox+ex-kattx;
        ky = oy+ey-katty;
    }

}
bool Cruiser::elhelyez(int ex, int ey)
{
    if(sqrt(pow(ex-kx,2)+pow(ey-ky,2)) < 15)
    {
        grabbed = false;
        down = true;
        return true;
    }
    else
    {
        return false;
    }
}
void Cruiser::setxy(int kx, int ky)
{
    this->kx = kx;
    this->ky = ky;
    parts = 3;
}




void Battleship::rajzol()
{

    gout << move_to(kx-75,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx-45,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx-15,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx+15,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx+45,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx,ky) << color(0,0,0) << dot;
}
void Battleship::damage(int ex, int ey,int &t)
{
    if(kx - 75 < ex && ex < kx + 75 && ky - 75 < ey && ey <ky + 75  )
    {
        hits++;
        t++;
    }
    if(hits == parts)
    {
        destroyed = true;
    }
}
void Battleship::mozog(int ex, int ey)
{
    if(ox+ex-kattx - 105 > 0 && ox+ex-kattx + 105 < 399 && oy+ey-katty -45 > 0 && oy+ey-katty + 45 < 399)
    {
        kx = ox+ex-kattx;
        ky = oy+ey-katty;
    }

}

bool Battleship::elhelyez(int ex, int ey)
{
    if(sqrt(pow(ex-kx,2)+pow(ey-ky,2)) < 15)
    {
        grabbed = false;
        down = true;
        return true;
    }
    else
    {
        return false;
    }
}
void Battleship::setxy(int kx, int ky)
{
    this->kx = kx;
    this->ky = ky;
    parts = 5;
}



void AircraftCarrier::rajzol()
{

    gout << move_to(kx-105,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx-75,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx-45,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx-15,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx+15,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx+45,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx+75,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx,ky) << color(0,0,0) << dot;
}
void AircraftCarrier::damage(int ex, int ey,int &t)
{
    if(kx - 105 < ex && ex < kx + 105 && ky - 105 < ey && ey <ky + 105  )
    {
        hits++;
        t++;
    }
    if(hits == parts)
    {
        destroyed = true;
    }
}
void AircraftCarrier::mozog(int ex, int ey)
{
    if(ox+ex-kattx - 135 > 0 && ox+ex-kattx + 135 < 399 && oy+ey-katty -45 > 0 && oy+ey-katty + 45 < 399)
    {
        kx = ox+ex-kattx;
        ky = oy+ey-katty;
    }

}

bool AircraftCarrier::elhelyez(int ex, int ey)
{
    if(sqrt(pow(ex-kx,2)+pow(ey-ky,2)) < 15)
    {
        grabbed = false;
        down = true;
        return true;
    }
    else
    {
        return false;
    }
}
void AircraftCarrier::setxy(int kx, int ky)
{
    this->kx = kx;
    this->ky = ky;
    parts = 7;
}
