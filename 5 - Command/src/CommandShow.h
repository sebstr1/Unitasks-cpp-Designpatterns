#ifndef CommandShow_H
#define CommandShow_H

#include <fstream>
#include "Command.h"
#include "HanoiEngine.h"

using std::ifstream;



class CommandShow : public Command
{

    private: 
        HanoiEngine &hanoiEngine;
        bool log;

    public:
      CommandShow(HanoiEngine &he, bool logg=true) : hanoiEngine(he), log(logg) {}
      virtual ~CommandShow() {}
      virtual bool execute();                  // Execute the command
      virtual bool unExecute();                // Undo the command
      virtual bool isUndoable();               // Undoable?
      virtual void readFromStream(ifstream &); //Read from stream
};

bool CommandShow::execute() // Execute the command
{ 
    hanoiEngine.show();
    if (log)
    { // If not replaying it should log
        ofstream logfile;
        logfile.open("Hanoi.log", fstream::app); // opens logfile in append mode.
        if (logfile.is_open())
        {
            logfile << "show \n"; // add show + new line
            logfile.close();
        }
        else
            cout << "Unable to open file";
    }
    return false;
}
bool CommandShow::unExecute() // Undo the command
{ 
    return false;
}
bool CommandShow::isUndoable() // Undoable?
{ 
    return true;
}
void CommandShow::readFromStream(ifstream &) //Read from stream
{ 

}

#endif