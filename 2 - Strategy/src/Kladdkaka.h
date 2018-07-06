/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef KladdkakaH
#define KladdkakaH

#include <iostream>
#include <string>
#include <vector>
#include "BakingRecepy.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Kladdkaka : public BakingRecepy
{

  private:
    string iName;

  public:
    // Add Ingredients needed for recepie.
    Kladdkaka() {
      neededIngredient.push_back(Ingredient("egg"));
      neededIngredient.push_back(Ingredient("sugar"));
      neededIngredient.push_back(Ingredient("baking-powder"));
      neededIngredient.push_back(Ingredient("wheat-flour"));
      neededIngredient.push_back(Ingredient("salt"));
      neededIngredient.push_back(Ingredient("marge"));  
      neededIngredient.push_back(Ingredient("cocoa-powder"));  
    }
    
    ~Kladdkaka() {}
    //Bake
    virtual void bakeIt() const { cout << "For the best Kladdkaka, just take egg, sugar, baking-powder, wheat-flour, salt and cocoa-powder and mix for days." << endl << endl; }
};

#endif