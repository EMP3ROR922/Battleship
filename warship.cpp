#include "graphics.hpp"
#include "warship.hpp"

using namespace genv;


Warship::Warship(int kx, int ky,int parts)
{
    this->kx = kx;
    this->ky = ky;
    this->parts = parts;
}


void Warship::damage()
{

}

Destroyer::Destroyer(int kx, int ky, int parts): Warship(kx, ky, 1){}

void Destroyer::rajzol()
{

    gout << move_to(kx-15,ky-15) << color(151,151,151) << box(30,30);
    gout << move_to(kx,ky) << color(0,0,0) << dot;
}
void Destroyer::damage()
{

}
void Destroyer::mozog()
{

}
void Destroyer::elhelyez()
{

}


Cruiser::Cruiser(int kx, int ky, int parts) : Warship(kx, ky, 3){}

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
void Cruiser::mozog()
{

}
void Cruiser::elhelyez()
{

}


Battleship::Battleship(int kx, int ky, int parts) : Warship(kx, ky, 5){}

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
void Battleship::mozog()
{

}
void Battleship::elhelyez()
{

}

AircraftCarrier::AircraftCarrier(int kx, int ky, int parts) : Warship(kx, ky, 7){}

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
void AircraftCarrier::mozog()
{

}
void AircraftCarrier::elhelyez()
{

}
