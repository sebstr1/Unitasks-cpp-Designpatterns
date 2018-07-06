/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#include <exception>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <string>
#include "Pizza.h"
#include "Scones.h"
#include "Kladdkaka.h"
#include "Sockerkaka.h"
#include "Ingredient.h"
#include "BakingRecepyManager.h"
#include "NoBakingException.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;


// Constructor
BakingRecepyManager::BakingRecepyManager(string fileName) {

    // Open file and read lines until end of file
    string line;
    ifstream inFile("src/" + fileName);
    if (inFile.is_open())
    {
        if (inFile.eof()) {
            cout << "Empty file" << endl;
        }
        else {
            while (getline(inFile, line))
            {
                availableIngredients.push_back(Ingredient(line));
            }
            inFile.close();
        }
    }
    else {
        cout << "File with filename " << fileName << " does not exist!" << endl;
    }

}

// Checks if we have more recepies
BakingRecepy* BakingRecepyManager::getNextBakingRecepy() {

    // If true return recepie
    if(hasAnotherRecepy()) { 
        BakingRecepy *recept = Recepies[Recepies.size()-1];
        Recepies.pop_back();
        return recept;
    // Throw Special exception
    } else {
        NoBakingException myException;
        throw myException;
    }

}

// Check if recepies vector has recepies
bool BakingRecepyManager::hasAnotherRecepy() {

    if (Recepies.empty()) {
        return false;
    } else {
        return true;
    }
}