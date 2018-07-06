#include "Component.h"
#include <iostream>
#include <string>

using namespace std;

class Coffee : public Component
{
public:
  Coffee() {}

  virtual string getName() { return "Coffee"; }
  virtual int getPrice() { return 10; }
};

class Espresso : public Component
{
public:
  Espresso(){};
  virtual string getName()
  {
    return "Espresso";
  }
  virtual int getPrice() { return 14; }
};

class Tea : public Component
{
public:
  Tea(){};
  virtual string getName() { return "Tea"; }
  virtual int getPrice() { return 10; }
};

class Chocolate : public Component
{
public:
  Chocolate(){};
  virtual string getName() { return "Chocolate"; }
  virtual int getPrice() { return 12; }
};
