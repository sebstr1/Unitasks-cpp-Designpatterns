/*
   File: Obstacle.h
   Objective:	Designmönster DT063G - Abstract Factory
   Last change: feb 2014 / Orjan Sterner
*/

#ifndef ObstacleH
#define ObstacleH

#include <string>
#include <iostream>
#include "Action.h"
#include "Player.h"

using std::string;
using std::ostream;

class Obstacle {
  private:
    string typeStr;
  protected:
    enum {ACTIONDELAY=2};
  public:
    Obstacle(string type):typeStr(type) { }
    virtual ~Obstacle()=default;
    const string& operator()(void) {return typeStr;}
    virtual void show(ostream &os=cout)=0;
    virtual bool tryToPass(Player*, Action*, ostream &os=cout)=0;
};

class Wall : public Obstacle {
  public:
    Wall():Obstacle("Wall") { }
    virtual bool tryToPass(Player*, Action*, ostream &os=cout);
    virtual void show(ostream &os=cout);
};


class Elephant : public Obstacle {
  public:
    Elephant():Obstacle("Elephant") { }
    virtual bool tryToPass(Player*, Action*, ostream &os=cout);
    virtual void show(ostream &os=cout);
};

class Wizard : public Obstacle {
  public:
    Wizard():Obstacle("Wizard") { }
    virtual bool tryToPass(Player*, Action*, ostream &os=cout);
    virtual void show(ostream &os=cout);
};

class Gangster : public Obstacle {
  public:
    Gangster():Obstacle("Gangster") { }
    virtual bool tryToPass(Player*, Action*, ostream &os=cout);
    virtual void show(ostream &os=cout);
};


class Dragon : public Obstacle {
  public:
    Dragon():Obstacle("Dragon") { }
    virtual bool tryToPass(Player*, Action*, ostream &os=cout);
    virtual void show(ostream &os=cout);
};


class Bomb : public Obstacle {
  public:
    Bomb():Obstacle("Bomb") { }
    virtual bool tryToPass(Player*, Action*, ostream &os=cout);
    virtual void show(ostream &os=cout);
};


class Samuray : public Obstacle {
  public:
    Samuray():Obstacle("Samuray") { }
    virtual bool tryToPass(Player*, Action*, ostream &os=cout);
    virtual void show(ostream &os=cout);
};


class SumoWrestler : public Obstacle {
  public:
    SumoWrestler():Obstacle("SumoWrestler") { }
    virtual bool tryToPass(Player*, Action*, ostream &os=cout);
    virtual void show(ostream &os=cout);
};

class DPexam : public Obstacle {
  public:
    DPexam():Obstacle("DPexam") { }
    virtual bool tryToPass(Player*, Action*, ostream &os=cout);
    virtual void show(ostream &os=cout);
};

#endif
