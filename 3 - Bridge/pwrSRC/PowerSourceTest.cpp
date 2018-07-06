/*
   File: PowerSourceTest.cpp
   Demo of DP Adapter. Threee different and originally incompatible classes are adapted
   to the PowerSource interface and used uniformly in a short scenario.
   2016/ Orjan Sterner
*/

#include <vector>
#include <iostream>
//#include <memstat.h>
#include <memory>
#include "PowerSourceAdapters.h"

using namespace std;

class PowerSourceTest {

public:
    PowerSourceTest() {

        psVec.emplace_back(new V8ClassicAD);
        psVec.emplace_back(new GasTurbineAD);
        psVec.emplace_back(new FuelCellAD);
    }

    void run() {
        vector<std::unique_ptr<PowerSource>>::iterator it;
        for(it=psVec.begin(); it!=psVec.end(); ++it) {
            cout <<'\n' << (*it)->type() << endl;
            (*it)->setPower(35);
            (*it)->tryStart();
            if((*it)->isRunning()) {
                (*it)->incPower(35);
                (*it)->decPower(35);
                (*it)->stop();
            }
            else
              cerr << "Did not start." << endl;
        }
    }

private:
    vector<std::unique_ptr<PowerSource>> psVec;

};

int main() {

    PowerSourceTest test;
    test.run();
    return 0;
}
