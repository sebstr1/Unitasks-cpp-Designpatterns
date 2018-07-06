/**
    PowerSourceAdapters.h
    Definition of adapters classes that adapt various power sources / engines to the
    PowerSource interface. This will enable adaptees to be used polymorphically as
    PowerSource objects without any changes to the original classes.

*/


#ifndef POWERSOURCEADAPTERS_H
#define POWERSOURCEADAPTERS_H

#include "PowerSource.h"

#include "V8Classic.h"
#include "GasTurbine.h"
#include "FuelCell.h"

// --- V8ClassicAD -----------------------------

// Object adapter
class V8ClassicAD : public PowerSource
{
private:
    V8Classic v8; // Adaptee

public:
    V8ClassicAD() : PowerSource("V8"){}

    virtual bool isRunning() const;
    virtual bool tryStart();
    virtual void stop();
    virtual bool setPower(int p=0);
    virtual bool incPower(int p = 10);
    virtual bool decPower(int p = 10);
};

// --- GasTurbineAD ----------------------------

// Object adapter
class GasTurbineAD : public PowerSource
{
private:
    GasTurbine gt;  // Adaptee
public:
    GasTurbineAD() : PowerSource("Gas turbine") {}

    virtual bool isRunning() const;
    virtual bool tryStart();
    virtual void stop();
    virtual bool setPower(int p=0);
    virtual bool incPower(int p = 10);
    virtual bool decPower(int p = 10);
};

//--- FuelCellAD -------------------------------


// Class adapter
class FuelCellAD : public PowerSource, private FuelCell
{
public:
    FuelCellAD() : PowerSource("Fuel cell") {}

    virtual bool isRunning() const;
    virtual bool tryStart();
    virtual void stop();
    virtual bool setPower(int p=0);
    virtual bool incPower(int p = 10);
    virtual bool decPower(int p = 10);
};


#endif // POWERSOURCEADAPTERS_H
