
#ifndef DrinkPrototype_H
#define DrinkPrototype_H

#include "Component.h"
#include <iostream>
#include <string>

using namespace std;

class DrinkPrototype : public Component
{
private:
  string name;
  double price;

public:
  DrinkPrototype() {}

  DrinkPrototype *clone() { return new DrinkPrototype(*this); }
  void inintialize(string type, double drinkPrice)
  {
    name = type;
    price = drinkPrice;
  }

  virtual string getName() { return name; }
  virtual double getPrice() { return price; }
};

#endif
// class Coffee : public Component
// {
// public:
//   Coffee() {}

//   virtual string getName() { return "Coffee"; }
//   virtual int getPrice() { return 10; }
// };

// class Espresso : public Component
// {
// public:
//   Espresso(){};
//   virtual string getName()
//   {
//     return "Espresso";
//   }
//   virtual int getPrice() { return 14; }
// };

// class Tea : public Component
// {
// public:
//   Tea(){};
//   virtual string getName() { return "Tea"; }
//   virtual int getPrice() { return 10; }
// };

// class Chocolate : public Component
// {
// public:
//   Chocolate(){};
//   virtual string getName() { return "Chocolate"; }
//   virtual int getPrice() { return 12; }
// };
