#ifndef __EXAMPLE_OBJECT_H__
#define __EXAMPLE_OBJECT_H__

#include "Object.h"
#include "EventKeyboard.h"

namespace df {
	class ExampleObject : public Object {
	private:
		int move_slowdown;
		int move_countdown;
		Animation a;
	public:
		ExampleObject();
		int eventHandler(const Event* p_e);
		~ExampleObject();
		//int draw();
		void move(int dy, int direction);
		void step();
		void kbd(const EventKeyboard* p_key_event);

	};
}

#endif