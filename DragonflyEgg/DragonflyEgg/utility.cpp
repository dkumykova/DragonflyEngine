#include "utility.h"
#include <math.h>
#include "WorldManager.h"

using namespace df;

Utility::Utility() {

}

bool Utility::positionsIntersect(Vector p1, Vector p2) const{
	if (fabsf(p1.getX() - p2.getX()) <= 1 && fabsf(p1.getY() - p2.getY()) <= 1) {
		return true;
	}
	else {
		return false;
	}
}

bool Utility::boxIntersectsBox(Box A, Box B) const{
	//test horizontal overlap
	float widthB = B.getHorizontal();
	float heightB = B.getVertical();
	float widthA = A.getHorizontal();
	float heightA = A.getVertical();
	

	float bx1 = B.getCorner().getX();
	float ax1 = A.getCorner().getX();
	float bx2 = B.getCorner().operator+(Vector(widthB, 0)).getX();
	float ax2 = A.getCorner().operator+(Vector(widthA, 0)).getX();

	float by1 = B.getCorner().getY();
	float ay1 = A.getCorner().getY();
	float by2 = B.getCorner().operator+(Vector(0, heightB)).getY();
	float ay2 = A.getCorner().operator+(Vector(0, heightA)).getY();

	bool x_overlap = false;
	bool y_overlap = false;

	if ((bx1 <= ax1 && ax1 <= bx2) || (ax1 <= bx1 && bx1 <= ax2)) {
		//x overlap!
		x_overlap = true;
	}

	if ((by1 <= ay1 && ay1 <= by2) || (ay1 <= by1 && by1 <= ay2)) {
		//y overlap!
		y_overlap = true;
	}

	if (x_overlap && y_overlap) {
		return true;
	}
	else {
		return false;
	}

}

Box Utility::getWorldBox(const Object *obj) const{
	Box temp = obj->getBox();
	Vector corner = temp.getCorner();
	corner.setX(corner.getX() + obj->getPosition().getX());
	corner.setY(corner.getY() + obj->getPosition().getY());

	temp.setCorner(corner);

	return temp;
}

Vector Utility::worldToView(Vector world_pos) const {
	Vector view_origin = WM.getView().getCorner();
	int view_x = view_origin.getX();
	int view_y = view_origin.getY();
	Vector view_pos(world_pos.getX() - view_x, world_pos.getY() - view_y);

	return view_pos;
}
