#ifndef Command_H
#define Command_H

#include<fstream>

using std::ifstream;

class Command
{
  public:
    virtual bool execute() = 0; // Execute the command 
    virtual bool unExecute() = 0; // Undo the command 
    virtual bool isUndoable() = 0; // Undoable? 
    virtual void readFromStream(ifstream&) = 0; //Read from stream 
    virtual ~Command() {} 
};

#endif