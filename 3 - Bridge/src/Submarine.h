/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef SubmarineH
#define SubmarineH

#include <iostream>
#include <string>
#include "Vehicle.h"
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;

class Submarine : public Vehicle
{

public:

  Submarine() : Vehicle("Submarine", unique_ptr<PowerSource>(new FuelCellAD())) {}
  ~Submarine() {}

  virtual void drive(); // Simulate a driving scenario

  //Operations for steering
  virtual void steerLeft(int degrees);
  virtual void steerRight(int degrees);
};

void Submarine::drive()
{
  incPower(70);
  cout << "WOW MAX SPEED!!!" << endl;
  steerLeft(30);
  steerRight(360);
  cout << "360 with a submarine woho!" << endl;
  decPower(40);
}
void Submarine::steerLeft(int degrees)
{
  cout << "STEER LEFT " + std::to_string(degrees) + " degrees" << endl;
}
void Submarine::steerRight(int degrees)
{
  cout << "STEER RIGHT " + std::to_string(degrees) + " degrees" << endl;
}

#endif
