#include "ExampleObject.h"
#include "EventStep.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "DisplayManager.h"
using namespace df;

ExampleObject::ExampleObject() {
	setType("example");
	LM.writeLog("ExampleObject constructor called");
	setAltitude(1); //lower, appears behind
}

int ExampleObject::eventHandler(Event *p_e) {
	LM.writeLog("ExampleObject event handler called");
	if (p_e->getType() == df::STEP_EVENT) {
		//react to step event + dynamic cast for use
		LM.writeLog("Object %d received a step event!", getId());
		EventStep* step = dynamic_cast<EventStep*> (p_e);
		if (GM.getLoopCount() > 0) {
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

	DM.drawCh(df::Vector(20, 15), 'X', WHITE);
	return 0;
	//draw object here
}

