/*
   File:        GameFactory.h
   Objective:	Designm�nster DT063G - Abstract Factory
   Last change: feb 2014 / Orjan Sterner
*/


#ifndef GameFactoryH
#define GameFactoryH

#include <vector>
#include <string>

using std::vector;
using std::string;

class Player;
class Obstacle;
class Action;


// GameFactory �r en abstrakt klass som definierar ett interface f�r
// deriverade konkreta klasser

class GameFactory {
protected:
  GameFactory() { }

public:
	virtual ~GameFactory() = default;
   // Lämpliga operationer: se klassen Game.
   virtual vector<Obstacle*> makeObstacles() = 0;
   virtual vector<Action*> makeActions() = 0;
   virtual Player* makePlayer() = 0;
   virtual string setGameTitle() = 0;
   
};


 

class NiceGameFactory : public GameFactory {
    public: 
        NiceGameFactory() {}
        ~NiceGameFactory() {}
        virtual vector<Obstacle*> makeObstacles();
        virtual vector<Action*> makeActions();
        virtual Player* makePlayer();
        virtual string setGameTitle();

};

class NastyGameFactory : public GameFactory {
    public: 
        NastyGameFactory() {}
        ~NastyGameFactory() {}
        virtual vector<Obstacle*> makeObstacles();
        virtual vector<Action*> makeActions();
        virtual Player* makePlayer();
        virtual string setGameTitle();
};


#endif
