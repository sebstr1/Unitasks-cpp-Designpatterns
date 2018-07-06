#ifndef Replayer_H
#define Replayer_H

#include <fstream>
#include "HanoiEngine.h"
#include "CommandManager.h"
#include "Command.h"
#include "CommandMove.h"
#include "CommandShow.h"
#include "CommandReset.h"
#include <iostream>
#include <string>

using namespace std;

class Replayer
{
    private:
        HanoiEngine &engine;

    public:
        Replayer(HanoiEngine &hanoiengine) : engine(hanoiengine) {}
        ~Replayer() {}
        void readlog();                  // Execute the command
        void createCommand(string command, ifstream &logstream);

};

void Replayer::readlog()
{ 

    string cmd;
    ifstream logStream("Hanoi.log");  // Opens file
    if (logStream.is_open())
    {
        logStream.get(); // Reads past nr of discs
        while (logStream >> cmd)  // Loops thro the logfile
        {
            createCommand(cmd, logStream); // Creates command of type read
        }
        
        createCommand("show", logStream); // Creates one final showcommand to see the result of the replay
        logStream.close();            
    }

    else // File not existing
        std::cout << "Unable to open file";
}

void Replayer::createCommand(string cmd, ifstream &logStream) { // Creates command of type wanted
    Command *cmdPtr = nullptr;
    if (cmd == "move") {
        cmdPtr = new CommandMove(engine, false);  // Commandmove with option false to not log to fil when replaying
		cmdPtr->readFromStream(logStream);
		cmdPtr->execute();
    } 
    
    else if (cmd == "show") {
		cmdPtr = new CommandShow(engine, false);
        cout << "[SHOW]" << endl;
        cmdPtr->execute();
    }

    delete cmdPtr;
}


#endif