#include "gamemaster.hpp"
#include "map.hpp"
#include "warship.hpp"
#include "graphics.hpp"
#include<iostream>
#include<memory>
#include<sstream>

using namespace genv;
using namespace std;

bool game_started = false;
bool game_over = false;
bool first_time = true;
int click = 0;
pair<int,int> shippos;
int ct,ct2 = 0;

GameMaster::GameMaster()
{

}

vector<Warship*> makeships()
{
    vector<Warship*> ships;
    ships.push_back(new Destroyer);
    ships[0]->setxy(200,50);
    /*ships.push_back(new Destroyer);
    ships[1]->setxy(200,100);
    ships.push_back(new Cruiser);
    ships[2]->setxy(200,150);
    ships.push_back(new Cruiser);
    ships[3]->setxy(200,200);
    ships.push_back(new Battleship);
    ships[4]->setxy(200,250);
    ships.push_back(new AircraftCarrier);
    ships[5]->setxy(200,350);*/

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
                                        shippos = p[k][l].setshipsstatus(ships[i]->getkx(),ships[i]->getky());
                                        if(shippos.first > 0 && shippos.second > 0 )
                                        {
                                            ships[i]->setxy(shippos.first,shippos.second);
                                            ct++;

                                        }
                                    }
                                }



                            }
                            break;
                        case 3:
                            if(ships[i]->elhelyez(ev.pos_x,ev.pos_y))
                            {
                                for(size_t k = 0; k < p.size();k++)
                                {
                                    for(size_t l = 0; l < p[k].size();l++)
                                    {


                                            shippos = p[k][l].setshipsstatus(ships[i]->getkx(),ships[i]->getky());
                                            p[k][l].setshipsstatus(ships[i]->getkx()+30,ships[i]->getky());
                                            p[k][l].setshipsstatus(ships[i]->getkx()-30,ships[i]->getky());

                                            if(shippos.first > 0 && shippos.second > 0 )
                                            {
                                                ships[i]->setxy(shippos.first,shippos.second);
                                                ct++;

                                            }

                                    }
                                }

                            }



                            break;
                        case 5:
                            if(ships[i]->elhelyez(ev.pos_x,ev.pos_y))
                            {
                                for(size_t k = 0; k < p.size();k++)
                                {
                                    for(size_t l = 0; l < p[k].size();l++)
                                    {
                                        shippos = p[k][l].setshipsstatus(ships[i]->getkx(),ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()+30,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()+60,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()-30,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()-60,ships[i]->getky());

                                        if(shippos.first > 0 && shippos.second > 0 )
                                        {
                                            ships[i]->setxy(shippos.first,shippos.second);
                                            ct++;

                                        }
                                    }
                                }

                            }

                            break;
                        case 7:
                            if(ships[i]->elhelyez(ev.pos_x,ev.pos_y))
                            {
                                for(size_t k = 0; k < p.size();k++)
                                {
                                    for(size_t l = 0; l < p[k].size();l++)
                                    {
                                        shippos = p[k][l].setshipsstatus(ships[i]->getkx(),ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()+30,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()+60,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()+90,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()-30,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()-60,ships[i]->getky());
                                        p[k][l].setshipsstatus(ships[i]->getkx()-90,ships[i]->getky());

                                        if(shippos.first > 0 && shippos.second > 0 )
                                        {
                                            ships[i]->setxy(shippos.first,shippos.second);
                                            ct++;

                                        }
                                    }
                                }

                            }

                            break;
                        }



                    }
                    ships[i]->rajzol();

                    }
                    if(ev.keycode == key_enter && ships.size() == size_t(ct))
                    {

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
                                        shippos = p2[k][l].setshipsstatus(ships2[i]->getkx(),ships2[i]->getky());

                                        if(shippos.first > 0 && shippos.second > 0 )
                                        {
                                            ships2[i]->setxy(shippos.first,shippos.second);
                                            ct2++;

                                        }
                                    }
                                }

                            }
                            break;
                        case 3:
                            if(ships2[i]->elhelyez(ev.pos_x,ev.pos_y))
                            {
                                for(size_t k = 0; k < p.size();k++)
                                {
                                    for(size_t l = 0; l < p[k].size();l++)
                                    {


                                            shippos = p2[k][l].setshipsstatus(ships2[i]->getkx(),ships2[i]->getky());
                                            p2[k][l].setshipsstatus(ships2[i]->getkx()+30,ships2[i]->getky());
                                            p2[k][l].setshipsstatus(ships2[i]->getkx()-30,ships2[i]->getky());

                                            if(shippos.first > 0 && shippos.second > 0 )
                                            {
                                            ships2[i]->setxy(shippos.first,shippos.second);
                                            ct2++;

                                            }

                                    }
                                }

                            }



                            break;
                        case 5:
                            if(ships2[i]->elhelyez(ev.pos_x,ev.pos_y))
                            {
                                for(size_t k = 0; k < p.size();k++)
                                {
                                    for(size_t l = 0; l < p[k].size();l++)
                                    {
                                        shippos = p2[k][l].setshipsstatus(ships2[i]->getkx(),ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()+30,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()+60,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()-30,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()-60,ships2[i]->getky());

                                        if(shippos.first > 0 && shippos.second > 0 )
                                        {
                                            ships2[i]->setxy(shippos.first,shippos.second);
                                            ct2++;

                                        }
                                    }
                                }

                            }

                            break;
                        case 7:
                            if(ships2[i]->elhelyez(ev.pos_x,ev.pos_y))
                            {
                                for(size_t k = 0; k < p.size();k++)
                                {
                                    for(size_t l = 0; l < p[k].size();l++)
                                    {
                                        shippos = p2[k][l].setshipsstatus(ships2[i]->getkx(),ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()+30,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()+60,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()+90,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()-30,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()-60,ships2[i]->getky());
                                        p2[k][l].setshipsstatus(ships2[i]->getkx()-90,ships2[i]->getky());

                                        if(shippos.first > 0 && shippos.second > 0 )
                                        {
                                            ships2[i]->setxy(shippos.first,shippos.second);
                                            ct2++;

                                        }
                                    }
                                }

                            }
                            break;
                        }

                        }
                            ships2[i]->rajzol();
                    }



                    if(ev.keycode == key_enter && ships2.size() == size_t(ct2))
                    {

                        playerstart++;
                        game_started = true;
                    }
                break;
            default:
                break;
        }






        if(game_started)
        {
            if(first_time)
            {
                gout << move_to(200,20) << text("Battle starts!") << refresh;

            }
            stringstream s;
            s <<"Player " << playerturn << "'s turn, press Enter when ready";

            switch(playerturn)
            {

                case 1:

                        gout << move_to(20,20) << color(255,255,255) << text(s.str());
                        gout << move_to(20,379) << text("You MUST click on a sector first");
                        for(size_t i = 0; i < p2.size();i++)
                        {
                            for(size_t j = 0; j < p2[i].size();j++)
                            {
                                p2[i][j].rajzol_game();
                            }
                        }
                    if(ev.button == btn_left)
                    {
                        if(click % 2 == 0)
                        {
                            for(size_t i = 0; i < p2.size();i++)
                            {
                            for(size_t j = 0; j < p2[i].size();j++)
                            {
                                p2[i][j].szinez(ev);
                                for(size_t k = 0; k < ships2.size();k++)
                                {
                                    ships2[k]->damage(ev.pos_x,ev.pos_y);
                                }
                            }
                            }
                            click++;
                        }

                    }else
                    {
                        if(ev.keycode == key_enter && click % 2 == 1 && !game_over)
                        {
                            playerturn++;

                        }
                        if(ev.keycode == key_enter && click % 2 == 0)
                        {
                            gout << move_to(100,369) << text("Make your move first!") << refresh;
                        }
                    }



                    break;
                case 2:

                    gout << move_to(20,20) << color(255,255,255) << text(s.str());
                    gout << move_to(20,379) << text("You MUST click on a sector first");
                    for(size_t i = 0; i < p.size();i++)
                        {
                            for(size_t j = 0; j < p[i].size();j++)
                            {
                                p[i][j].rajzol_game();
                            }
                        }
                    if(ev.button == btn_left)
                    {
                        if(click % 2 == 1)
                        {
                            for(size_t i = 0; i < p.size();i++)
                            {
                            for(size_t j = 0; j < p[i].size();j++)
                            {
                                p[i][j].szinez(ev);
                            }
                            }
                            click--;
                        }

                    }else
                    {
                        if(ev.keycode == key_enter && click % 2 == 0 && !game_over)
                        {
                            playerturn--;
                            first_time = false;
                        }
                        if(ev.keycode == key_enter && click % 2 == 1)
                        {
                            gout << move_to(200,369) << text("Make your move first!") << refresh;
                        }
                    }
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
