#include <string>
#ifndef __EVENT_H__
#define __EVENT_H__

namespace df {
	const std::string UNDEFINED_EVENT = "df::undefined";
	class Event {
	private:
		std::string event_type;
	public:
		Event();

		//define in child classes
		virtual ~Event();

		void setType(std::string new_type);

		std::string getType() const;
	};
}

#endif
