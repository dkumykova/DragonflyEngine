#include "Bee.h"
#include "LogManager.h"
#include "EventStep.h"
#include "GameManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "EventKeyboard.h"
#include "EventCollision.h"
#include "EventOut.h"
#include "ResourceManager.h"

using namespace df;

Bee::Bee() {
	LM.writeLog("Bee constructor called");
	setType("Bee");
	setAltitude(1);
	setSpeed(.25);
	setDirection(Vector(-1.0, 0));
	
	int v1 = rand() % 60;
	int v2 = rand() % 30;
	setPosition(Vector(v1, v2));
	setSolidness(SOFT);

	Sprite *s = RM.getSprite("saucer");
	a = Animation();
	//a.setSlowdownCount(s->getSlowdown());
	a.setSprite(s);
	setAnimation(a);

	death = RM.getSound("explode");
	


}

int Bee::eventHandler(const Event *p_e) {
	LM.writeLog("Bee event handler called");
	if (p_e->getType() == STEP_EVENT) {
		LM.writeLog("Bee received a step event!");
		if (GM.getLoopCount() == 1000) {
			LM.writeLog("Setting bee altitude to 3!");
			setAltitude(3);
		}
		else if (GM.getLoopCount() == 1500) {
			WM.markForDelete(this);
			return 0;
		}
	}

	if (p_e->getType() == COLLISION_EVENT) {
		LM.writeLog("Bee has collided with something!");
		const df::EventCollision* ec =
			dynamic_cast <const df::EventCollision*> (p_e);
		//if collid with example object controlled by player
		if (ec->getObject1()->getType() == "example" || ec->getObject2()->getType() == "example") {
			LM.writeLog("collided with player! Time to delete myself");
			death->play();
			WM.markForDelete(this);
		}

	}
	if (p_e->getType() == OUT_EVENT) {
		LM.writeLog("Bee has gone out of bounds!");
		const df::EventOut* eo =
			dynamic_cast <const df::EventOut*> (p_e);
		//if collid with example object controlled by player

	}

	//handle event out
	//log statement

	
	return 0;
}

Bee::~Bee() {
	LM.writeLog("Bee destructor called");
}
