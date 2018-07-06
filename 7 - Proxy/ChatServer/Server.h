#ifndef Server_H
#define Server_H
#include <algorithm>
#include <vector>

#include "ClientProxy.h"
#include "ChatLogger.h"

using namespace std;

class Server
{
  private:
    vector<ChatObserver *> clientproxies;

  public:
    ~Server() {}
    void attach(ChatObserver *); // Triggers notify
    void detach(ChatObserver *); // Triggers notify

    void addMessage(const Message &mess)
    { // Triggers notify
        notify(mess);
    }

    void notify(Message mess); // New message
};

// Implemented

inline void Server::attach(ChatObserver *CP) // When Client connected this ChatObserver was created so now we add it to the vector of clientproxies
{
    clientproxies.push_back(CP);

    Message msg("Server", CP->getName() + " has joined the chat."); // Create a message
    notify(msg);                                                    // send it to all conencted clients
}

inline void Server::detach(ChatObserver *CP) // Client disconnected so remove proxy from vector
{
    vector<ChatObserver *>::iterator it;
    it = find_if(clientproxies.begin(), clientproxies.end(), [CP](ChatObserver *cp) { // Search thru vector for this specific ChatObserver
        return CP == cp;
    });

    Message msg("Server", CP->getName() + " has left the chat."); // Create message
    notify(msg);                                                  // Send it to users
    clientproxies.erase(it);                                      // Remove proxy from vector
}

inline void Server::notify(Message mess) // Log & Send message
{
    for (auto &ChatObserver : clientproxies) // Send to all users
    {
        ChatObserver->update(mess);
    }
}

#endif