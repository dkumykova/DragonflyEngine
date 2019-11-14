#include "Bee.h"
#include "LogManager.h"
#include "EventStep.h"
#include "GameManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"

using namespace df;

Bee::Bee() {
	LM.writeLog("Bee constructor called");
	setType("Bee");
	setAltitude(2);

}

int Bee::eventHandler(Event *p_e) {
	LM.writeLog("Bee event handler called");
	if (p_e->getType() == STEP_EVENT) {
		LM.writeLog("Bee received a step event!");
		if (GM.getLoopCount() > 0) {
			WM.markForDelete(this);
			return 0;
		}
	}
	return 0;
}

Bee::~Bee() {
	LM.writeLog("Bee destructor called");
}

int Bee::draw() {
	LM.writeLog("Bee draw called");

	DM.drawString(df::Vector(20, 15), "Beeeeeeee", CENTER_JUSTIFIED, WHITE);
	return 0;
}