#include "GameManager.h"
#include "LogManager.h"
#include "Windows.h"
#include "Clock.h"
#include "Object.h"
#include "EventStep.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include <vector>

using namespace df;

GameManager::GameManager() {
	setType("GameManager");
	game_over = true;
	frame_time = FRAME_TIME_DEFAULT;
	loop_count = 0;
	totalTime = 0;
	
}

GameManager &GameManager::getInstance() {

	static GameManager gameManager;
	return gameManager;
}
void GameManager::setGameOver(bool new_game_over) {
	game_over = new_game_over;
}

bool GameManager::getGameOver() const{
	return game_over;
}

int GameManager::getFrameTime() const {
	return frame_time;
}

void GameManager::run() {

	Clock *clock = new Clock();
	while (!game_over) {
		if (loop_count > 2000) { //stop after 2 loop
			//GM.setGameOver();
			GM.shutDown();
		}
		clock->delta(); //get elapsed time
		//create event step and send to each object in world manager list
		//print all objects in updates list
		LM.writeLog("All objects currently in world:");
		WM.printAllObjects(WM.getAllObjects());
		LM.writeLog("All objects of type example");
		WM.printAllObjects(WM.objectsOfType("example"));
		LM.writeLog("All objects of type Bee");
		WM.printAllObjects(WM.objectsOfType("Bee"));

		//create window and draw to it!
		

		EventStep *step = new EventStep(loop_count);
		
		//iterate over all objects in object list and update
		onEvent(step);
		std::vector<Object*>::iterator i;
		
		//get input
		//update game world state
		//draw current scene to back buffer
		//swap back buffer to current buffer

		//call worldmanager update 1 time per loop
		IM.getInput();
		WM.update();
		WM.draw();

		//demonstrate the different justifications for drawing strings
		DM.drawString(df::Vector(50, 5), "Center Justified", CENTER_JUSTIFIED, WHITE);
		DM.drawString(df::Vector(50, 10), "Left Justified", LEFT_JUSTIFIED, WHITE);
		DM.drawString(df::Vector(50, 15), "Right Justified", RIGHT_JUSTIFIED, WHITE);
		DM.swapBuffers();
		//Sleep(2000);
		//cast this to float for more accuracy probably
		long int loop_time = clock->split() / 1000; //loop time should be around 20 ms
		LM.writeLog("loop time and count: %ld, %d", loop_time, loop_count);
		
		
		//we want to sleep if the loop ends early to preserve 
		//smooth loop transitions

		//convert time frame default microseconds for subtraction
		if (FRAME_TIME_DEFAULT - loop_time > 0) {
			Sleep(FRAME_TIME_DEFAULT - loop_time);
		}
		

		LM.writeLog("time slept in milliseconds: %ld", FRAME_TIME_DEFAULT - loop_time);


		//if target - lopptime is negative, time to process took longer than expected and engine can't keep up
		//results in frame rate drop
		loop_count++;
		totalTime += loop_time + (FRAME_TIME_DEFAULT - loop_time); //this should be a multiple of 33 always
		LM.writeLog("number of steps: %ld", totalTime * loop_count);
		
	}
}

int GameManager::startUp() {
	//get instances of and startup all other managers
	LM.writeLog("GameManager startup called.\n");
	if (LM.startUp()) {
		printf("Error starting log manager!\n");
		return -1;
	}
	if (WM.startUp()) {
		LM.writeLog("Error starting WM");
		return -1;
	}
	if (DM.startUp()) {
		LM.writeLog("Error starting DM");
		return -1;
	}
	if (IM.startUp()) {
		LM.writeLog("Error starting IM");
		return -1;
	}
	game_over = false; 
	//call in order to have clock millisecond resolution
	timeBeginPeriod(1);

	return 0;
}

void GameManager::shutDown() {
	LM.writeLog("Total time in run loop: %ld\n", totalTime);
	LM.writeLog("GameManager shutdown called.\n");
	WM.shutDown();
	LM.shutDown();
	DM.shutDown();
	setGameOver();
	timeEndPeriod(1);
}

long int GameManager::getTotalTime() const{
	return totalTime;
}

int GameManager::getLoopCount() const{
	return loop_count;
}