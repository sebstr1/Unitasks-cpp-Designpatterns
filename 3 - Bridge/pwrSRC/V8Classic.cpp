/**
  V8Classic.cpp
  Implementation of class V8Clasic, an abstraction of a classical V8 engine
*/

#include <iostream>
#include "V8Classic.h"

using std::cout;
using std::endl;


// --- V8Classic -----------------------------

void V8Classic::ignitionOn() {
  ignition=true;
  cout << "ignition ON " << endl;
}

void V8Classic::ignitionOff() {
  ignition=false;
  cout << "ignition OFF \n";
  cout << "The V8 is stopped." << endl;
}

void V8Classic::chokeOn() {
  choke=true;
  cout << "choke ON " << endl;
}

void V8Classic::chokeOff() {
  choke=false;
  cout << "choke OFF " << endl;
}

int V8Classic::getThrottle() const {
  return throttle;
}

bool V8Classic::setThrottle(int t) {
  if(t<0 || t>100)
    return false;
  throttle = t;
  cout << "Throttle is open " << throttle << " % " << endl;
  return true;
}

void V8Classic::runStarter() {
  if(running) {
    cout <<"Already running" << endl;
    return;
  }
  cout << "Running starter...\n";
  if(ignition && choke && throttle>=MIN_START_THROTTLE) {
    running=true;
    cout << "The V8 is running" << endl;
  }
  else
    cout << "The V8 won't start." << endl;
}


bool V8Classic::isRunning() const {
  return running;
}
