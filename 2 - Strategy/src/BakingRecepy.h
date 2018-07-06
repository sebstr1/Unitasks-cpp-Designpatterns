/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef BakingRecepyH
#define BakingRecepyH

#include <iostream>
#include <string>
#include <vector>
#include "Ingredient.h"
#include <algorithm>

using std::string;
using std::vector;

class BakingRecepy {
	protected:
		string iName;
		vector<Ingredient> neededIngredient;

	public:

		BakingRecepy() {}
		BakingRecepy(string aName) { iName = aName; }
		virtual ~BakingRecepy() {}

		virtual void bakeIt() const = 0;

		// Checks if the ingredients needed for recepie is in stock (pantry)
		bool isBakeable(vector<Ingredient> &availableIngredients) {
			// Loop thru all
			for (auto needed : neededIngredient)
			{
				//If ingredient not in needed ingredients, return false
				if (std::find(availableIngredients.begin(), availableIngredients.end(), needed) == availableIngredients.end())
				{
					return false;
				}
			}
			// All ingredients existed
			return true;
		} 
};

#endif