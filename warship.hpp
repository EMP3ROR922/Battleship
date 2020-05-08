#ifndef WARSHIP_HPP_INCLUDED
#define WARSHIP_HPP_INCLUDED


class Warship
{
public:
    int kx, ky, ox, oy;
    int parts;
    bool destroyed = false;
protected:
    Warship(int kx, int ky, int parts);


    virtual void damage();



};


class Destroyer : public Warship
{
protected:

public:
    Destroyer(int kx, int ky, int parts);

    void rajzol();
    void damage();
    void mozog();
    void elhelyez();
};

class Cruiser : public Warship
{
protected:
public:

    Cruiser(int kx, int ky, int parts);

    void rajzol();
    void damage();
    void mozog();
    void elhelyez();
};

class Battleship : public Warship
{
protected:
public:

    Battleship(int kx, int ky, int parts);

    void rajzol();
    void damage();
    void mozog();
    void elhelyez();
};

class AircraftCarrier : public Warship
{
protected:
public:

    AircraftCarrier(int kx, int ky, int parts);

    void rajzol();
    void damage();
    void mozog();
    void elhelyez();
};


#endif // WARSHIP_HPP_INCLUDED
