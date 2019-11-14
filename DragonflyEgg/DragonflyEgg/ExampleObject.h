#ifndef __EXAMPLE_OBJECT_H__
#define __EXAMPLE_OBJECT_H__

#include "Object.h"

namespace df {
	class ExampleObject : public Object {
	public:
		ExampleObject();
		int eventHandler(Event* p_e);
		~ExampleObject();
		int draw();
	};
}

#endif