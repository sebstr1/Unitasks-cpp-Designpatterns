#ifndef AddonDecorator_H
#define AddonDecorator_H

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
        // Call prtTicket for the next component in chain
        if (nextComp != NULL)
        {
            return nextComp->getName();
        }
    }
    virtual double getPrice()
    {
        // Call prtTicket for the next component in chain
        if (nextComp != NULL)
        {
            return nextComp->getPrice();
        }
    }

    virtual void inintialize(Component *comp)
    {
        nextComp = comp;
    }

  private:
    Component *nextComp;
};

class DecoratorPrototype : public AddonDecorator
{
  private:
    string name;
    double price;

  public:
    DecoratorPrototype(Component *comp)
        : AddonDecorator(comp) {}

    DecoratorPrototype *clone() { return new DecoratorPrototype(*this); }

    void inintialize(string type, double decoprice, Component *comp)
    {
        name = type;
        price = decoprice;
        AddonDecorator::inintialize(comp);
    }
    virtual string getName()
    {
        return AddonDecorator::getName() + " + " + name;
    }
    virtual double getPrice()
    {
        return AddonDecorator::getPrice() + price;
    }
};

#endif
// class SugarDecorator : public AddonDecorator
// {
//   public:
//     SugarDecorator(Component *comp)
//         : AddonDecorator(comp) {}

//     virtual string getName()
//     {
//         return AddonDecorator::getName() + " + Sugar";
//     }
//     virtual int getPrice()
//     {
//         return AddonDecorator::getPrice() + 1;
//     }
// };

// class MilkDecorator : public AddonDecorator
// {
//   public:
//     MilkDecorator(Component *comp)
//         : AddonDecorator(comp) {}

//     virtual string getName()
//     {
//         return AddonDecorator::getName() + " + Milk";
//     }
//     virtual int getPrice()
//     {
//         return AddonDecorator::getPrice() + 1;
//     }
// };

// class CreamDecorator : public AddonDecorator
// {
//   public:
//     CreamDecorator(Component *comp)
//         : AddonDecorator(comp) {}

//     virtual string getName()
//     {
//         return AddonDecorator::getName() + " + Cream";
//     }
//     virtual int getPrice()
//     {
//         return AddonDecorator::getPrice() + 2;
//     }
// };

// class WhippedCreamDecorator : public AddonDecorator
// {
//   public:
//     WhippedCreamDecorator(Component *comp)
//         : AddonDecorator(comp) {}

//     virtual string getName()
//     {
//         return AddonDecorator::getName() + " + WhippedCream";
//     }

//     virtual int getPrice()
//     {
//         return AddonDecorator::getPrice() + 5;
//     }
// };