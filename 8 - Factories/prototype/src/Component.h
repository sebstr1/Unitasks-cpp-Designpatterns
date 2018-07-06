
#ifndef Component_H
#define Component_H

#include <string>
using namespace std;
// #include <list>
// #include "Command.h"
// using namespace std;
class Component
{
public:
  virtual string getName() = 0;
  virtual double getPrice() = 0;
  virtual ~Component() {}
};

#endif
