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
	box = Box(Vector(), 1, 1); //initialize to unit box of 1 by 1
	speed = 0;
	direction = Vector();
	velocity = Vector();
	setSolidness(HARD);
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

int Object::getId() const {
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
	//Vector pos = Vector(2, 3); //test vector setting
	//this->setPosition(pos);
	//this->getPosition().setXY(2, 3);
}

int Object::eventHandler(const Event* p_e) {
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
	}
	else {
		return -1;
	}


}

int Object::getAltitude() const {
	return altitude;
}

void Object::setBox(Box new_box) {
	box = new_box;
}

Box Object::getBox() const {
	return box;
}

void Object::setSpeed(float new_speed) {
	speed = new_speed;
}

float Object::getSpeed() const {
	return speed;
}

void Object::setDirection(Vector new_direction) {
	direction = new_direction;
}

Vector Object::getDirection() const {
	return direction;
}

void Object::setVelocity(Vector new_vel) {
	velocity = new_vel;
}

//based on speed and direction
Vector Object::getVelocity() const {
	Vector v = getDirection();
	v.scale(speed);
	return v;
}

//predict object position based ons peed and direction, return prediction
Vector Object::predictPosition() {
	//add velocity to position
	Vector new_pos = getVelocity().operator+(getPosition());

	//return new position
	return new_pos;
}

bool Object::isSolid() const {
	if (solidness == HARD || solidness == SOFT) {
		return true;
	}
	else {
		return false;
	}
}

int Object::setSolidness(Solidness new_solid) {
	solidness = new_solid;
	return 0;
}

Solidness Object::getSolidness() const {
	return solidness;
}