/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef PizzaH
#define PizzaH

#include <iostream>
#include <string>
#include <vector>
#include "BakingRecepy.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Pizza : public BakingRecepy
{

public:
  // Add Ingredients needed for recepie.
  Pizza()
  {
    neededIngredient.push_back(Ingredient("oil"));
    neededIngredient.push_back(Ingredient("yeast"));
    neededIngredient.push_back(Ingredient("wheat-flour"));
    neededIngredient.push_back(Ingredient("salt"));
  }

  ~Pizza() {}

  // Bake
  virtual void bakeIt() const { cout << "For the best pizza, take 2L oil and mix with yeast, wheat-flour and salt. \n Put in oven for 1 hour at 250C" << endl << endl; }
};

#endif
