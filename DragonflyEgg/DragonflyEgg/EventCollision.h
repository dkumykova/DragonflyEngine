#ifndef __EVENT_COLLISION_H__
#define __EVENT_COLLISION_H__


#include "Event.h"
#include "Object.h"
const std::string COLLISION_EVENT = "df::collision";

namespace df {
	class EventCollision : public Event {
	private: 
		Vector pos; //where collision occurred
		Object* p_obj1; //object moving, causing the collision
		Object* p_obj2; //object being collided with

	public:
		//pos 0, 0, obj1 and obj2 are null
		EventCollision();

		EventCollision(Object* obj1, Object* obj2, Vector p);

		//object that caused collision
		void setObject1(Object *new_obj);

		Object* getObject1() const;

		//object collided with
		void setObject2(Object *new_obj);

		Object* getObject2() const;

		//set position of collision
		void setPosition(Vector new_pos);

		Vector getPosition() const;


	};
}


#endif