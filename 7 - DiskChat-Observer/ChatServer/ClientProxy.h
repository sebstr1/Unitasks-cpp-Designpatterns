#ifndef ClientProxy_H
#define ClientProxy_H

#include "Address.h"
#include "ClientConnection.h"
#include "ChatObserver.h"
#include <string>

using namespace std;

class ClientProxy : public ChatObserver
{
private:
  Connection *connection;

public:
  ClientProxy(string name, HDaddress address) : ChatObserver(name), connection(new HDclientConnection)
  {
    connection->connect(address);
  }

  ~ClientProxy()
  {
    connection->disconnect(); // Disconnect
    delete connection;        // DElete pointer
  }

  virtual void update(const Message &msg);
};

inline void ClientProxy::update(const Message &msg) // Send message to user
{
  connection->send(msg); // Send
}

#endif