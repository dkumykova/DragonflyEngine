#include "Frame.h"
#include "DisplayManager.h"
using namespace df;

Frame::Frame() {
	height = 0;
	width = 0;
	frame_str = "";
}

Frame::Frame(int new_width, int new_height, std::string new_frame_str) {
	height = new_height;
	width = new_width;
	frame_str = new_frame_str;
}

void Frame::setWidth(int new_width) {
	width = new_width;
}

int Frame::getWidth() const {
	return width;
}

void Frame::setHeight(int new_height) {
	height = new_height;
}

int Frame::getHeight() const {
	return height;
}

void Frame::setString(std::string new_frame_str) {
	frame_str = new_frame_str;
}

std::string Frame::getString() const {
	return frame_str;
}

//draw self, cetnered at position with color
//top left coord = 0,0
int Frame::draw(Vector position, Color color) const {
	if (frame_str.empty()) {
		//emtpy string is bad
		return -1;
	}

	//determine offset since centered at position
	int x_offset = getWidth() / 2;
	int y_offset = getHeight() / 2;

	//draw character by character
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			Vector temp_pos = Vector(position.getX() + x - x_offset,
				position.getY() + y - y_offset);

			DM.drawCh(temp_pos, frame_str[y*width + x], color);
		}//x

	}//y
}