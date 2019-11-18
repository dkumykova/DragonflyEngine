#ifndef __EVENT_OUT_H__
#define __EVENT_OUT_H__

#include "Event.h"

const std::string OUT_EVENT = "df::out";

namespace df {
	class EventOut : public Event {
	public:
		EventOut();
	};
}

#endif