#include "graphics.hpp"
#include "warship.hpp"

using namespace genv;


Warship::Warship()
{

}


void Warship::damage()
{

}
bool Warship::getgrabbed()
{
    return grabbed;
}
void Warship::grab(int ex, int ey)
{
    if(kx - 15 < ex && ex < kx+15 && ky-15 < ey && ey < ky+15 && grabbed == false )
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
    kx = ox+ex-kattx;
    ky = oy+ey-katty;
}
void Warship::rajzol()
{

}
void Warship::elhelyez(int ex, int ey)
{

}
void Warship::setxy(int kx,int ky)
{

}





void Destroyer::rajzol()
{

    gout << move_to(kx-15,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx,ky) << color(0,0,0) << dot;
}
void Destroyer::damage()
{

}


void Destroyer::elhelyez(int ex, int ey)
{
    grabbed = false;
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
void Cruiser::damage()
{

}
void Cruiser::elhelyez(int ex, int ey)
{
    grabbed = false;
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
void Battleship::damage()
{

}

void Battleship::elhelyez(int ex, int ey)
{
    grabbed = false;
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
void AircraftCarrier::damage()
{

}

void AircraftCarrier::elhelyez(int ex, int ey)
{
    grabbed = false;
}
void AircraftCarrier::setxy(int kx, int ky)
{
    this->kx = kx;
    this->ky = ky;
    parts = 7;
}
