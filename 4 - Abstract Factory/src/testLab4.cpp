/*
   File:        testLab4.cpp
   Objective:	Designm�nster DT063G - Abstract Factory
   Last change: feb 2014 / Orjan Sterner
*/

#include <vector>
#include <iostream>
#include <cstdlib>
#include "Game.h"
#include "GameFactory.h"

#include "C:\Dev\Tools\include\memstat.hpp"

using std::cin;

int main() {

    int choice;
    bool keepOn = true;


    while(keepOn) {
        GameFactory *gf = nullptr;
        cout << "Choose your game:" << endl;
        cout << "1 - Nice game" << endl;
        cout << "2 - Nasty game" << endl;
        cout << "3 - quit" << endl;

        while(!(cin >> choice) || choice <1 || choice >3) {
          cin.clear();
          cin.ignore(cin.rdbuf()->in_avail());
        }

        switch(choice) {
          case 1:  gf = new NiceGameFactory(); break;
          case 2:  gf = new NastyGameFactory(); break;
          case 3: keepOn=false;
        }

        if(keepOn) {
          Game game(gf);
          game.play();
          delete gf;
        }
    } // while

    return 0;
}


