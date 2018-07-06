/**
  PowerSource.h
  Common interface for various power sources / engines

*/

//--- PowerSource  -------------------------------------

#ifndef POWERSOURCE_H
#define POWERSOURCE_H

#include <string>

using std::string;

class PowerSource {

private:
  string typeStr;  // A descriptive name

public:
  PowerSource(string type):typeStr(type)
  { }

  virtual ~PowerSource() = default;

  const string& type() const { return typeStr; }
  virtual bool isRunning() const =0;
  virtual bool tryStart()=0;    // returns true if success, else false
  virtual void stop()=0;
  virtual bool setPower(int p)=0;   // returns true if success, else false
  virtual bool incPower(int p=10)=0;    // returns true if success, else false
  virtual bool decPower(int p=10)=0;    // returns true if success, else false
};

#endif
