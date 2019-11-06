#include "WorldManager.h"
#include "LogManager.h"
using namespace df;

WorldManager::WorldManager() {
	setType("WorldManager");
	
	//initialize updates and deletions lists?
}

WorldManager& WorldManager::getInstance() {
	static WorldManager worldManager;
	return worldManager;
}

int WorldManager::startUp() {
	//initialize everything to empty
	
	return 0;
}

void WorldManager::shutDown() {
	std::vector<Object*>::iterator i;
	std::vector<Object*> updatesCopy = updates;
	/*if (updates.size() > 0) {*/
		for (i = updatesCopy.begin(); i != updatesCopy.end(); i++) {
			removeObject((*i));
		}
	//}
	

}

//insert object into world, 0 if ok
int WorldManager::insertObject(Object* p_o) {
	p_o->setId(id_count);
	LM.writeLog("Inserting object %d", p_o->getId());
	updates.push_back(p_o);
	id_count++; //increment id counter to ensure each object has unique identifier within game
	
	return 0;
}

//remove from world, 0 if ok
int WorldManager::removeObject(Object* p_o) {
	std::vector<Object*>::iterator i;
	int count = 0;
	LM.writeLog("All objects before removal of one");
	printAllObjects(updates);
	for (i = updates.begin(); i != updates.end(); i++,count++) {
		//pop last item from end and swap over item to delete
		if ((*i) == p_o) {
			updates.erase(updates.begin() + count);
			LM.writeLog("All objects after removal of one");
			printAllObjects(updates);
			return 0;
		}
	}
	return -1;

}

//return list of all objects in world
std::vector<Object*> WorldManager::getAllObjects() const {
	return updates;
}

//update world + delete objects marked for deletion
void WorldManager::update() {
	std::vector<Object*>::iterator i;
	LM.writeLog("All objects currently in deletions:");
	printAllObjects(deletions);
	for (i = updates.begin(); i != updates.end(); i++) {
		(*i)->Update();
	}

	for (i = deletions.begin(); i != deletions.end(); i++) {
		delete((*i));
	}
	deletions.clear(); //clear for next loop

}

//indicate object is to be deleted at end of current game loop, 0 if ok
//add to deletions list
int WorldManager::markForDelete(Object* p_o) {
	std::vector<Object*>::iterator i;
	for (i = deletions.begin(); i != deletions.end(); i++) {
		if ((*i) == p_o) {
			//object already marked for deletion
			return 0;
		}
	}
	LM.writeLog("Object %d marked for deletion", p_o->getId());
	deletions.push_back(p_o);
	return 0;
}

std::vector<Object*> WorldManager::objectsOfType(std::string type) const {
	std::vector<Object*> objects;
	std::vector<Object*> updatesCopy = updates;
	std::vector<Object*>::iterator i;

	for (i = updatesCopy.begin(); i != updatesCopy.end(); i++) {
		if((*i)->getType() == type) {
			objects.push_back((*i));
		}
	}

	return objects;
}

//prints list of all objects in updates list into LM for debug purposes
void WorldManager::printAllObjects(std::vector<Object*> list) {
	std::vector<Object*>::iterator i;
	

	for (i = list.begin(); i != list.end(); i++) {
		LM.writeLog("Object type %s, id %d, position %f, %f, vector magnitude %f", (*i)->getType().c_str(), 
			(*i)->getId(), (*i)->getPosition().getX(), (*i)->getPosition().getY(), (*i)->getPosition().getMagnitude());
	}

}