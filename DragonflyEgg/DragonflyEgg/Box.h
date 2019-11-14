#ifndef __BOX_H__
#define __BOX_H__

#include "Vector.h"

namespace df {
	class Box {
	private:
		Vector corner; //upper left corner of box 
		float horizontal; //horizontal dimension
		float vertical; //vertical dimension

	public:
		//create box with 0, 0 for corner and 0 for horx and vert
		Box(); 
		//create box with upper let croner, h and v sizes
		Box(Vector init_corner, float init_horiz, float init_vert);
		void setCorner(Vector new_corner);

		Vector getCorner() const;

		void setHorizontal(float new_horiz);

		float getHorizontal() const;

		void setVertical(float new_vert);

		float getVertical() const;
	};
}

#endif