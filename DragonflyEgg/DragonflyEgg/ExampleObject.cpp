#include "ExampleObject.h"
#include "EventStep.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "GameManager.h"
using namespace df;

ExampleObject::ExampleObject() {
	setType("example");
	LM.writeLog("ExampleObject constructor called");
}

int ExampleObject::eventHandler(Event *p_e) {
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

