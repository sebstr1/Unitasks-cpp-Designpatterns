/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#include "Uppgift1.h"
#include "Whisperer.h"
#include "Shouter.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Uppgift1 uppg1;

	SoundProducer *w = new Whisperer;
	SoundProducer *s = new Shouter;

	uppg1.setSoundProducer(w);
	uppg1.saySomething();
	uppg1.setSoundProducer(s);
	uppg1.saySomething();

	delete w;
	delete s;

	system("Pause");
	return 0;
}

