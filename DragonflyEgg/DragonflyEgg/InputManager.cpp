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
			std::string key = setKeyCode(eventKey, event);
			
			LM.writeLog("Key %s pressed", key.c_str());
			eventKey->setKeyboardAction(KEY_PRESSED);
			onEvent(eventKey);
			//keycode = event->key.code;
			//LM.writeLog("Key %d pressed", keycode);

		}

		if (event->type == sf::Event::KeyReleased) {
			//key released stuff
			keycode = event->key.code;
			EventKeyboard* eventKey = new EventKeyboard();
			std::string key = setKeyCode(eventKey, event);
			LM.writeLog("Key %s released", key.c_str());
			////eventKey->setKey(sf::Keyboard::Key);
			eventKey->setKeyboardAction(KEY_RELEASED);
			onEvent(eventKey);
			//LM.writeLog("Key %d released", keycode);

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

	//check current key press events for each key 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		LM.writeLog("Key %d is being held down", keycode);
		//key pressed stuff
		EventKeyboard* eventKey = new EventKeyboard();
		eventKey->setKeyboardAction(KEY_DOWN);
		eventKey->setKey(Keyboard::W);
		std::string key = setKeyCode(eventKey, event);
		
		onEvent(eventKey);
		//return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		LM.writeLog("Key %d is being held down", keycode);
		//key pressed stuff
		EventKeyboard* eventKey = new EventKeyboard();
		eventKey->setKeyboardAction(KEY_DOWN);
		eventKey->setKey(Keyboard::D);
		std::string key = setKeyCode(eventKey, event);

		onEvent(eventKey);
		//return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		LM.writeLog("Key %d is being held down", keycode);
		//key pressed stuff
		EventKeyboard* eventKey = new EventKeyboard();
		eventKey->setKeyboardAction(KEY_DOWN);
		eventKey->setKey(Keyboard::S);
		std::string key = setKeyCode(eventKey, event);

		onEvent(eventKey);
		//return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		LM.writeLog("Key %d is being held down", keycode);
		//key pressed stuff
		EventKeyboard* eventKey = new EventKeyboard();
		eventKey->setKeyboardAction(KEY_DOWN);
		eventKey->setKey(Keyboard::A);
		std::string key = setKeyCode(eventKey, event);

		onEvent(eventKey);
		//return;
	}
	if (sf::Mouse::isButtonPressed(button)) {
		//mouse pressed stuff
		EventMouse* eventMouse = new EventMouse();
		eventMouse->setMouseAction(PRESSED);
		LM.writeLog("Mouse button %d is being held down", button);

		onEvent(eventMouse);
	}
}

std::string InputManager::setKeyCode(EventKeyboard *ke, sf::Event *event) {
	std::string keycode;
	switch (event->key.code) {
		
		case sf::Keyboard::A:
			ke->setKey(Keyboard::A);
			keycode = "A";
			break;
		case sf::Keyboard::B:
			ke->setKey(Keyboard::B);
			
			break;
		case sf::Keyboard::C:
			ke->setKey(Keyboard::C);
			break;
		case sf::Keyboard::D:
			ke->setKey(Keyboard::D);
			keycode = "D";
			break;
		case sf::Keyboard::E:
			ke->setKey(Keyboard::E);
			break;
		case sf::Keyboard::F:
			ke->setKey(Keyboard::F);
			break;
		case sf::Keyboard::G:
			ke->setKey(Keyboard::G);
			break;
		case sf::Keyboard::H:
			ke->setKey(Keyboard::H);
			break;
		case sf::Keyboard::I:
			ke->setKey(Keyboard::I);
			break;
		case sf::Keyboard::J:
			ke->setKey(Keyboard::J);
			break;
		case sf::Keyboard::K:
			ke->setKey(Keyboard::K);
			break;
		case sf::Keyboard::L:
			ke->setKey(Keyboard::L);
			break;
		case sf::Keyboard::M:
			ke->setKey(Keyboard::M);
			break;
		case sf::Keyboard::N:
			ke->setKey(Keyboard::N);
			break;
		case sf::Keyboard::O:
			ke->setKey(Keyboard::O);
			break;
		case sf::Keyboard::P:
			ke->setKey(Keyboard::P);
			break;
		case sf::Keyboard::Q:
			ke->setKey(Keyboard::Q);
			break;
		case sf::Keyboard::R:
			ke->setKey(Keyboard::R);
			break;
		case sf::Keyboard::S:
			ke->setKey(Keyboard::S);
			keycode = "S";
			break;
		case sf::Keyboard::T:
			ke->setKey(Keyboard::T);
			break;
		case sf::Keyboard::U:
			ke->setKey(Keyboard::U);
			break;
		case sf::Keyboard::V:
			ke->setKey(Keyboard::V);
			break;
		case sf::Keyboard::W:
			ke->setKey(Keyboard::W);
			keycode = "W";
			break;
		case sf::Keyboard::X:
			ke->setKey(Keyboard::X);
			break;
		case sf::Keyboard::Y:
			ke->setKey(Keyboard::Y);
			break;
		case sf::Keyboard::Z:
			ke->setKey(Keyboard::Z);
			break;
		case sf::Keyboard::F1:
			ke->setKey(Keyboard::F1);
			break;
		case sf::Keyboard::F2:
			ke->setKey(Keyboard::F2);
			break;
		case sf::Keyboard::F3:
			ke->setKey(Keyboard::F3);
			break;
		case sf::Keyboard::F4:
			ke->setKey(Keyboard::F4);
			break;
		case sf::Keyboard::F5:
			ke->setKey(Keyboard::F5);
			break;
		case sf::Keyboard::F6:
			ke->setKey(Keyboard::F6);
			break;
		case sf::Keyboard::F7:
			ke->setKey(Keyboard::F7);
			break;
		case sf::Keyboard::F8:
			ke->setKey(Keyboard::F8);
			break;
		case sf::Keyboard::F9:
			ke->setKey(Keyboard::F9);
			break;
		case sf::Keyboard::F10:
			ke->setKey(Keyboard::F10);
			break;
		case sf::Keyboard::F11:
			ke->setKey(Keyboard::F11);
			break;
		case sf::Keyboard::F12:
			ke->setKey(Keyboard::F12);
			break;
		case sf::Keyboard::Space:
			ke->setKey(Keyboard::SPACE);
			keycode = "Space";
			break;
		case sf::Keyboard::Return:
			ke->setKey(Keyboard::RETURN);
			break;
		case sf::Keyboard::Escape:
			ke->setKey(Keyboard::ESCAPE);
			break;
		case sf::Keyboard::Left:
			ke->setKey(Keyboard::LEFTARROW);
			keycode = "Left";
			break;
		case sf::Keyboard::Up:
			ke->setKey(Keyboard::UPARROW);
			keycode = "Up";
			break;
		case sf::Keyboard::Right:
			ke->setKey(Keyboard::RIGHTARROW);
			keycode = "Right";
			break;
		case sf::Keyboard::Down:
			ke->setKey(Keyboard::DOWNARROW);
			keycode = "Down";
			break;
		case sf::Keyboard::Tab:
			ke->setKey(Keyboard::TAB);
			break;
		case sf::Keyboard::LControl:
			ke->setKey(Keyboard::LEFTCONTROL);
			break;
		case sf::Keyboard::Slash:
			ke->setKey(Keyboard::SLASH);
			break;
		case sf::Keyboard::Subtract:
			ke->setKey(Keyboard::MINUS);
			break;
		case sf::Keyboard::Tilde:
			ke->setKey(Keyboard::TILDE);
			break;
		case sf::Keyboard::Period:
			ke->setKey(Keyboard::PERIOD);
			break;
		case sf::Keyboard::Comma:
			ke->setKey(Keyboard::COMMA);
			break;
		case sf::Keyboard::RControl:
			ke->setKey(Keyboard::RIGHTCONTROL);
			break;
		case sf::Keyboard::LShift:
			ke->setKey(Keyboard::LEFTSHIFT);
			break;
		case sf::Keyboard::RShift:
			ke->setKey(Keyboard::RIGHTSHIFT);
			break;
		case sf::Keyboard::Num0:
			ke->setKey(Keyboard::NUM0);
			break;
		case sf::Keyboard::Num1:
			ke->setKey(Keyboard::NUM1);
			break;
		case sf::Keyboard::Num2:
			ke->setKey(Keyboard::NUM2);
			break;
		case sf::Keyboard::Num3:
			ke->setKey(Keyboard::NUM3);
			break;
		case sf::Keyboard::Num4:
			ke->setKey(Keyboard::NUM4);
			break;
		case sf::Keyboard::Num5:
			ke->setKey(Keyboard::NUM5);
			break;
		case sf::Keyboard::Num6:
			ke->setKey(Keyboard::NUM6);
			break;
		case sf::Keyboard::Num7:
			ke->setKey(Keyboard::NUM7);
			break;
		case sf::Keyboard::Num8:
			ke->setKey(Keyboard::NUM8);
			break;
		case sf::Keyboard::Num9:
			ke->setKey(Keyboard::NUM9);
			break;
		
	}
	return keycode;
}

//void setMouse