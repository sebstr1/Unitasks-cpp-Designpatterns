#ifndef PrototypeManager_H
#define PrototypeManager_H

#include "DrinkPrototype.h"
#include "DecoratorPrototype.h"
#include "Component.h"
#include <string>

class PrototypeManager
{
  private:
    static PrototypeManager *instance;
    static DrinkPrototype *drinkPro;
    static DecoratorPrototype *decoratorPrototype;
    PrototypeManager()
    {
        drinkPro = new DrinkPrototype();
        decoratorPrototype = new DecoratorPrototype(drinkPro);
    }

  public:
    ~PrototypeManager() { delete decoratorPrototype; }
    DrinkPrototype *getDrink(string type);
    DecoratorPrototype *getDecorator(Component *comp, string type);
    void destroy()
    {
        delete instance;
        instance = nullptr;
    }

    static PrototypeManager *getInstance();
};

#endif