#include "EventCollision.h"

using namespace df;

EventCollision::EventCollision() {
	p_obj1 = NULL;
	p_obj2 = NULL;
	pos = Vector();
}

EventCollision::EventCollision(Object* obj1, Object* obj2, Vector p) {
	p_obj1 = obj1;
	p_obj2 = obj2;
	pos = p;
}

//object that caused collision
void EventCollision::setObject1(Object* new_obj) {
	p_obj1 = new_obj;
}

Object* EventCollision::getObject1() const {
	return p_obj1;
}

//object collided with
void EventCollision::setObject2(Object* new_obj) {
	p_obj2 = new_obj;
}

Object* EventCollision::getObject2() const {
	return p_obj2;
}

//set position of collision
void EventCollision::setPosition(Vector new_pos) {
	pos = new_pos;
}

Vector EventCollision::getPosition() const {
	return pos;
}