/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef Uppgift1H
#define Uppgift1H

#include <string>
#include "Talker.h"
#include "SoundProducer.h"
#include <iostream>
																						
class Uppgift1 : public Talker {

private: 
	SoundProducer *sp;
public:
	Uppgift1() {}
	~Uppgift1() {}
	void setSoundProducer(SoundProducer *sp) {
		this->sp = sp;
	}
	virtual void saySomething() const { sp->makeSound(); }
};

#endif