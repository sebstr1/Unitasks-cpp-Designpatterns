/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef ShouterH
#define ShouterH
#include <iostream>
#include "SoundProducer.h"

class Shouter : public SoundProducer {

public:
	Shouter() : SoundProducer("Shout") {}
	virtual void makeSound() const { std::cout << getSoundName() << ": BIG WORDS" << std::endl; }
};

#endif