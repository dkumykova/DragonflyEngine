#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <string>
#include "Vector.h"
#include "Event.h"
#include "Box.h"

namespace df {
	enum Solidness {
		HARD, //object causes collision and impedes
		SOFT, //object causes collisiosn but doens't impede
		SPECTRAL //object doesn't cause collisions
	};
	class Object {
		
	private:
		
		int id; //unique game engine defined identifier, defined and set in gameManager
		std::string m_type; //setType()
		Vector position; //position in game world
		int altitude; //0 to MAX, lower drawn first
		Box box; //for sprite boundary + collisions
		Vector direction; 
		float speed; //object speed in direction
		Vector velocity;
		Solidness solidness; 

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

		void Update();

		virtual int eventHandler(const Event *p_e);

		virtual int draw();

		//set altitude ob ject, with checks for range between 0 and MAX
		int setAltitude(int new_alt);

		int getAltitude() const;

		void setBox(Box new_box);

		Box getBox() const;

		void setSpeed(float new_speed);

		float getSpeed() const;

		void setDirection(Vector new_direction);

		Vector getDirection() const;

		void setVelocity(Vector new_vel);

		Vector getVelocity() const;

		//predict object position based ons peed and direction, return prediction
		Vector predictPosition();

		bool isSolid() const; //tru if hard or soft, else false

		//set object solidness with checks for consistency
		int setSolidness(Solidness new_solid);

		Solidness getSolidness() const;
	};
}

#endif