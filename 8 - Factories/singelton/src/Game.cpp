/*
   File:        Game.cpp
   Objective:	Designm�nster DT063G - Abstract Factory
   Last change: feb 2014 / Orjan Sterner
*/


#include <iostream>
#include "Game.h"

using std::cin;

template<typename T>
void destroyVectorElements(vector<T> &vec);


Game::Game(GameFactory *gFact) {

  
  // gFact pekar p� ett konkret Factory-objekt som h�r ska utf�ra operationerna


  // makeObstacles:
  // - fylla upp obstacles med pekare till de Obstacle-objekt som spelet best�r av
  obstacles = gFact->makeObstacles();
  
  // makeActions:
  // - fylla upp actions med pekare till de Action-objekt som spelaren kan v�lja mellan
  actions = gFact->makeActions();

  //   makePlayer:
  // - tilldela player en pekare till ett konkret Player-objekt
   player = gFact->makePlayer();

  // setGameTitle:
  // - ge title ett passande v�rde
  title = gFact->setGameTitle();


}

Game::~Game() {
  destroyVectorElements(obstacles);
  destroyVectorElements(actions);
  delete player;
}


void Game::play( ) {

  cout << "*** Welcome to " << title << " ***" << endl;

  typedef std::vector<Action*>::iterator AtypeIt;
  typedef std::vector<Obstacle*>::iterator OtypeIt;

  AtypeIt aStart=actions.begin(), aStop=actions.end(), ait;
  OtypeIt oStart=obstacles.begin(), oStop=obstacles.end(), oit;

  for(oit=oStart; oit!=oStop&& player->alive(); ++oit) {

    int alt, choice;
    bool passed = false;

    while(!passed && player->alive()) {
      (*oit)-> show();
      cout <<"\nChoose action:\n";

      for(alt=1, ait=aStart; ait!=aStop&& player->alive();++alt,++ait)
        cout << "\t " << alt << ' '<< (*ait)->show();

      while(!(cin >> choice) || choice <1 || choice >=alt) {
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
      }

      passed = (*oit)->tryToPass(player,actions[choice-1]);
      player->show();
    }   // while
  }
  if(player->alive())
      cout << "\nYou Win!" << endl;
  else
      cout << "\nYou Lose!" << endl;
  cin.ignore(cin.rdbuf()->in_avail());
}


template<typename T>
void destroyVectorElements(vector<T> &vec) {
  for(auto element : vec)
  {
    delete element;
  }
}

