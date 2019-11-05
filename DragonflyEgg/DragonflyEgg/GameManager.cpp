#include "GameManager.h"
#include "LogManager.h"
#include "Windows.h"
#include "Clock.h"

using namespace df;

GameManager::GameManager() {
	setType("GameManager");
	game_over = true;
	frame_time = FRAME_TIME_DEFAULT;
	
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
	Clock clock = Clock();
	while (!game_over) {
		clock.delta(); //get elapsed time

		//get input
		//update game world state
		//draw current scene to back buffer
		//swap back buffer to current buffer

		long int loop_time = clock.split();
		//we want to sleep if the loop ends early to preserve 
		//smooth loop transitions
		
		Sleep(FRAME_TIME_DEFAULT - loop_time);

		//if target - lopptime is negative, time to process took longer than expected and engine can't keep up
		//results in frame rate drop
	}
}

int GameManager::startUp() {
	//get instances of and startup all other managers
	LM.getInstance();
	LM.startUp();

	game_over = false; 
	//call in order to have clock millisecond resolution
	timeBeginPeriod(1);

	return 0;
}

void GameManager::shutDown() {
	LM.shutDown();
	setGameOver();
	timeEndPeriod(1);
}