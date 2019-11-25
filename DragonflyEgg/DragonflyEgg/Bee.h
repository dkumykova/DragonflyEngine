#ifndef __BEE_H__
#define __BEE_H__

#include "Object.h"

namespace df {
	class Bee : public Object {
	private:
		int frame; //keep track of frame num for animation
		Animation a;
	public:
		Bee();
		int eventHandler(const Event* p_e);
		~Bee();
	};
}

#endif