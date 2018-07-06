/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#include "Bakery.h"
#include "Pizza.h"
#include "Scones.h"
#include "Kladdkaka.h"
#include "Sockerkaka.h"

// #include "C:\Dev\Tools\include\memstat.hpp"

int main()
{
	// _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Bakery Delicato("skafferi.dat");

	Delicato.addRecepy(new Pizza);
	Delicato.addRecepy(new Scones);
	Delicato.addRecepy(new Kladdkaka);
	Delicato.addRecepy(new Sockerkaka);  // Sockerkaka will not bake because one ingredient is missing.

	Delicato.runBakery();


	system("Pause");
	return 0;
}

