#include "PrototypeManager.h"
#include "prices.h"

using namespace std;

PrototypeManager *PrototypeManager::instance = nullptr;
DrinkPrototype *PrototypeManager::drinkPro = nullptr;
DecoratorPrototype *PrototypeManager::decoratorPrototype = nullptr;

PrototypeManager *PrototypeManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new PrototypeManager();
    }
    return instance;
}

DrinkPrototype *PrototypeManager::getDrink(string type)
{
    DrinkPrototype *drink = drinkPro->clone();

    map<string, double>::iterator priceFinder;
    priceFinder = priceMap.find(type);

    drink->inintialize(type, priceFinder->second);
    return drink;
}

DecoratorPrototype *PrototypeManager::getDecorator(Component *comp, string type)
{
    DecoratorPrototype *decorator = decoratorPrototype->clone();

    map<string, double>::iterator priceFinder;
    priceFinder = priceMap.find(type);

    decorator->inintialize(type, priceFinder->second, comp);
    return decorator;
}