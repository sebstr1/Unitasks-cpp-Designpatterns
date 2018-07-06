#ifndef CommandReset_H
#define CommandReset_H

#include <fstream>
#include "Command.h"
#include "HanoiEngine.h"

using std::ifstream;

class CommandReset : public Command
{

  private:
    HanoiEngine &hanoiEngine;
    int nrOfDiscs;

  public:
    CommandReset(HanoiEngine &he, int discs) : hanoiEngine(he), nrOfDiscs(discs)  {}
    virtual ~CommandReset() {}
    virtual bool execute();                  // Execute the command
    virtual bool unExecute();                // Undo the command
    virtual bool isUndoable();               // Undoable?
    virtual void readFromStream(ifstream &); //Read from stream
};

bool CommandReset::execute() // Execute the command
{
    hanoiEngine.reset(nrOfDiscs); // Resets engine
    return false;
}
bool CommandReset::unExecute() // Undo the command
{
    return false;
}
bool CommandReset::isUndoable() // Undoable?
{
    return true;
}
void CommandReset::readFromStream(ifstream &) //Read from stream
{
}

#endif