#include "EventKeyboard.h"
#include "LogManager.h"

using namespace df;

EventKeyboard::EventKeyboard() {
	setType(KEYBOARD_EVENT);
	LM.writeLog("Event keyboard constructor called");
	keyboard_action = UNDEFINED_KEYBOARD_ACTION;
	key_val = Keyboard::UNDEFINED_KEY;
}

void EventKeyboard::setKey(Keyboard::Key new_key) {
	key_val = new_key;
}

Keyboard::Key EventKeyboard::getKey() const {
	return key_val;
}

void EventKeyboard::setKeyboardAction(EventKeyboardAction new_action) {
	keyboard_action = new_action;
}

EventKeyboardAction EventKeyboard::getKeyboardAction() const {
	return keyboard_action;
}