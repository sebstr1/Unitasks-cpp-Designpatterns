/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef BakeryH
#define BakeryH

#include <exception>
#include "NoBakingException.h"
#include "BakingRecepyManager.h"

using std::cout;
using std::string;


class Bakery {

    private:
        BakingRecepyManager manager;

    public:
        Bakery(string pantryPath) : manager(pantryPath) {}
        void addRecepy(BakingRecepy *recepy) { manager.addRecepy(recepy); }
        void runBakery();
};


void Bakery::runBakery() {
    
    try
    {
        BakingRecepy *recepy;

        // While BakingRecepyManager has Recepies
        while (recepy = manager.getNextBakingRecepy())   {
            if (recepy->isBakeable(manager.getIngredient())) recepy->bakeIt(); // If all requiered ingredients are available, bake it.
            delete recepy; // Delete pointer
        }
    }
    // Catch custom exception
    catch (const NoBakingException &e) {
        cout << e.what() << endl;
    }
    // Catch other stuff
    catch (const exception &e)  {
        cout << e.what() << endl;
    }
}

#endif