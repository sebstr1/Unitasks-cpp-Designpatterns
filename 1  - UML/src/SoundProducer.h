/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#ifndef SoundProducerH
#define SoundProducerH

#include <string>
																					
class SoundProducer {

private:
	string soundName;
public:
	SoundProducer() {}
	SoundProducer(string nameOfSound) { soundName = nameOfSound; }
	~SoundProducer() {}
	virtual void makeSound() const = 0;
	string getSoundName() const { return soundName; }
	virtual void saySomething() {}
};

#endif