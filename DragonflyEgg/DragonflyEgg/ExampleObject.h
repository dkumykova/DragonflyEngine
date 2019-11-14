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