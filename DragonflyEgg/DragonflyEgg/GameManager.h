#include "Manager.h"

#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#define GM df::GameManager::getInstance();

namespace df {
	const int FRAME_TIME_DEFAULT = 33;
	//default game loop time in ms

	class GameManager : public Manager {
	private:
		GameManager(); //singleton! therefore private
		
		GameManager(GameManager const&); //don't allow copies
		void operator = (GameManager const&); //don't allow assignment
		bool game_over; //true -> game stop
		int frame_time; // target time per game loop, ms

	public:
		//~GameManager();
		//get singleton
		static GameManager& getInstance();
		//startup all gm services
		int startUp();
		//shutdown all gm stuff
		void shutDown();
		//run game loop
		void run();
		//if true (default) will stop game loop
		void setGameOver(bool new_game_over = true);

		bool getGameOver() const;

		int getFrameTime() const;

	};
}
#endif
