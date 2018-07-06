/*
   File:        Player.h
   Objective:	Designmönster DT063G - Abstract Factory
   Last change: feb 2014 / Orjan Sterner
*/

#ifndef PlayerH
#define PlayerH

#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::cout;

class Player {
  private:
    string typeStr;
    int resources, ammo, health;
  public:
    Player(string type, int r, int a, int h)
    : typeStr(type), resources(r), ammo(a), health(h) { }
    void decResources() { --resources; }
    void incResources() { ++resources; }
    int getResources() const { return resources; }
    void decAmmo() { --ammo; }
    int getAmmo() const { return ammo; }
    void decHealth() { --health; }
    int getHealth() const { return health; }
    void kill() { health=0; }
    bool alive() const { return health >0; }
    void show(ostream &os=cout);
};

class OrdinaryPlayer : public Player {
  public:
    OrdinaryPlayer( )
    :Player("OrdinaryPlayer",5,3,3) { }
};

class HeroPlayer : public Player {
  public:
    HeroPlayer( )
    :Player("HeroPlayer",7,5,5) { }
};

#endif
