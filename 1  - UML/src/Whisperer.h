/* 2018-03-14
* Namn: Sebastian Strindlund
*/
#ifndef WhispererH
#define WhispererH
#include <iostream>
#include "SoundProducer.h"

class Whisperer : public SoundProducer {

public:
	Whisperer() :SoundProducer("Whisperer") {}
	virtual void makeSound() const { std::cout << getSoundName() << ": small words" << std::endl; }

};
#endif

