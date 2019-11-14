#ifndef __WORLD_MANAGER_H__
#define __WORLD_MANAGER_H__

#include "Manager.h"
#include <vector>
#include "Object.h"


#define WM df::WorldManager::getInstance()
const int MAX_ALTITUDE = 4;

namespace df {
	static int id_count = 0;
	class WorldManager : public Manager {
	
	private:
		WorldManager(); //singleton
		WorldManager(WorldManager const&);
		void operator=(WorldManager const&);

		std::vector<Object*> updates; //all objects in world
		std::vector<Object*> deletions; //all objects in world to delete
	public:
		static WorldManager& getInstance();

		int startUp();

		void shutDown();

		//insert object into world, 0 if ok
		int insertObject(Object *p_o);

		//remove from world, 0 if ok
		int removeObject(Object *p_o);

		//return list of all objects in world
		std::vector<Object*> getAllObjects() const;

		//update world + delete objects marked for deletion
		void update();

		//indicate object is to be deleted at end of current game loop, 0 if ok
		int markForDelete(Object *p_o);

		std::vector<Object*> objectsOfType(std::string type) const;
	
		void printAllObjects(std::vector<Object*> list);

		void draw();
	};
}

#endif
