#include "Vector.h"
#include <math.h>
using namespace df;

Vector::Vector() {
	m_x = 0;
	m_y = 0;
}

Vector::Vector(float init_x, float init_y) {
	m_x = init_x;
	m_y = init_y;
}

float Vector::getMagnitude() const{
	float m = sqrt(m_x*m_x + m_y*m_y);
	return m;
}

void Vector::scale(float s) {
	m_x = m_x * s;
	m_y = m_y * s;
}

//change length to 1
void Vector::normalize() {
	float length = getMagnitude();
	if (length > 0) {
		m_x = m_x / length;
		m_y = m_y / length;
	}

}

//add 2 vectors together and return sum
Vector Vector::operator+(const Vector &other) const{
	Vector v; //make new vector
	v.m_x = m_x + other.m_x;
	v.m_y = m_y + other.m_y;
	return v;
}

//subtracts 2 vectors and return result
Vector Vector::operator-(const Vector& other) const {
	Vector v; //make new vector
	v.m_x = m_x - other.m_x;
	v.m_y = m_y - other.m_y;
	return v;
}

//multiplies 2 vectors together and return result
Vector Vector::operator*(const Vector& other) const {
	Vector v; //make new vector
	v.m_x = m_x * other.m_x;
	v.m_y = m_y * other.m_y;
	return v;
}

//divides 2 vectors and return result
Vector Vector::operator/(const Vector& other) const {
	Vector v; //make new vector
	v.m_x = m_x / other.m_x;
	v.m_y = m_y / other.m_y;
	return v;
}

//add 2 vectors and return sum
bool Vector::equals(const Vector& other) const {
	if (m_x == other.m_x && m_y == other.m_y) {
		return true;
	}
	else {
		return false;
	}
}

void Vector::setX(float new_x) {
	m_x = new_x;
}

float Vector::getX() const {
	return m_x;
}

void Vector::setY(float new_y) {
	m_y = new_y;
}

float Vector::getY() const {
	return m_y;
}

void Vector::setXY(float new_x, float new_y) {
	m_x = new_x;
	m_y = new_y;
}