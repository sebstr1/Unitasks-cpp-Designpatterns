/*
   File:        Game.h
   Objective:	Designmönster DT063G - Abstract Factory
   Last change: feb 2014 / Orjan Sterner
*/


#ifndef GameH
#define GameH

#include <vector>
#include "Action.h"
#include "Obstacle.h"
#include "GameFactory.h"

using std::vector;

class Action;
class Obstacle;
class GameFactory;


class Game{
  private:
    string title;
    vector<Obstacle*> obstacles;  // Hinder som ska passeras i ett spel
    vector<Action*> actions;  // Möjliga 'actions' som spelaren kan göra
    Player* player;

  public:
    Game(GameFactory *gFact);  // gFact är ett konkret factory-objekt
    ~Game();
    void play(); //Play the game
};


#endif
