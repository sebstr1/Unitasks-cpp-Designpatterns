/*
   File:        Player.cpp
   Objective:	Designmönster DT063G - Abstract Factory
   Last change: feb 2014 / Orjan Sterner
*/
#include "Player.h"

using std::endl;

void Player::show(ostream &os) {
  os << "\nStatus health:" << health << " resources:" << resources;
  os << " ammo:" << ammo << endl;
}


