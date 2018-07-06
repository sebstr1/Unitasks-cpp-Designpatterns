/*
   File:        PlayHanoi.cpp
   Objective:	Designmönster DT063G - DP Command
*/

#include "HanoiEngine.h"
#include "CommandManager.h"
#include "Command.h"
#include "CommandMove.h"
#include "CommandShow.h"
#include "CommandReset.h"
#include "Replayer.h"
#include "C:\Dev\Tools\include\memstat.hpp"

#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

// Helper function for nicer main function.
void printMenu() {
    cout << endl << "HanoiTowers:" << endl;
    cout << "1 - Move" << endl;
    cout << "2 - Show" << endl;
    cout << "3 - Undo" << endl;
    cout << "4 - Redo" << endl;
    cout << "5 - RESET" << endl;
    cout << "6 - Quit" << endl;
    cout << "Choice: ";
}

// Returns nr of discs user want to have in new game.
int resetTO()
{
    remove("Hanoi.log"); // Removes logfile
    int discs;
    cout << "Enter nr of discs: ";
    cin >> discs;
    cin.get();

    ofstream logfile;
    logfile.open("Hanoi.log");
    if (logfile.is_open())
    {
        logfile << discs << '\n';   // Writes nr of discs used in game to file
    }
    logfile.close();
    return discs;
}

// Sets values to Move disc from & move disc to
void getMoveLocations(int &from, int &to)
{
    cout << "Move from: ";
    cin >> from;
    cin.get();
    cout << "Move to: ";
    cin >> to;
    cin.get();
}



int main()
{
    // Initializes variables
    bool replay = true; 
    bool keepOn = true;
    int choice, discs;
    CommandManager *Cmdmanager = new CommandManager();


    ifstream logfile;
    logfile.open("Hanoi.log");
    if (logfile.is_open())            // Tries to open logfile
    {

        while (replay)                // Replay from logfile or new game
        {
            string nrdiscs;
            logfile >> nrdiscs;
            cout << "~~~~~~~~~~ HANOI Towers ~~~~~~~~~~~~~~ " << endl;
            cout << "1 - Replay last game" << endl;
            cout << "2 - New game (Clears replay data)" << endl;
            cout << "Choice: ";
            while (!(cin >> choice) || choice < 1 || choice > 10)
            {
                cin.clear();
                cin.ignore(cin.rdbuf()->in_avail());
            }

            switch (choice)
            {
                case 1:
                {
                    HanoiEngine gameEngine(stoi(nrdiscs)); // Create HanoiEngine with nr of discs read from file
                    Replayer replai(gameEngine);          // Create replayer object
                    replai.readlog();                     // Run replay
                    break;
                }
                case 2:
                {
                    replay = false;
                    break;
                }
            }
        }
        logfile.close();
    }
    else {
        cout << "No replay available";
    }
    
    HanoiEngine gameEngine(1); // Creates a new gameEngine..
    


    Cmdmanager->doCommand(new CommandReset(gameEngine, resetTO())); // Delete logfile, let user create new game with selected nr of discs

    while (keepOn)  // WHile user not selected exit game
    {
        printMenu(); 

        while (!(cin >> choice) || choice < 1 || choice > 6)
        {
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail());
        }

        switch (choice)
        {
        case 1:	{
            int from, to;
            getMoveLocations(from, to); // Changes the value of from and to
            Cmdmanager->doCommand(new CommandMove(gameEngine, from, to));  // New command sent to Commandmanager to execute it
            break;
        }
        case 2: { Cmdmanager->doCommand(new CommandShow(gameEngine)); break; }                       // New command sent to Commandmanager to execute it
        case 3: { Cmdmanager->undo(); Cmdmanager->doCommand(new CommandShow(gameEngine, false)); break; }   // New command sent to Commandmanager to execute it
        case 4: { Cmdmanager->redo(); Cmdmanager->doCommand(new CommandShow(gameEngine, false)); break; }   // New command sent to Commandmanager to execute it
        case 5: { Cmdmanager->doCommand(new CommandReset(gameEngine, resetTO())); break; }                  // New command sent to Commandmanager to execute it
        case 6: { keepOn = false; break; } // Quit
        }
    } // while

    delete Cmdmanager; // Delete pointer
    return 0;
}
