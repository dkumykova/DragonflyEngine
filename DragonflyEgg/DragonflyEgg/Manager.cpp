#include "Manager.h"
#include "LogManager.h"
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
