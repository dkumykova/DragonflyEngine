#ifndef __UTILITY_H__
#define __UTILITY_H__

#include "Vector.h"
namespace df {
	class Utility {
	public:
		Utility();
		
		bool positionsIntersect(Vector p1, Vector p2) const;
	};
}

#endif
