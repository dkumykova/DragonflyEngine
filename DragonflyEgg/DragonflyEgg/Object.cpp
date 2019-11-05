#include "Object.h"

using namespace df;

Object::Object() {
	//id = id_count;
	m_type = "Object";
	position = Vector();

	//add to wm
	//id_count++;
}

Object::~Object() {
	//remove from wm
}

void Object::setId(int new_id) {
	id = new_id;
}

int Object::getId() const{
	return id;
}

void Object::setType(std::string new_type) {
	m_type = new_type;
}

std::string Object::getType() const {
	return m_type;
}

void Object::setPosition(Vector new_pos) {
	position = new_pos;
}

Vector Object::getPosition() const {
	return position;
}