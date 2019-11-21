#ifndef __UTILITY_H__
#define __UTILITY_H__

#include "Vector.h"
#include "Box.h"
#include "Object.h"
namespace df {
	class Utility {
	public:
		Utility();
		
		bool positionsIntersect(Vector p1, Vector p2) const;

		
		bool boxIntersectsBox(Box A, Box B);

		Box getWorldBox(const Object *obj);
	};
}

#endif
