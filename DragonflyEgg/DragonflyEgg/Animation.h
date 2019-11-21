#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "Sprite.h"
#include <string>

namespace df {
	class Animation {
	private:
		Sprite* sprite; //sprite associated with animation
		std::string name; //sprite name in resource manager
		int index; //current index frame for sprite
		int slowdown_count; //slowdown counter

	public:
		Animation();

		//set associated sprite to new one; sprite is managed by RM
		//set sprite index to 0 (first frame)
		void setSprite(Sprite *new_sprite);

		//retunr pointer to associated sprite
		Sprite* getSprite() const;

		void setName(std::string new_name);

		std::string getName() const;

		//set index of current sprite frame to be displayed
		void setIndex(int new_index);

		int getIndex() const;

		void setSlowdownCount(int new_slowdown);

		//set animation slowdown count, -1 means stop animation
		int getSlowdownCount() const;

		//draw single frame centered at x, y
		//drawing accounts for slowdown and advances sprite frame
		int draw(Vector position);
	};
}

#endif