/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef RaceCarH
#define RaceCarH

#include <iostream>
#include <string>
#include "Vehicle.h"
#include <memory>


using std::string;
using std::unique_ptr;
using std::cout;
using std::endl;

class RaceCar : public Vehicle
{

public:
  RaceCar() : Vehicle("Race Car", unique_ptr<PowerSource>(new V8ClassicAD())) {}

  ~RaceCar() {}

  virtual void drive();           // Simulate a driving scenario

  //Operations for steering
  virtual void steerLeft(int degrees);
  virtual void steerRight(int degrees);

};

void RaceCar::drive() {
  incPower(70);
  cout << "WOW MAX SPEED!!!" << endl;
  steerLeft(30);
  steerRight(360);
  cout << "DONUT! while Max speed? WOW" << endl;
  decPower(40);
}
void RaceCar::steerLeft(int degrees) {
  cout << "STEER LEFT " + std::to_string(degrees) + " degrees" << endl;
}
void RaceCar::steerRight(int degrees) {
  cout << "STEER RIGHT " + std::to_string(degrees) + " degrees" << endl;
}

#endif
