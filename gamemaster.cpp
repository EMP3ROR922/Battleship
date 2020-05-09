#include "gamemaster.hpp"
#include "map.hpp"
#include "warship.hpp"
#include "graphics.hpp"
#include<iostream>
#include<memory>

using namespace genv;
using namespace std;

bool game_started = false;

GameMaster::GameMaster()
{

}

vector<Warship*> makeships()
{
    vector<Warship*> ships;
    ships.push_back(new Destroyer);
    ships[0]->setxy(200,100);
    ships.push_back(new Cruiser);
    ships[1]->setxy(200,150);
    ships.push_back(new Battleship);
    ships[2]->setxy(200,250);
    ships.push_back(new AircraftCarrier);
    ships[3]->setxy(200,350);

    return ships;
}


void GameMaster::startgame()
{
    event ev;
    palya p = GameMaster::makemap();
    vector<Warship*> ships = makeships();
    vector<Warship*> ships2 = makeships();
    int playerstart = 1;
    while(gin >> ev && ev.keycode != key_escape)
    {
        for(size_t i = 0; i < p.size();i++)
        {
            for(size_t j = 0; j < p[i].size();j++)
            {
                p[i][j].rajzol();
            }
        }
        switch(playerstart)
        {
            case 1:

                    for(size_t i = 0; i < ships.size();i++)
                    {
                        if(ev.type == ev_mouse && ev.button == btn_left)
                    {
                        ships[i]->grab(ev.pos_x,ev.pos_y);

                    }
                    if(ev.type == ev_mouse && ships[i]->getgrabbed())
                    {
                        ships[i]->mozog(ev.pos_x,ev.pos_y);

                    }
                    if(ev.button == btn_right)
                    {
                        ships[i]->elhelyez(ev.pos_x,ev.pos_y);
                    }
                    ships[i]->rajzol();

                    }
                    if(ev.keycode == key_enter)
                    {
                        playerstart++;
                    }
                break;
            case 2:
                    for(size_t i = 0; i < ships2.size();i++)
                    {
                        if(ev.type == ev_mouse && ev.button == btn_left)
                    {
                        ships2[i]->grab(ev.pos_x,ev.pos_y);

                    }
                    if(ev.type == ev_mouse && ships2[i]->getgrabbed())
                    {
                        ships2[i]->mozog(ev.pos_x,ev.pos_y);

                    }
                    if(ev.button == btn_right)
                    {
                        ships2[i]->elhelyez(ev.pos_x,ev.pos_y);
                    }
                    ships2[i]->rajzol();

                    }
                    if(ev.keycode == key_enter)
                    {
                        playerstart++;
                    }
                break;
            default:
                break;
        }






        if(game_started)
        {

        }


        gout << refresh;
        gout << move_to(0,0) << color(0,0,0) << box_to(399,399);
    }
}

palya GameMaster::makemap()
{
    vector<Sector> sect;
    palya terkep;
    for(int i = 1; i <= 11;i++)
    {
        sect.clear();
        for(int j  = 1; j <= 11;j++)
        {
            Sector s(j*30,i*30);
            sect.push_back(s);
        }
        terkep.push_back(sect);
    }

    return terkep;
}
