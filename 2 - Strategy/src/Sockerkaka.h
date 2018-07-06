/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef SockerkakaH
#define SockerkakaH

#include <iostream>
#include <string>
#include <vector>
#include "BakingRecepy.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Sockerkaka : public BakingRecepy
{

private:
  string iName;

public:
  // Add Ingredients needed for recepie.
  Sockerkaka()
  {
    neededIngredient.push_back(Ingredient("egg"));
    neededIngredient.push_back(Ingredient("sugar"));
    neededIngredient.push_back(Ingredient("baking-powder"));
    neededIngredient.push_back(Ingredient("wheat-flour"));
    neededIngredient.push_back(Ingredient("marge"));
    neededIngredient.push_back(Ingredient("lemon"));
  }
  ~Sockerkaka() {}
  //Bake
  virtual void bakeIt() const { cout << "For amazing Sockerkaka, take 4 eggs, sugar, baking-powder, wheat-flour, marge and lemon. Destroy themarge with your fists until it looks good." << endl << endl; }
};

#endif