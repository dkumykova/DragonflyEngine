#include "EventMouse.h"
#include "LogManager.h"

using namespace df;

EventMouse::EventMouse() {
	setType(MSE_EVENT);
	LM.writeLog("Mouse event constructor called");
	mouse_action = UNDEFINED_MOUSE_ACTION;
	mouse_button = Mouse::UNDEFINED_MOUSE_BUTTON;
	mouse_xy = Vector(); //intialize to 0, 0
}

void EventMouse::setMouseAction(EventMouseAction new_action) {
	mouse_action = new_action;
}

EventMouseAction EventMouse::getMouseAction() const {
	return mouse_action;
}

void EventMouse::setMouseButton(Mouse::Button new_button) {
	mouse_button = new_button;
}

Mouse::Button EventMouse::getMouseButton() const {
	return mouse_button;
}

void EventMouse::setMousePosition(Vector new_pos) {
	mouse_xy = new_pos;
}

Vector EventMouse::getMousePosition() const {
	return mouse_xy;
}