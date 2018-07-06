#ifndef CommandMove_H
#define CommandMove_H

#include <fstream>
#include "Command.h"
#include "HanoiEngine.h"
#include <string>


using namespace std;

class CommandMove : public Command
{
  private:
    HanoiEngine &hanoiEngine;
    int from, to;
    bool log = true;

  public:
    CommandMove(HanoiEngine &he, int from, int to) : hanoiEngine(he), from(from), to(to) {}
    CommandMove(HanoiEngine &he, bool log) : hanoiEngine(he), log(log) {}
    virtual ~CommandMove() {}
    virtual bool execute();                  // Execute the command
    virtual bool unExecute();                // Undo the command
    virtual bool isUndoable();               // Undoable?
    virtual void readFromStream(ifstream &); //Read from stream
    static CommandMove *CommandMove::createObjectFromStream(HanoiEngine engine, ifstream &);
};

bool CommandMove::execute() {                   // Execute the command

    if (hanoiEngine.move(from, to)) { // If move successful
        
        if (log) { // If not replaying it should log
            ofstream logfile;
            logfile.open("Hanoi.log", fstream::app);
            if (logfile.is_open())
            {
                logfile << "move " << from << "-" << to << "\n";
                logfile.close();
            }
            else
                cout << "Unable to open file";
        }
        return true;
    }
    return false;
}                  
bool CommandMove::unExecute() {                // Undo the command
    hanoiEngine.move(to, from);
    return true;
}               
bool CommandMove::isUndoable() {               // Undoable?

    return true;
}


void CommandMove::readFromStream(ifstream &logstream) { //Sets from and to..
    string positions, movefrom, moveto;
    logstream >> positions;             // should be something like "1-2", "3-1" or "21" etc..
    logstream.get();                    // skip stream to next line
    
    movefrom = positions.substr(0, positions.find("-")); // filter out first number which is from

    moveto = positions.substr(positions.find("-") + 1, positions.length()-1);  // filter out second numbers which is to

    cout << "[MOVE] From " + movefrom + " -> " + moveto << endl;  // Show in console..

    to = stoi(moveto);     // Sets object's to variable..
    from = stoi(movefrom); // Sets objects from variable.

}

#endif