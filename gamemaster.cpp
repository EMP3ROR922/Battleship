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
    ships[0]->setxy(200,50);
    ships.push_back(new Destroyer);
    ships[1]->setxy(200,100);
    ships.push_back(new Cruiser);
    ships[2]->setxy(200,150);
    ships.push_back(new Cruiser);
    ships[3]->setxy(200,200);
    ships.push_back(new Battleship);
    ships[4]->setxy(200,250);
    ships.push_back(new AircraftCarrier);
    ships[5]->setxy(200,350);

    return ships;
}


void GameMaster::startgame()
{
    gout.open(400,400);
    event ev;
    palya p = GameMaster::makemap();
    palya p2 = GameMaster::makemap();
    vector<Warship*> ships = makeships();
    vector<Warship*> ships2 = makeships();
    int playerstart = 1;
    int playerturn = 1;
    while(gin >> ev && ev.keycode != key_escape)
    {

        switch(playerstart)
        {
            case 1:
                    for(size_t i = 0; i < p.size();i++)
                    {
                        for(size_t j = 0; j < p[i].size();j++)
                        {
                            p[i][j].rajzol();
                        }
                    }

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
                        switch(ships[i]->returntype())
                        {
                        case 1:
                            if(ships[i]->elhelyez(ev.pos_x,ev.pos_y))
                            {
                                for(size_t k = 0; k < p.size();k++)
                                {
                                    for(size_t l = 0; l < p[k].size();l++)
                                    {
                                        p[k][l].setshipsstatus(ships[i]->getkx(),ships[i]->getky());
                                    }
                                }
                                ships.erase(ships.begin()+i);
                            }
                            break;
                        case 3:
                            if(ships[i]->elhelyez(ev.pos_x,ev.pos_y))
                            {
                                for(size_t k = 0; k < p.size();k++)
                                {
                                    for(size_t l = 0; l < p[k].size();l++)
                                    {


                                            p[k][l].setshipsstatus(ships[i]->getkx(),ships[i]->getky());
                                            p[k][l].setshipsstatus(ships[i]->getkx()+30,ships[i]->getky());
                                            p[k][l].setshipsstatus(ships[i]->getkx()-30,ships[i]->getky());

                                    }
                                }
                                ships.erase(ships.begin()+i);
                            }



                            break;
                        case 5:
                            if(ships[i]->elhelyez(ev.pos_x,ev.pos_y))
                            {
                                for(size_t k = 0; k < p.size();k++)
                                {
                                    for(size_t l = 0; l < p[k].size();l++)
                                    {
                                        p[k][l].setshipsstatus(ships[i]->getkx(),ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()+30,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()+60,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()-30,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()-60,ships[i]->getky());
                                    }
                                }
                                ships.erase(ships.begin()+i);
                            }

                            break;
                        case 7:
                            if(ships[i]->elhelyez(ev.pos_x,ev.pos_y))
                            {
                                for(size_t k = 0; k < p.size();k++)
                                {
                                    for(size_t l = 0; l < p[k].size();l++)
                                    {
                                        p[k][l].setshipsstatus(ships[i]->getkx(),ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()+30,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()+60,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()+90,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()-30,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()-60,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()-90,ships[i]->getky());
                                    }
                                }
                                ships.erase(ships.begin()+i);
                            }

                            break;
                        }



                    }
                    ships[i]->rajzol();

                    }
                    if(ev.keycode == key_enter)
                    {
                        ships.clear();
                        playerstart++;
                    }
                break;
            case 2:
                    for(size_t i = 0; i < p2.size();i++)
                    {
                        for(size_t j = 0; j < p2[i].size();j++)
                        {
                            p2[i][j].rajzol();
                        }
                    }
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
                        switch(ships2[i]->returntype())
                        {
                        case 1:
                            if(ships2[i]->elhelyez(ev.pos_x,ev.pos_y))
                            {
                                for(size_t k = 0; k < p2.size();k++)
                                {
                                    for(size_t l = 0; l < p2[k].size();l++)
                                    {
                                        p2[k][l].setshipsstatus(ships2[i]->getkx(),ships2[i]->getky());
                                    }
                                }
                                ships2.erase(ships2.begin()+i);
                            }
                            break;
                        case 3:
                            if(ships2[i]->elhelyez(ev.pos_x,ev.pos_y))
                            {
                                for(size_t k = 0; k < p.size();k++)
                                {
                                    for(size_t l = 0; l < p[k].size();l++)
                                    {


                                            p2[k][l].setshipsstatus(ships2[i]->getkx(),ships2[i]->getky());
                                            p2[k][l].setshipsstatus(ships2[i]->getkx()+30,ships2[i]->getky());
                                            p2[k][l].setshipsstatus(ships2[i]->getkx()-30,ships[i]->getky());

                                    }
                                }
                                ships2.erase(ships2.begin()+i);
                            }



                            break;
                        case 5:
                            if(ships2[i]->elhelyez(ev.pos_x,ev.pos_y))
                            {
                                for(size_t k = 0; k < p.size();k++)
                                {
                                    for(size_t l = 0; l < p[k].size();l++)
                                    {
                                        p2[k][l].setshipsstatus(ships2[i]->getkx(),ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()+30,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()+60,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()-30,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()-60,ships2[i]->getky());
                                    }
                                }
                                ships2.erase(ships2.begin()+i);
                            }

                            break;
                        case 7:
                            if(ships2[i]->elhelyez(ev.pos_x,ev.pos_y))
                            {
                                for(size_t k = 0; k < p.size();k++)
                                {
                                    for(size_t l = 0; l < p[k].size();l++)
                                    {
                                        p2[k][l].setshipsstatus(ships2[i]->getkx(),ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()+30,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()+60,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()+90,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()-30,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()-60,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()-90,ships2[i]->getky());
                                    }
                                }
                                ships2.erase(ships2.begin()+i);
                            }
                            break;
                        }

                        }
                            ships2[i]->rajzol();
                    }



                    if(ev.keycode == key_enter)
                    {
                        ships2.clear();
                        playerstart++;
                        game_started = true;
                    }
                break;
            default:
                break;
        }






        if(game_started)
        {
            switch(playerturn)
            {
                case 1:
                    break;
                case 2:
                    break;
                default:
                    break;
            }
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
