#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>
#include "Vector.h"

namespace df {
	class Object {
		
	private:
		//static int id_count = 0;
		int id; //unique game engine defined identifier
		std::string m_type; //setType()
		Vector position; //position in game world

	public:
		//construct object, set default params + add to game world (WM)
		Object();

		//destroy and remove from WM
		virtual ~Object();

		void setId(int new_id);

		int getId() const;

		void setType(std::string new_type);

		std::string getType() const;

		void setPosition(Vector new_pos);

		Vector getPosition() const;

	};
}

#endif