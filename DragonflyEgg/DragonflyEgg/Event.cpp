#include "Event.h"
#include "LogManager.h"

using namespace df;

Event::Event() {
	event_type = UNDEFINED_EVENT;
	LM.writeLog("Event base constructor called");
}

Event::~Event() {
	LM.writeLog("Event base destructor called");
}


void Event::setType(std::string new_type) {
	event_type = new_type;
}

std::string Event::getType() const {
	return event_type;
}