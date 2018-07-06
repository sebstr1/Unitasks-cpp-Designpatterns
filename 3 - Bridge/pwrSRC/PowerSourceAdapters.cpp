/**
    PowerSourceAdapters.cpp
    Implementation of adapters classes
*/

#include <iostream>
#include "PowerSourceAdapters.h"

using std::cout;
using std::endl;


// --- V8ClassicAD -----------------------------

bool V8ClassicAD::isRunning() const {
    return v8.isRunning();
}


bool V8ClassicAD::tryStart() {
    v8.ignitionOn();
    v8.chokeOn();
    v8.runStarter();
    v8.chokeOff();
    if(!isRunning())
         v8.ignitionOff();

    return v8.isRunning();
}


void V8ClassicAD::stop() {
    v8.setThrottle(0);
    v8.ignitionOff();
}


bool V8ClassicAD::incPower(int p) {
    return v8.setThrottle(v8.getThrottle() + p);
}


bool V8ClassicAD::decPower(int p) {
    return v8.setThrottle(v8.getThrottle() - p);
}

bool V8ClassicAD::setPower(int p) {
    return v8.setThrottle(p);
}

// --- GasTurbineAD ----------------------------


bool GasTurbineAD::isRunning() const {
    return gt.isRunning();
}

bool GasTurbineAD::tryStart() {
    gt.startCompressors();
    return gt.burnerOn();
}

void GasTurbineAD::stop() {
    gt.setCompressorPressure(0);
    gt.stopCompressors();
    gt.burnerOff();
}

bool GasTurbineAD::setPower(int p) {
    return gt.setCompressorPressure(p);

}

bool GasTurbineAD::incPower(int p) {
    return gt.setCompressorPressure(gt.getCompressorPressure() + p);
}

bool GasTurbineAD::decPower(int p) {
    return gt.setCompressorPressure(gt.getCompressorPressure() - p);
}


//--- FuelCellAD -------------------------------

bool FuelCellAD::isRunning() const {
    return FuelCell::isActive();
}


bool FuelCellAD::tryStart() {
    FuelCell::fuelOn();
    return true;
}


void FuelCellAD::stop() {
    FuelCell::regulator.setElectricPower(0);
    FuelCell::fuelOff();
}

bool FuelCellAD::setPower(int p) {
    return FuelCell::regulator.setElectricPower(p);
}

bool FuelCellAD::incPower(int p) {
    return FuelCell::regulator.setElectricPower(FuelCell::regulator.getElectricPower() + p);
}


bool FuelCellAD::decPower(int p) {
    return FuelCell::regulator.setElectricPower(FuelCell::regulator.getElectricPower() - p);
}
