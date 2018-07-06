/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef SpaceShipH
#define SpaceShipH

#include <iostream>
#include <string>
#include "Vehicle.h"
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;

class SpaceShip : public Vehicle
{

  public:

    SpaceShip() : Vehicle("Space Ship", unique_ptr<PowerSource>(new GasTurbineAD())) {}

    ~SpaceShip() {}

    virtual void drive(); // Simulate a driving scenario

    //Operations for steering
    virtual void steerLeft(int degrees);
    virtual void steerRight(int degrees);
};

void SpaceShip::drive()
{
  incPower(70);
  cout << "We reached Mars!" << endl;
  steerLeft(30);
  steerRight(360);
  cout << "360 BarrelRoll midSpace" << endl;
  decPower(40);
}
void SpaceShip::steerLeft(int degrees)
{
  cout << "STEER LEFT " + std::to_string(degrees) + " degrees" << endl;
}
void SpaceShip::steerRight(int degrees)
{
  cout << "STEER RIGHT " + std::to_string(degrees) + " degrees" << endl;
}

#endif
