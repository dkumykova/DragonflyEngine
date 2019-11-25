#include "ExampleObject.h"
#include "EventStep.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "DisplayManager.h"
#include "EventCollision.h"
#include "EventOut.h"
#include "ResourceManager.h"
using namespace df;

ExampleObject::ExampleObject() {
	setType("example");
	LM.writeLog("ExampleObject constructor called");
	setAltitude(2); //lower, appears behind
	setPosition(Vector(10, 20));
	Sprite* s = RM.getSprite("ship");
	a = Animation();
	//a.setSlowdownCount(s->getSlowdown());
	a.setSprite(s);
	setAnimation(a);

	move_slowdown = 2;
	move_countdown = move_slowdown;
}

int ExampleObject::eventHandler(const Event *p_e) {
	LM.writeLog("ExampleObject event handler called");
	if (p_e->getType() == df::STEP_EVENT) {
		//react to step event + dynamic cast for use
		LM.writeLog("Object %d received a step event!", getId());
		const EventStep* eventStep = dynamic_cast<EventStep const*> (p_e);
		step();
		if (GM.getLoopCount() == 2000) {
			WM.markForDelete(this);
		}
		return 0;
	}
	if (p_e->getType() == KEYBOARD_EVENT) {
		const df::EventKeyboard* ke =
			dynamic_cast <const df::EventKeyboard*> (p_e);
		kbd(ke);
		//return 0;
	}
	if (p_e->getType() == COLLISION_EVENT) {
		LM.writeLog("Player has collided with something!");
		const df::EventCollision* ec =
			dynamic_cast <const df::EventCollision*> (p_e);
		//if collid with example object controlled by player
		if (ec->getObject1()->getType() == "Bee" || ec->getObject2()->getType() == "Bee") {
			LM.writeLog("collided with bee!");
			//WM.markForDelete(this);
			return 0;
		}
		return 0;

	}
	if (p_e->getType() == OUT_EVENT) {
		LM.writeLog("Player has gone out of bounds!");
		const df::EventOut* eo =
			dynamic_cast <const df::EventOut*> (p_e);
		//if collid with example object controlled by player
		return 0;

	}
}

//look at key pressed and act
void ExampleObject::kbd(const EventKeyboard* p_key_event) {
	switch (p_key_event->getKey()) {
	case Keyboard::ESCAPE:
		if (p_key_event->getKeyboardAction() == KEY_PRESSED) {
			GM.setGameOver();
			//WM.markForDelete(this);
		}
		break;
	case Keyboard::W:
		if (p_key_event->getKeyboardAction() == KEY_DOWN) {
			move(0, -1);
			LM.writeLog("Key down up");
		}
		break;
	case Keyboard::S:
		if (p_key_event->getKeyboardAction() == KEY_DOWN) {
			move(0, 1);
		}
		break;
	case Keyboard::A:
		if (p_key_event->getKeyboardAction() == KEY_DOWN) {
			move(-1, 0);
		}
		break;
	case Keyboard::D:
		if (p_key_event->getKeyboardAction() == KEY_DOWN) {
			move(1, 0);
		}
		break;
	default:
		return;
	};
	return;
}

//taken from saucer shoot
void ExampleObject::move(int dx, int dy) {
	Vector new_position;
	//check if it's ok to move
	if (move_countdown > 0) {
		return;
	}
	move_countdown = move_slowdown;
	
	new_position = Vector(getPosition().getX() + dx, getPosition().getY() + dy);

	
	//if stays in window, allow object to move
	
	//if ((new_position.getY() > 3) && (new_position.getY() < WM.getBoundary().getVertical())) {
	WM.moveObject(this, new_position);
	return;
	//}
}

//keep track of when hero can move
void ExampleObject::step() {
	//move countdown
	move_countdown--;
	if (move_countdown < 0) {
		move_countdown = 0;
	}

}

ExampleObject::~ExampleObject() {
	LM.writeLog("ExampleObject destructor called");
}

//int ExampleObject::draw() {
//	LM.writeLog("Example object draw called");
//
//	DM.drawString(getPosition(), "EO", CENTER_JUSTIFIED, YELLOW);
//	return 0;
//	//draw object here
//}

