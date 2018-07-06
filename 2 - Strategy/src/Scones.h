/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef SconesH
#define SconesH

#include <iostream>
#include <string>
#include <vector>
#include "BakingRecepy.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Scones : public BakingRecepy
{
  public:

    // Add Ingredients needed for recepie.
    Scones()
    {
      neededIngredient.push_back(Ingredient("oil"));
      neededIngredient.push_back(Ingredient("baking-powder"));
      neededIngredient.push_back(Ingredient("wheat-flour"));
      neededIngredient.push_back(Ingredient("salt"));
      neededIngredient.push_back(Ingredient("sugar"));
      neededIngredient.push_back(Ingredient("milk"));
    }
    ~Scones() {}

    // Bake
    virtual void bakeIt() const { cout << "For amazing Scones, take huge amounts sugar and then mix with sugar, milk, salt, oil and wheat-flour. Put in oven at 225C for 6 hours." << endl << endl; }
};

#endif