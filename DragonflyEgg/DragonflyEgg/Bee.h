#include "Object.h"

namespace df {
	class Bee : public Object {
	public:
		Bee();
		int eventHandler(Event* p_e);
		~Bee();
		int draw();
	};
}