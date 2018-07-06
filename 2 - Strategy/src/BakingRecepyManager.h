/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef BakingRecepyManagerH
#define BakingRecepyManagerH

#include <string>
#include <iostream>
#include <fstream>

#include "Ingredient.h"
#include "BakingRecepy.h"

using std::string;
using std::ifstream;
using std::ofstream;

class BakingRecepyManager {

private:
  string pantryFile;
  vector<Ingredient> availableIngredients;
  vector<BakingRecepy *> Recepies;
public:
	BakingRecepyManager() {}
	~BakingRecepyManager() { 
		for(auto recepy : Recepies) {
			delete recepy;
		}		
	}

	BakingRecepyManager(string fileName);
	bool hasAnotherRecepy();

	void addRecepy(BakingRecepy *recepy) { Recepies.push_back(recepy); }
	// Return available ingredients vector
	vector<Ingredient> getIngredient() {return availableIngredients;}

	// BakingRecepy getNextBakingRecepy();
	BakingRecepy* getNextBakingRecepy();
};

#endif