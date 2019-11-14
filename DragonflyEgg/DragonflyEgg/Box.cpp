#include "Box.h"

using namespace df;

//create box with 0, 0 for corner and 0 for horx and vert
Box::Box() {
	corner = Vector();
	horizontal = 0;
	vertical = 0;
}
//create box with upper let croner, h and v sizes
Box::Box(Vector init_corner, float init_horiz, float init_vert) {
	corner = init_corner;
	horizontal = init_horiz;
	vertical = init_vert;
}

void Box::setCorner(Vector new_corner) {
	corner = new_corner;
}

Vector Box::getCorner() const {
	return corner;
}

void Box::setHorizontal(float new_horiz) {
	horizontal = new_horiz;
}

float Box::getHorizontal() const {
	return horizontal;
}

void Box::setVertical(float new_vert) {
	vertical = new_vert;
}

float Box::getVertical() const {
	return vertical;
}