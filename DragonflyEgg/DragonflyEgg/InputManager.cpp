#include "InputManager.h"
#include "DisplayManager.h"
#include "LogManager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"

using namespace df;

InputManager::InputManager() {
	
}

InputManager &InputManager::getInstance() {
	static InputManager inputManager;
	return inputManager;
}

int InputManager::startUp() {
	//assumes DM has already created the window; is dependent on it
	if (!DM.isStarted()) {
		return -1;
	}

	sf::RenderWindow *window = DM.getWindow();

	window->setKeyRepeatEnabled(false);

	//manager start up
	Manager::startUp();

}

void InputManager::shutDown() {
	sf::RenderWindow* window = DM.getWindow();

	window->setKeyRepeatEnabled(true);

	//manager shutdown
	Manager::shutDown();
}

//get input from keyboard + mouse and pass event along to all objects
void InputManager::getInput() {
	sf::Keyboard::Key keycode = sf::Keyboard::Key();
	sf::Mouse::Button button = sf::Mouse::Button();
	//go through all window events and extract recognized ones for input use
	sf::Event* event = new sf::Event();
	sf::RenderWindow* window = DM.getWindow();

	while (window->pollEvent(*event)) {
		//key pressed
		if (event->type == sf::Event::KeyPressed) {
			//do keypressed stuff, like key code
			EventKeyboard *eventKey = new EventKeyboard();
			//eventKey->setKey(event->key);
			eventKey->setKeyboardAction(KEY_PRESSED);
			onEvent(eventKey);
			//keycode = event->key.code;
			LM.writeLog("Key %d pressed", keycode);

		}

		if (event->type == sf::Event::KeyReleased) {
			//key released stuff
			keycode = event->key.code;
			EventKeyboard* eventKey = new EventKeyboard();
			
			////eventKey->setKey(sf::Keyboard::Key);
			eventKey->setKeyboardAction(KEY_RELEASED);
			onEvent(eventKey);
			LM.writeLog("Key %d pressed", keycode);

		}

		if (event->type == sf::Event::MouseMoved) {
			//mouse move handle
			
			EventMouse* eventMouse = new EventMouse();
			eventMouse->setMouseAction(MOVED);
			//eventMouse->setMousePosition(sf::Mouse::getPosition());
			onEvent(eventMouse);
			LM.writeLog("Mouse has moved!");
		}

		if (event->type == sf::Event::MouseButtonPressed) {
			//mouse butotn press handle
			EventMouse* eventMouse = new EventMouse();
			eventMouse->setMouseAction(CLICKED);
			//eventMouse->setMousePosition(sf::Mouse::getPosition());
			LM.writeLog("left click!");
			if (event->mouseButton.button == sf::Mouse::Right) {
				//handle right click
				eventMouse->setMouseButton(Mouse::RIGHT);
				LM.writeLog("right click!");
			}
			else {
				eventMouse->setMouseButton(Mouse::LEFT);
			}
			onEvent(eventMouse);

		}
	}

	//check current key press events for each key - do i have to do ALL of them??
	if (sf::Keyboard::isKeyPressed(keycode)) {
		LM.writeLog("Key %d is being held down", keycode);
		//key pressed stuff
	}
	if (sf::Mouse::isButtonPressed(button)) {
		//mouse pressed stuff
		LM.writeLog("Mouse button %d is being held down", button);
	}
}