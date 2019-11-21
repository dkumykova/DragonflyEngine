#include "Sprite.h"
#include "LogManager.h"
using namespace df;

Sprite::Sprite() {
	width = 0;
	height = 0;
	frame_count = 0;
	frames = new Frame[frame_count];
	color = COLOR_DEFAULT;
	max_frame_count = 0;
}
Sprite::~Sprite() {
	LM.writeLog("sprite destructor called");
	if (frames != NULL) {
		delete frames; //delete array
	}
}
Sprite::Sprite(int max_frames) {
	width = 0;
	height = 0;
	frame_count = 0;
	frames = new Frame[frame_count];
	color = COLOR_DEFAULT;
	max_frame_count = max_frames;
}

void Sprite::setWidth(int new_width) {
	width = new_width;
}

int Sprite::getWidth() const {
	return width;
}

void Sprite::setHeight(int new_height) {
	height = new_height;
}

int Sprite::getHeight() const {
	return height;
}

void Sprite::setColor(Color new_color) {
	color = new_color;
}

Color Sprite::getColor() const {
	return color;
}

int Sprite::getFrameCount() const {
	return frame_count;
}

//return -1 if full
int Sprite::addFrame(Frame new_frame) {
	if (frame_count == max_frame_count) {
		//full
		return -1;
	}
	else {
		frames[frame_count] = new_frame;
		frame_count++;
	}


}

Frame Sprite::getFrame(int frame_num) const {
	if (frame_num < 0 || frame_num >= frame_count) {
		Frame empty = Frame();
		return empty;
	}
	return frames[frame_num];
}

void Sprite::setLabel(std::string new_label) {
	label = new_label;
}

std::string Sprite::getLabel() const {
	return label;
}

//set animation slowdown value; value in multiples of GM frame time
void Sprite::setSlowdown(int new_slowdown) {
	slowdown = new_slowdown;
}

int Sprite::getSlowdown() const {
	return slowdown;
}

//draw centered at x, y
int Sprite::draw(int frame_num, Vector position) const {
	if (frame_num < 0 || frame_num >= frame_count) {
		return -1;
	}

	Frame copy = frames[frame_num];
	copy.draw(position, color);
	return 0;
}