#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include "Manager.h"


#define IM df::InputManager::getInstance()

namespace df {
	class InputManager : public Manager {
	private:
		InputManager();
		InputManager(InputManager const&);
		void operator=(InputManager const&);

	public:
		static InputManager& getInstance();

		int startUp();

		void shutDown();

		//get input from keyboard + mouse and pass event along to all objects
		void getInput();
	};
}

#endif