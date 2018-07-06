
#include "CommandManager.h"
#include <iostream>

using std::cerr;
using std::endl;

CommandManager::CommandManager() {}

CommandManager::~CommandManager()  // Clears the lists 
{
    clear();
}

bool CommandManager::canUndo() const  // Checks if undolist is not empty
{
    return (iUndoList.size() > 0);
}

bool CommandManager::canRedo() const // Checks if redolist is not empty
{
    return (iRedoList.size() > 0);
}

Command *CommandManager::popUndo()  // pops undo command
{
    Command *pCommand = iUndoList.back();
    iUndoList.pop_back();
    return pCommand;
}

Command *CommandManager::popRedo()  // pop redo command
{
    Command *pCommand = iRedoList.back();
    iRedoList.pop_back();
    return pCommand;
}

bool CommandManager::doCommand(Command *pCommand)
{
    // Execute the command.
    // Add to undo list if successful and undoable
    if (pCommand->execute() && pCommand->isUndoable())
    {
        addUndo(pCommand);
        // A new command clears RedoList
        clearRedoList();
        return true;
    }
    else
        delete pCommand;
    return false;
}

bool CommandManager::undo()
{
    if (canUndo())  // If undolist is not empty
    {
        Command *pCommand = popUndo();
        if (pCommand->unExecute()) {
            addRedo(pCommand);      // add redo command
        }
        else {
            delete pCommand;
            undo();            // recursive call since last command was not a move command
        }
        return true;
    }
    return false;
}

bool CommandManager::redo()
{
    if (canRedo()) // if redolist is not empty
    {
        Command *pCommand = popRedo();
        if (pCommand->execute()) {
            addUndo(pCommand); // add undo command
        }
        else {
            delete pCommand; 
            redo();          // recursive call since last command was not a command that you can redo;
        }
        return true;
    }
    return false;
}

void CommandManager::clear() // delets everything in lists
{
    clearUndoList();
    clearRedoList();
}

void CommandManager::addUndo(Command *pCommand) // Add command to undo list
{
    iUndoList.push_back(pCommand);
}

void CommandManager::addRedo(Command *pCommand) // Add command to redolist
{
    iRedoList.push_back(pCommand);
}

void CommandManager::clearUndoList() // 
{
    clearCommandList(&iUndoList);
}

void CommandManager::clearRedoList()
{
    clearCommandList(&iRedoList);
}

void CommandManager::clearCommandList(CommandList *pList)
{
    CommandList::iterator it;
    for (it = pList->begin(); it != pList->end(); it++)
        delete *it;
    pList->erase(pList->begin(), pList->end());
}
