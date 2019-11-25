#include <iostream>
#include "LogManager.h"
#include "Clock.h"
#include "Windows.h"
#include "GameManager.h"
#include "ExampleObject.h"
#include "Bee.h"
#include "ResourceManager.h"

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

	// Start up LogManager.
	if (LM.startUp()) {
		LM.writeLog("main(): Error starting log manager!");
		return 1;
	}

	// Start up ResourceManager.
	if (RM.startUp()) {
		LM.writeLog("main(): Error starting resource manager!");
		return 1;
	}

	// Load good sprite.
	if (RM.loadSprite("sprites/good-spr.txt", "good") != 0)
		LM.writeLog("main(): Error loading good sprite!");
	else
		LM.writeLog("main(): Successfully loaded good sprite.");

	// Load bad sprite.
	if (RM.loadSprite("sprites/bad-spr.txt", "bad") == 0)
		LM.writeLog("main(): Loaded bad sprite, but should not have!");
	else
		LM.writeLog("main(): Correctly did not load bad sprite.");

	// Shut everything down.
	//RM.shutDown();
	//LM.shutDown();

	
	if (GM.startUp()) {
		printf("error with game manager");
	}
	LM.setFlush(true);

	//load stuff in for testing
	RM.loadSprite("sprites/saucer-spr.txt", "saucer");
	RM.loadSprite("sprites/ship-spr.txt", "ship");
	RM.loadSprite("sprites/bullet-spr.txt", "bullet");
	RM.loadSprite("sprites/explosion-spr.txt", "explosion");
	RM.loadSprite("sprites/gameover-spr.txt", "gameover");
	RM.loadSprite("sprites/gamestart-spr.txt", "gamestart");

	RM.loadSound("sounds/fire.wav", "fire");
	RM.loadSound("sounds/explode.wav", "explode");
	RM.loadSound("sounds/nuke.wav", "nuke");
	RM.loadSound("sounds/game-over.wav", "gameOver");
	RM.loadSound("sounds/health-pickup.wav", "healthpickup");

	RM.loadMusic("sounds/start-music.wav", "startMusic");
	RM.loadMusic("sounds/game-music.wav", "gameMusic");
	//create objects and add to WM
	
	new ExampleObject;
	new Bee;
	new Bee;
	new Bee;
	new Bee;
	Music *musicTest = RM.getMusic("gameMusic");
	//musicTest->play();
	
	GM.run();

	//musicTest->stop();
	
}
