#include <iostream>
#include "LogManager.h"
#include "Clock.h"
#include "Windows.h"
#include "GameManager.h"

using namespace df;

int main(int argc, char* argv[])
{
	// Start up LogManager.
	if (LM.startUp()) {
		printf("Error starting log manager!\n");
		return 1;
	}
	
	//can;t call GM for some reason??
	Clock *c = new Clock();
	// Successfully started, so write some stuff.
	LM.writeLog("This is a test.");
	LM.writeLog("This is test %d.", 2);
	LM.writeLog("This is %s %0.1f.", "test", 2.5);
	LM.writeLog("Clock testing------------");
	//long int time1 = c->delta();
	LM.writeLog("Time 1 delta: %ld", c->delta());
	Sleep(500);
	LM.writeLog("Time 2 delta: %ld", c->delta()); //should be exactly 500 ms
	Sleep(1000);
	LM.writeLog("Time 3 split: %ld", c->split()); //should be 1000 ms
	Sleep(1000);
	LM.writeLog("Time 4 delta: %ld", c->delta());//should be 2000 ms

	// Shutdown LogManager.
	LM.shutDown();
	
}