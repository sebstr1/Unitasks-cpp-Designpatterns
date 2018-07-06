/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef VehicleH
#define VehicleH

#include <string>
#include <iostream>
#include "../pwrSRC/PowerSource.h"
#include <memory>
#include "../pwrSRC/PowerSourceAdapters.h"

using std::cout;
using std::string;
using std::unique_ptr;

class Vehicle
{
  private: 
    unique_ptr<PowerSource> PowerSrc;
    string Vehicletype;

  public:   
    // Constructor 
    Vehicle() {}
    Vehicle(string type, unique_ptr<PowerSource> ptr) { Vehicletype = type; PowerSrc = std::move(ptr); }
    // Destructor ... 
    virtual ~Vehicle() {}

    string toString() { return Vehicletype; } // e.g."SpaceShutte" 
    string poweredBy() { return PowerSrc->type(); } // e.g."FuelCell" 
    bool tryStart() { return PowerSrc->tryStart();}    // Try to start the powersource 
    bool stop() { PowerSrc->stop(); return true; }        // Stop the powersource 
    bool incPower(int p = 5) { return PowerSrc->incPower(p); } // Increase power 
    bool decPower(int p = 5) { return PowerSrc->decPower(p); }   // Decrease power 
    virtual void drive() = 0;   // Simulate a driving scenario
    void setPowerSource(unique_ptr<PowerSource> ptr) { PowerSrc = std::move(ptr); } // Change PowerSource

    //Operations for steering
    virtual void steerLeft(int degrees)=0;
    virtual void steerRight(int degrees)=0; 
    //Optional driving operations of your choice ...  
};

#endif