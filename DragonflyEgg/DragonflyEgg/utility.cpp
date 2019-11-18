#include "utility.h"
#include <math.h>

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