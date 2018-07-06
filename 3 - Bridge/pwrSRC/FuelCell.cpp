/**
  FuelCell.cpp
  Implementation of class FuelCell, a very simple abstraction of a fuel cell
*/

#include <iostream>
#include "FuelCell.h"

using std::cout;
using std::endl;

// --- FuelCell ------------------------------


// Turn on fuel
void FuelCell::fuelOn() {
  if(active)
    return;
  if(regulator.getElectricPower()>=MIN_POWER) {
    active=true;
    battery.charge();
    cout << "Fuelcell active and charging\n";
  }
  else {
    cout << "Power setting " << regulator.getElectricPower() << " to low.\n";
    cout << "Fuelcell not charging\n";
  }
}

// Turn off fuel
void FuelCell::fuelOff(){
  active=false;
  cout << "Fuelcell inactive\n";
}


bool FuelCell::isActive() const {
  return active;
}

// Set power level
bool FuelCell::setRegulator(int powerLevel) {  //
    return regulator.setElectricPower(powerLevel);
}


bool PowerRegulator::setElectricPower(int p) {
  if(p<0 || p>100)
    return false;
  power = p;
  cout << "Electric power set to " << power << endl;
  return true;
}


int PowerRegulator::getElectricPower() const {
  return power;
}
