/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef IngredientH
#define IngredientH

#include <string>
#include <exception>
#include <stdexcept>

using std::string;

class Ingredient
{
  private:
		string iName;

  public:
		Ingredient(string aName) : iName(aName) {}
		~Ingredient() {}
		string getName() const { return iName; }
		operator string() const { return iName; }
		bool operator==(const Ingredient &rhs) const { return iName == rhs.iName; }

};

#endif