#include "ExampleObject.h"
#include "EventStep.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "DisplayManager.h"
#include "EventKeyboard.h"
using namespace df;

ExampleObject::ExampleObject() {
	setType("example");
	LM.writeLog("ExampleObject constructor called");
	setAltitude(2); //lower, appears behind
}

int ExampleObject::eventHandler(const Event *p_e) {
	LM.writeLog("ExampleObject event handler called");
	if (p_e->getType() == df::STEP_EVENT) {
		//react to step event + dynamic cast for use
		LM.writeLog("Object %d received a step event!", getId());
		const EventStep* step = dynamic_cast<EventStep const*> (p_e);
		if (GM.getLoopCount() > 3) {
			WM.markForDelete(this);
		}
		return 1;
	}
}

ExampleObject::~ExampleObject() {
	LM.writeLog("ExampleObject destructor called");
}

int ExampleObject::draw() {
	LM.writeLog("Example object draw called");

	DM.drawString(df::Vector(10, 15), "ExampleObject", CENTER_JUSTIFIED, YELLOW);
	return 0;
	//draw object here
}

