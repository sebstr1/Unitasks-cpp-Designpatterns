#include "Component.h"
#include <iostream>
#include <string>

using namespace std;

// Abstract base class for decorators
class AddonDecorator : public Component
{
  public:
    AddonDecorator(Component *comp)
        : nextComp(comp) {}

    ~AddonDecorator()
    {
        delete nextComp;
    }
    virtual string getName()
    {
        // GetName for next component
        if (nextComp != NULL)
        {
            return nextComp->getName();
        }
    }
    virtual int getPrice()
    {
        // Call getprice for next component
        if (nextComp != NULL)
        {
            return nextComp->getPrice();
        }
    }

  private:
    Component *nextComp;
};

class SugarDecorator : public AddonDecorator
{
  public:
    SugarDecorator(Component *comp)
        : AddonDecorator(comp) {}

    virtual string getName()
    {
        return AddonDecorator::getName() + " + Sugar";
    }
    virtual int getPrice()
    {
        return AddonDecorator::getPrice() + 1;
    }
};

class MilkDecorator : public AddonDecorator
{
  public:
    MilkDecorator(Component *comp)
        : AddonDecorator(comp) {}

    virtual string getName()
    {
        return AddonDecorator::getName() + " + Milk";
    }
    virtual int getPrice()
    {
        return AddonDecorator::getPrice() + 1;
    }
};

class CreamDecorator : public AddonDecorator
{
  public:
    CreamDecorator(Component *comp)
        : AddonDecorator(comp) {}

    virtual string getName()
    {
        return AddonDecorator::getName() + " + Cream";
    }
    virtual int getPrice()
    {
        return AddonDecorator::getPrice() + 2;
    }
};

class WhippedCreamDecorator : public AddonDecorator
{
  public:
    WhippedCreamDecorator(Component *comp)
        : AddonDecorator(comp) {}

    virtual string getName()
    {
        return AddonDecorator::getName() + " + WhippedCream";
    }

    virtual int getPrice()
    {
        return AddonDecorator::getPrice() + 5;
    }
};