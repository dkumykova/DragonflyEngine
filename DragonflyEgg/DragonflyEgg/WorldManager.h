#ifndef __WORLD_MANAGER_H__
#define __WORLD_MANAGER_H__

#include "Manager.h"
#include <vector>
#include "Object.h"
#include "utility.h"


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
		Utility u;
		Box boundary; //world boundary
		Box view; //player view of game world

		Object* view_following; //object view is following

	public:
		static WorldManager& getInstance();

		int startUp();

		void shutDown();

		//insert object into world, 0 if ok
		int insertObject(Object* p_o);

		//remove from world, 0 if ok
		int removeObject(Object* p_o);

		//return list of all objects in world
		std::vector<Object*> getAllObjects() const;

		//update world + delete objects marked for deletion
		void update();

		//indicate object is to be deleted at end of current game loop, 0 if ok
		int markForDelete(Object* p_o);

		std::vector<Object*> objectsOfType(std::string type) const;

		void printAllObjects(std::vector<Object*> list);

		void draw();

		//return list of objects collided with at position "where"
		//collisions only with solid objects
		//does not consider if obj is solid or not
		std::vector<Object*> getCollisions(Object* obj, Vector where) const;

		//move object
		//if collision with solid, send collision events
		//if no collision with solid, move ok else don't move object
		//if object is spectral, move ok
		//return 0 if move ok, else -1 if collision with solid
		int moveObject(Object* obj, Vector where);

		void setBoundary(Box new_boundary);

		Box getBoundary() const;

		void setView(Box new_view);

		Box getView() const;

		//set view to center window on position view_pos, view edge will not
		//go beyond world boundary
		void setViewPosition(Vector view_pos);

		//set view to center window on object
		//set to null to stop follinwg
		//if new_view_following not legit, return -1
		int setViewFollowing(Object *new_view_following);
	};
}

#endif
