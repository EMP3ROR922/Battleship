#include "gamemaster.hpp"
#include "map.hpp"
#include "warship.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;



GameMaster::GameMaster()
{

}


void GameMaster::startgame()
{
    event ev;
    palya p = GameMaster::makemap();
    AircraftCarrier cv(200,100,7);
    Destroyer dd(200, 150,1);
    Cruiser cc(200,250,3);
    Battleship bb(200,350,5);
    while(gin >> ev && ev.keycode != key_escape)
    {
        for(size_t i = 0; i < p.size();i++)
        {
            for(size_t j = 0; j < p[i].size();j++)
            {
                p[i][j].szinez(ev);
                p[i][j].rajzol();
            }
        }
        cv.rajzol();
        dd.rajzol();
        cc.rajzol();
        bb.rajzol();
        gout << refresh;
    }
}

palya GameMaster::makemap()
{
    vector<Sector> sect;
    palya terkep;
    for(int i = 1; i < 12;i++)
    {
        sect.clear();
        for(int j  = 1; j < 12;j++)
        {
            Sector s(j*30,i*30);
            sect.push_back(s);
        }
        terkep.push_back(sect);
    }

    return terkep;
}
