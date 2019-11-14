#include "Manager.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "Object.h"
#include "ExampleObject.h"
using namespace df;

Manager::Manager() {
	setType("Manager");
}

df::Manager::~Manager()
{
	std::printf("Manager is made!\n");
}

int Manager::startUp() {
	m_is_started = true;
	return 0;
}

void Manager::shutDown() {
	m_is_started = false;
	LM.writeLog("Manager shutdown called.\n");
}

bool Manager::isStarted() const {
	if (m_is_started) {
		LM.writeLog("Manager is started called.\n");
		return true;
	}
	else {
		return false;
	}
}

void Manager::setType(std::string type) {
	m_type = type;
}

std::string Manager::getType() const {
	return m_type;
}

//send event to all objects
//return count of number of events sent
int Manager::onEvent(const Event* p_event) {
	int count = 0;

	std::vector<Object*> allObjects = WM.getAllObjects();
	std::vector<Object*>::iterator i;
	for (i = allObjects.begin(); i != allObjects.end(); i++) {
		//(*i)->Update();
		//**for some reason this is only calling the virtual event instead of individualized
		(*i)->eventHandler(p_event); //send step event for each object to handle if they want
		count++;
	}

	return count;
}