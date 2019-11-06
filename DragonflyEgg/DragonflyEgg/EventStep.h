#ifndef __STEP_EVENT_H__
#define __STEP_EVENT_H__

#include "Event.h"

namespace df {
	const std::string STEP_EVENT = "df::step";

	class EventStep : public Event {
	private:
		int m_step_count; //iteration number of game loop
	public:
		EventStep();

		//initialize with specific step count
		EventStep(int init_step_count);

		void setStepCount(int new_step_count);

		int getStepCount() const;
	};
}


#endif
