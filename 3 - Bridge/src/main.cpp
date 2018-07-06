/* 2018-03-14
* Namn: Sebastian Strindlund
*/

#include "Vehicle.h"
#include "RaceCar.h"
#include "Submarine.h"
#include "SpaceShip.h"
#include "../pwrSRC/PowerSourceAdapters.h"

#include <String>
#include <iostream>
#include <vector>
#include <memory>

#include "C:\Dev\Tools\include\memstat.hpp"


using std::vector;
using std::unique_ptr;
using std::make_unique;

int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<unique_ptr<PowerSource>> engines;
	engines.emplace_back(new V8ClassicAD());
	engines.emplace_back(new GasTurbineAD());
	engines.emplace_back(new FuelCellAD());

	vector<unique_ptr<Vehicle>> vehicles;

	vehicles.emplace_back(new RaceCar());
	vehicles.emplace_back(new Submarine());
	vehicles.emplace_back(new SpaceShip());


	cout << endl << endl
	<< "Choose your vehicle" << endl 
	<< "[1] Race car" << endl
	<< "[2] Submarine" << endl
	<< "[3] SpaceShip" << endl;

	int vehicleChoice;

	std::cin >> vehicleChoice;
	unique_ptr<Vehicle> vehicle(move(vehicles[vehicleChoice - 1])); // Selects vehicle

	cout << endl << endl
		 << "Choose your PowerSource" << endl
		 << "[1] V8Classic" << endl
		 << "[2] GasTurbine" << endl
		 << "[3] FuelCellAD" << endl;

	int powerChoice;

	std::cin >> powerChoice;
	cout << endl << endl;

	powerChoice = powerChoice - 1;
	vehicle->setPowerSource(move(engines[powerChoice]));  // Selects engine

	int nextEngine = (powerChoice % 2 == 0 && powerChoice != 0) ? 0 : powerChoice + 1; // Just take next powerSource as next..



	cout << "You have chosen " + vehicle->toString() + " with " + vehicle->poweredBy() + " as powersource!" << endl << endl;

	vehicle->incPower(30); // Sets power so it will start even if v8 engine
	vehicle->tryStart();   // Try to start
	vehicle->drive();      // Execute drive scenario
	vehicle->setPowerSource(move(engines[nextEngine])); // change engine mid run
    cout << "---- Swapped power source to " + vehicle->poweredBy() + " ----" << endl;
	vehicle->drive();    // Execute drive again
	vehicle->stop();     // Execute stop scenario

	return 0;
}

