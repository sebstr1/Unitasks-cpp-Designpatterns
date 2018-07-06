
#ifndef Component_H
#define Component_H

#include <string>
using namespace std;
class Component
{
  public:
    virtual string getName() = 0;
    virtual int getPrice() = 0;
    virtual ~Component() {}
};

#endif
