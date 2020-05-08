#include "gamemaster.hpp"
#include "map.hpp"
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
        gout << refresh;
    }
}

palya GameMaster::makemap()
{
    vector<Sector> sect;
    palya terkep;
    for(int i = 1; i < 11;i++)
    {
        sect.clear();
        for(int j  = 1; j < 11;j++)
        {
            Sector s(j*30,i*30);
            sect.push_back(s);
        }
        terkep.push_back(sect);
    }

    return terkep;
}
