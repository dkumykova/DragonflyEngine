#include "ResourceManager.h"
#include "LogManager.h"
#include <string>
#include <iostream>

using namespace df;

ResourceManager::ResourceManager() {
	setType("ResourceManager");
	//sprite_count = 0;
	//sprites already initialized
}
ResourceManager &ResourceManager::getInstance() {
	static ResourceManager resourceManager;
	return resourceManager;
}

int ResourceManager::startUp() {
	//sprite_count = 0;
	if (Manager::startUp()) {
		LM.writeLog("Error starting resource manager");
		return -1;
	}
}
void ResourceManager::shutDown() {
	//delete sprites; //delete array
	Manager::shutDown();
}
