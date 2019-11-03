#include "GameManager.h"
#include "LogManager.h"
#include "Windows.h"

using namespace df;

GameManager::GameManager() {
	setType("GameManager");
	game_over = true;
	frame_time = FRAME_TIME_DEFAULT;
}


void GameManager::setGameOver(bool new_game_over = true) {
	game_over = new_game_over;
}

bool GameManager::getGameOver() const{
	return game_over;
}

int GameManager::getFrameTime() const {
	return frame_time;
}

void GameManager::run() {
	while (!game_over) {
		
	}
}

int GameManager::startUp() {
	//get instances of and startup all other managers
	LM.getInstance();
	LM.startUp();

	game_over = false;
	timeBeginPeriod(1);


}

void GameManager::shutDown() {
	LM.shutDown();
	setGameOver();
	timeEndPeriod(1);
}