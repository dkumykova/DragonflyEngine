#include "EventStep.h"
#include "LogManager.h"

using namespace df;

EventStep::EventStep() {
	m_step_count = 0;
	setType(STEP_EVENT);
	LM.writeLog("Event Step constructor called with type set to : %s", getType().c_str());
}

//initialize with specific step count
EventStep::EventStep(int init_step_count) {
	m_step_count = init_step_count;
	setType(STEP_EVENT);
	LM.writeLog("Event Step constructor called with type set to : %s and initial step count of %d", getType().c_str(), getStepCount());

}

void EventStep::setStepCount(int new_step_count) {
	m_step_count = new_step_count;
}

int EventStep::getStepCount() const {
	return m_step_count;
}