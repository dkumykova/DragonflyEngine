#include "WorldManager.h"
#include "LogManager.h"
#include "EventCollision.h"
#include "DisplayManager.h"
#include "EventOut.h"
using namespace df;

WorldManager::WorldManager() {
	setType("WorldManager");
	u = Utility();
	boundary = Box(Vector(), 0, 0);
	view = Box(Vector(), 0, 0);
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
	for (i = updates.begin(); i != updates.end(); i++, count++) {
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
		//if object changes position, move
		Vector new_pos = (*i)->predictPosition();
		if (new_pos.getX() != (*i)->getPosition().getX() || new_pos.getY() !=
			(*i)->getPosition().getY()) {
			moveObject((*i), new_pos);
		}
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
		if ((*i)->getType() == type) {
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

void WorldManager::draw() {
	//iterates through all objects and calls individual draw methods for each
	std::vector<Object*>::iterator i;
	
	std::vector<Object*> updatesCopy = WM.getAllObjects();
	for (i = updatesCopy.begin(); i != updatesCopy.end(); i++) {
		for (int j = 0; j <= MAX_ALTITUDE; j++) { //draw objects in order of altitude
			if ((*i)->getAltitude() == j) { //if current object alt = iterator
				Box temp = u.getWorldBox((*i));
				if (u.boxIntersectsBox(temp, view)) { //only draw if object visible on window, i.e. insersects view
					(*i)->draw();
				}
			}
		}
	}
}

std::vector<Object*> WorldManager::getCollisions(Object* obj, Vector where) const {
	std::vector<Object*> collisionList;
	std::vector<Object*>::iterator i;

	std::vector<Object*> updatesCopy = WM.getAllObjects();
	Box b = u.getWorldBox(obj);
	
	for (i = updatesCopy.begin(); i != updatesCopy.end(); i++) {
		Object* temp = (*i);
		Box tempBox = u.getWorldBox(temp);
		if (temp != obj) { //don't collide with self
			//use boxIntersectBox here isntead
			if (u.boxIntersectsBox(b, tempBox) && temp->isSolid()) {
				collisionList.push_back(temp);
			}//no solid collisions
			/*if (u.positionsIntersect(temp->getPosition(), where) && temp->isSolid()) {
			} */
		}//not self
	}//end iterate
	return collisionList;
}


int WorldManager::moveObject(Object* obj, Vector where) {
	if (obj->isSolid()) { //check for collisions if solid
		std::vector<Object*> list = getCollisions(obj, where);
		if (!list.empty()) {//if there are any collisions
			bool do_move = true; //assume can move

			std::vector<Object*>::iterator i;

			for (i = list.begin(); i != list.end(); i++) {
				Object* temp = (*i);

				//create collision event
				EventCollision c = EventCollision(obj, temp, where);
				temp->eventHandler(&c);
				obj->eventHandler(&c);
				//if both are hard can't move
				if (obj->getSolidness() == HARD && temp->getSolidness() == HARD) {
					do_move = false;
				}
			}//end iterate
			if (!do_move) {
				return -1; //move not allowed
			}
		}//no collision
	}//object not solid so can move anywhere it wants
	Box orig_box = u.getWorldBox(obj); //original bounding box
	obj->setPosition(where); //move object
	Box new_box = u.getWorldBox(obj); //new bounding box
	if (u.boxIntersectsBox(orig_box, boundary) && !u.boxIntersectsBox(new_box, boundary)) {
		EventOut ev = EventOut();
		LM.writeLog("Sending event out to object!");
		obj->eventHandler(&ev);
	}
	if (view_following == obj) {
		setViewPosition(obj->getPosition());
	}
	/*if (obj->getPosition().getX() < 0 || obj->getPosition().getX() > DM.getHorizontal()
		|| obj->getPosition().getY() < 0 || obj->getPosition().getY() > DM.getVertical()) {

		EventOut ev = EventOut();

		obj->eventHandler(&ev);
	}*/
	return 0;
}

void WorldManager::setBoundary(Box new_boundary) {
	boundary = new_boundary;
}

Box WorldManager::getBoundary() const {
	return boundary;
}

void WorldManager::setView(Box new_view) {
	view = new_view;
}

Box WorldManager::getView() const {
	return view;
}

void WorldManager::setViewPosition(Vector view_pos) {
	//make sure horizontal not out of world boundary
	int x = view_pos.getX() - view.getHorizontal() / 2;
	if (x + view.getHorizontal() > boundary.getHorizontal()) {
		x = boundary.getHorizontal() - view.getHorizontal();
	}
	if (x < 0) {
		x = 0;
	}

	//make sure vertical not out of world boundary
	int y = view_pos.getY() - view.getVertical() / 2;
	if (y + view.getVertical() > boundary.getVertical()) {
		y = boundary.getVertical() - view.getVertical();
	}
	if (y < 0) {
		y = 0;
	}

	//set view
	Vector new_corner = Vector(x, y);
	view.setCorner(new_corner);
}


int WorldManager::setViewFollowing(Object* new_view_following) {
	//set to null to turn off following
	if (new_view_following == NULL) {
		view_following = NULL;
	}

	//iterate over all objects, make sure new view following is one of them, set
	//found to true
	std::vector<Object*>::iterator i;
	bool found = false;
	std::vector<Object*> updatesCopy = WM.getAllObjects();

	for (i = updatesCopy.begin(); i != updatesCopy.end(); i++) {
		if ((*i) == new_view_following) {
			found = true;
		}
	}

	//if found, adjust attribute accordingly and set view position
	if (found) {
		view_following = new_view_following;
		setViewPosition(view_following->getPosition());
		LM.writeLog("Setting new view");
		return 0;
	}
	
	//was not legit and can't change view
	return -1;

	
}