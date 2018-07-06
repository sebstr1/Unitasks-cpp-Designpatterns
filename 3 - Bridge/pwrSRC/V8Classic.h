/**
  V8Classic.h
  Definition of class V8Clasic, an abstraction of a classical V( engine
 */


#ifndef V8CLASSIC_H
#define V8CLASSIC_H


// --- V8Classic -----------------------------

class V8Classic  {
private:
   bool running, ignition, choke;
   int throttle; //throttle vent 0 .. 100 units
   const int MIN_START_THROTTLE = 25;
public:
   V8Classic()
   :running(false),ignition(false),
    choke(false),throttle(0)
    { }
   void ignitionOn();
   void ignitionOff();
   void chokeOn();
   void chokeOff();
   void runStarter();
   bool setThrottle(int);
   int getThrottle() const;
   bool isRunning() const;

  /*  To get a classic V8 running:
   *    setThrottle(level);  // level >= MIN_START_THROTTLE
        ignitionOn();
        chokeOn();
        runStarter();
        chokeOff();

      ...and to stop it:
        setThrottle(0);
        ignitionOff()

     A change in throttle gives a change in power
  */
};

#endif // V8CLASSIC_H
