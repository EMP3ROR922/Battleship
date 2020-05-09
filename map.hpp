#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED
#include "graphics.hpp"
#include "ocean.hpp"

using namespace genv;


class Sector : public Ocean
{
protected:
    int r,g,b;
    bool ship_present = false;
public:
    Sector(int x, int y);

    virtual void szinez(genv::event ev);
    virtual void rajzol();
    void setshipsstatus(int shipx,int shipy);

};


#endif // MAP_HPP_INCLUDED
