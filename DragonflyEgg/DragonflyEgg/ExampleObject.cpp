#include "ExampleObject.h"
#include "EventStep.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "DisplayManager.h"
#include "EventKeyboard.h"
#include "EventCollision.h"
using namespace df;

ExampleObject::ExampleObject() {
	setType("example");
	LM.writeLog("ExampleObject constructor called");
	setAltitude(2); //lower, appears behind
	setPosition(Vector(40, 20));
}

int ExampleObject::eventHandler(const Event *p_e) {
	LM.writeLog("ExampleObject event handler called");
	if (p_e->getType() == df::STEP_EVENT) {
		//react to step event + dynamic cast for use
		LM.writeLog("Object %d received a step event!", getId());
		const EventStep* step = dynamic_cast<EventStep const*> (p_e);
		if (GM.getLoopCount() == 2000) {
			WM.markForDelete(this);
		}
		return 0;
	}
	if (p_e->getType() == KEYBOARD_EVENT) {
		const df::EventKeyboard* ke =
			dynamic_cast <const df::EventKeyboard*> (p_e);

		if (ke->getKey() == Keyboard::ESCAPE) {
			LM.writeLog("Escape key called! Time to shutdown");
			GM.shutDown();
			return 0;
		}
		if (ke->getKey() == Keyboard::W) {
			LM.writeLog("Move up!");

			//calculate new position
			Vector newpos = Vector(getPosition().getX(), getPosition().getY() - 1);
			WM.moveObject(this, newpos);
			return 0;
		}
		if (ke->getKey() == Keyboard::S) {
			LM.writeLog("Move down!");

			//calculate new position
			Vector newpos = Vector(getPosition().getX(), getPosition().getY() + 1);
			WM.moveObject(this, newpos);
			return 0;
		}
		if (ke->getKey() == Keyboard::A) {
			LM.writeLog("Move left!");

			//calculate new position
			Vector newpos = Vector(getPosition().getX() - 1, getPosition().getY());
			WM.moveObject(this, newpos);
			return 0;
		}
		if (ke->getKey() == Keyboard::D) {
			LM.writeLog("Move right!");

			//calculate new position
			Vector newpos = Vector(getPosition().getX() + 1, getPosition().getY());
			WM.moveObject(this, newpos);
			return 0;
		}
	}
	if (p_e->getType() == COLLISION_EVENT) {
		LM.writeLog("Player has collided with something!");
		const df::EventCollision* ec =
			dynamic_cast <const df::EventCollision*> (p_e);
		//if collid with example object controlled by player
		if (ec->getObject1()->getType() == "Bee" || ec->getObject2()->getType() == "Bee") {
			LM.writeLog("collided with bee!");
			//WM.markForDelete(this);
		}

	}
}

ExampleObject::~ExampleObject() {
	LM.writeLog("ExampleObject destructor called");
}

int ExampleObject::draw() {
	LM.writeLog("Example object draw called");

	DM.drawString(getPosition(), "EO", CENTER_JUSTIFIED, YELLOW);
	return 0;
	//draw object here
}

