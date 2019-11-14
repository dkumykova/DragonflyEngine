#include "Object.h"
#include "LogManager.h"
#include "WorldManager.h"
using namespace df;

Object::Object() {
	//id = id_count;
	m_type = "Object";
	position = Vector();
	WM.insertObject(this);
	LM.writeLog("Object base constructor called");
	altitude = MAX_ALTITUDE / 2;
	//add to wm
	//id_count++;
}

Object::~Object() {
	//remove from wm
	LM.writeLog("Object base destructor called");
	WM.removeObject(this);
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

void Object::Update() {
	//do update stuff here
	LM.writeLog("Object %d update called", id);
	Vector pos = Vector(2, 3); //test vector setting
	this->setPosition(pos);
	//this->getPosition().setXY(2, 3);
}

int Object::eventHandler(const Event *p_e) {
	LM.writeLog("Object base event handler called");
	return 0;
}

int Object::draw() {
	LM.writeLog("Object draw called");
	return 0;
}

int Object::setAltitude(int new_alt) {
	if (new_alt >= 0 && new_alt <= MAX_ALTITUDE) {
		altitude = new_alt;
		return 0;
	} else {
		return -1;
	}
	
	
}

int Object::getAltitude() const {
	return altitude;
}