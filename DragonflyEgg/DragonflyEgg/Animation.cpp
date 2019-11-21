#include "Animation.h"
#include "LogManager.h"

using namespace df;

Animation::Animation() {
	name = "";
	index = 0;
	slowdown_count = 0;
	sprite = NULL;
}

//set associated sprite to new one; sprite is managed by RM
//set sprite index to 0 (first frame)
void Animation::setSprite(Sprite* new_sprite) {
	sprite = new_sprite;
}

//retunr pointer to associated sprite
Sprite* Animation::getSprite() const {
	return sprite;
}

void Animation::setName(std::string new_name) {
	name = new_name;
}

std::string Animation::getName() const {
	return name;
}

//set index of current sprite frame to be displayed
void Animation::setIndex(int new_index) {
	index = new_index;
}

int Animation::getIndex() const {
	return index;
}

void Animation::setSlowdownCount(int new_slowdown) {
	slowdown_count = new_slowdown;
}
//set animation slowdown count, -1 means stop animation
int Animation::getSlowdownCount() const {
	return slowdown_count;
}

//draw single frame centered at x, y
//drawing accounts for slowdown and advances sprite frame
int Animation::draw(Vector position) {
	if (sprite == NULL) {
		LM.writeLog("Sprite is null in animation draw call");
		return -1;
	}

	//ask sprite to draw current frame
	index = getIndex();
	sprite->draw(index, position);

	//if slowdown count is -1, animation is froxen
	if (getSlowdownCount() == -1) {
		return -1;
	}

	//incrememnt counter
	int count = getSlowdownCount();
	count++;

	//advance sprite index if appropriate
	if (count >= getSlowdownCount()) {
		count = 0;
		index++;

		//if at last frame, loop to beginning
		if (index >= sprite->getFrameCount()) {
			index = 0;
		}

		//set index for next draw
		setIndex(index);
	}

	//set counter for next draw
	setSlowdownCount(count);

}