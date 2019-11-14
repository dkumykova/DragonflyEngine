#ifndef __MOUSE_EVENT_H__
#define __MOUSE_EVENT_H__

#include "Event.h"
#include "Vector.h"

enum EventMouseAction {
	UNDEFINED_MOUSE_ACTION = -1,
	CLICKED, PRESSED, MOVED
};

namespace Mouse {
	enum Button {
		UNDEFINED_MOUSE_BUTTON = -1,
		LEFT, RIGHT, MIDDLE
	};
}
namespace df {
	const std::string MSE_EVENT = "df::mouse";

	class EventMouse : public Event {
	private:
		EventMouseAction mouse_action;
		Mouse::Button mouse_button;
		Vector mouse_xy;
	public:
		EventMouse();

		void setMouseAction(EventMouseAction new_action);

		EventMouseAction getMouseAction() const;

		void setMouseButton(Mouse::Button new_button);

		Mouse::Button getMouseButton() const;

		void setMousePosition(Vector new_pos);

		Vector getMousePosition() const;

	};
}


#endif
