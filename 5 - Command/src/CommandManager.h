
#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <list>
#include "Command.h"
using namespace std;

class CommandManager
{
  private:
    typedef list<Command *> CommandList; // List of commands
    CommandList iUndoList; // Undo commands
    CommandList iRedoList; // Redo commands

    // Private operations
    Command *popUndo();                          // Pop most recent command from the list
    Command *popRedo();                          // Pop most recent command from the list
    void addUndo(Command *pCommand);             // Add command to undo list
    void addRedo(Command *pCommand);             // Add command to redo list
    void clear();                                // Clear undo- and redo list
    void clearCommandList(CommandList *pList);   // Clear list of commands

    // Public interface
  public:
    // CommandManager(int nUndoLevel = 100);
    CommandManager();
    ~CommandManager();                        // Destructor
    bool doCommand(Command *pCommand);        // Execute command
    bool canUndo() const;                     // Check if command can be undone
    bool canRedo() const;                     // Check if command can be redone
    bool undo();                              // Pop and undo command
    bool redo();                              // Pop and redo command
    void clearUndoList();                     // Clear undo list
    void clearRedoList();                     // Clear redo list
};

#endif
