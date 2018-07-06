/**
  GasTurbine.cpp
  Implementation of class GasTurbine
  */

#include <iostream>
#include "GasTurbine.h"
using std::cout;
using std::endl;

// --- GasTurbine ----------------------------

GasTurbine::GasTurbine()
    :pressure(0),running(false),
    compressors(false),burner(false)
{ }

bool GasTurbine::startCompressors() {
  if(running)
    return false;
  if(pressure >= 30) {
    cout << "Compressors started\n";
    compressors = true;
  }
  return checkRunning();
}


void GasTurbine::stopCompressors() {
  if(compressors) {
    cout << "Compressors stopped\n";
    compressors = false;
    pressure = 0;
  }
  checkRunning();
}

bool GasTurbine::burnerOn() {
  if(running)
      return true;

  else if(pressure<MIN_START_PRESSURE) {
    cout << "Pressure " << pressure << " is too low\n";
    return false;
  }
  else {
  cout << "Burner started\n";
  burner = true;
    checkRunning();
  }
  return running;
}


bool GasTurbine::burnerOff() {
  if(!burner)
    return false;
  cout << "Burner stopped\n";
  burner = false;
  checkRunning();
  return true;
}


bool GasTurbine::setCompressorPressure(int p) {
  if(p<0 || p>100)
    return false;

  pressure = p;
  cout << "Pressure is " << pressure << " units\n";
  return true;
}



bool GasTurbine::checkRunning() {
  return running = pressure>=MIN_START_PRESSURE && compressors && burner;
}


// Returns TRUE if the gas turbine is active and running, else FALSE
bool GasTurbine::isRunning() const {
  return running;
}
