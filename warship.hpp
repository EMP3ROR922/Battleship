#ifndef WARSHIP_HPP_INCLUDED
#define WARSHIP_HPP_INCLUDED


class Warship
{
protected:
    int kx, ky, ox, oy, kattx,katty;
    int parts;
    int hits = 0;
    bool destroyed = false;
    bool grabbed = false;
public:
    Warship();


    virtual void damage();
    virtual bool getgrabbed();
    virtual void grab(int ex, int ey);
    virtual void mozog(int ex, int ey);
    virtual void rajzol();
    virtual bool elhelyez(int ex, int ey);
    virtual void setxy(int kx, int ky);
    int getkx();
    int getky();
    int returntype();

};


class Destroyer : public Warship
{
protected:

public:

    void setxy(int kx, int ky);
    void rajzol();
    void damage();
    void mozog(int ex, int ey);
    bool elhelyez(int ex, int ey);

};

class Cruiser : public Warship
{
protected:
public:

    void setxy(int kx, int ky);
    void rajzol();
    void damage();
    void mozog(int ex, int ey);
    bool elhelyez(int ex, int ey);
};

class Battleship : public Warship
{
protected:
public:


    void setxy(int kx, int ky);
    void rajzol();
    void damage();
    void mozog(int ex, int ey);
    bool elhelyez(int ex, int ey);
};

class AircraftCarrier : public Warship
{
protected:
public:


    void setxy(int kx, int ky);
    void rajzol();
    void damage();
    void mozog(int ex, int ey);
    bool elhelyez(int ex, int ey);
};


#endif // WARSHIP_HPP_INCLUDED
