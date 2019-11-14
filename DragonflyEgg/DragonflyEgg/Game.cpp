#include <iostream>
#include "LogManager.h"
#include "Clock.h"
#include "Windows.h"
#include "GameManager.h"
#include "ExampleObject.h"
#include "Bee.h"

using namespace df;

int main(int argc, char* argv[])
{
	// Start up LogManager.
	/*if (LM.startUp()) {
		printf("Error starting log manager!\n");
		return 1;
	}*/
	
	//TODO: vector functions test code
	//TODO: test code for object + list of objects
	
	
	if (GM.startUp()) {
		printf("error with game manager");
	}

	//create objects and add to WM
	new ExampleObject;
	new ExampleObject;
	new ExampleObject;
	new Bee;
	
	GM.run();

	
	
}