#ifndef __BEE_H__
#define __BEE_H__

#include "Object.h"

namespace df {
	class Bee : public Object {
	public:
		Bee();
		int eventHandler(const Event* p_e);
		~Bee();
		int draw();
	};
}

#endif