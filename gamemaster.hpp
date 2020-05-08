#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED

#ifndef GAMEMASTER_H_INCLUDED
#define GAMEMASTER_H_INCLUDED

#include<vector>
#include "map.hpp"

using namespace std;

typedef vector<vector<Sector>> palya;


class GameMaster
{
protected:
    int pont1, pont2 = 0;
public:
    GameMaster();

    virtual void startgame();
    virtual palya makemap();

};


#endif // GAMEMASTER_H_INCLUDED


#endif // GAMEMASTER_HPP_INCLUDED
