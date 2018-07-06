/*
   File:        Test.cpp
   Objective:	Designmönster DT063G - DP Decorator
   Last change: feb 2018 sest1601
*/

#include "C:\Dev\Tools\include\memstat.hpp"

#include "Component.h"
#include "DrinkComponent.h"
#include "AddonDecorator.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Helper function for nicer main function.
void printTypeMenu()
{
    cout << "~~~~~~~~~~ Super Coffee Machine menu ~~~~~~~~~~~~~~ " << endl;
    cout << endl
         << "Choose type." << endl;
    cout << "1 - Coffee (10:-)" << endl;
    cout << "2 - Espresso (14:-)" << endl;
    cout << "3 - Tea (10:-)" << endl;
    cout << "4 - Chocolate (12:-)" << endl;
    cout << "5 - Shut Down CoffeMachine" << endl;
    cout << "Choice: ";
}

void printAddonMenu(Component *firstComp)
{
    cout << "~~~~~~~~~~ Super Coffee Addon menu ~~~~~~~~~~~~~~ " << endl;
    cout << "Current order: " << firstComp->getName() << " - " << firstComp->getPrice() << "kr" << endl;
    cout << "1 - Sugar (1:-)" << endl;
    cout << "2 - Milk (1:-)" << endl;
    cout << "3 - Cream (2:-)" << endl;
    cout << "4 - WhippedCream (5:-)" << endl;
    cout << "5 - Finish order" << endl;
    cout << "Choice: ";
}

int main()
{

    Component *firstComp;
    int typeChoice;
    bool coffeeMachineON = true;

    while (coffeeMachineON)
    {
        firstComp = nullptr;
        bool orderFinished = false;
        printTypeMenu();
        while (!(cin >> typeChoice) || typeChoice < 1 || typeChoice > 5)
        {
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }
        switch (typeChoice)
        {
        case 1:
        {
            firstComp = new Coffee();
            break;
        }
        case 2:
        {
            firstComp = new Espresso();
            break;
        }
        case 3:
        {
            firstComp = new Tea();
            break;
        }
        case 4:
        {
            firstComp = new Chocolate();
            break;
        }
        case 5:
        {
            coffeeMachineON = false;
            orderFinished = true;
            break;
        }
        }

        while (!orderFinished) // Replay from logfile or new game
        {
            int choice = 0;
            printAddonMenu(firstComp);
            while (!(cin >> choice) || choice < 1 || choice > 5)
            {
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
            }

            switch (choice)
            {
            case 1:
            {
                firstComp = new SugarDecorator(firstComp);
                break;
            }
            case 2:
            {
                firstComp = new MilkDecorator(firstComp);
                break;
            }
            case 3:
            {
                firstComp = new CreamDecorator(firstComp);
                break;
            }
            case 4:
            {
                firstComp = new WhippedCreamDecorator(firstComp);
                break;
            }
            case 5:
            {
                orderFinished = true;
                break;
            }
            }
        }
        cin.get();
        if (firstComp)
        {
            cout << endl
                 << endl;
            cout << "~~~~~~~~~~ ORDER COMPLETE ~~~~~~~~~~~~~~ " << endl;
            cout << "~~~~~~~~~~ You have ordered: " << firstComp->getName() << " for " << firstComp->getPrice() << "kr"
                 << " ~~~~~~~~~~" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl
                 << endl
                 << endl
                 << endl;
            delete firstComp;
        }
    }

    return 0;
}
