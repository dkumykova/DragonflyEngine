#ifndef __FRAME_H__
#define __FRAME_H__
#include "Vector.h"
#include <string>
#include "Color.h"

namespace df {
	class Frame {
	private:
		int width;
		int height;
		std::string frame_str; //all frame characters stored as string

	public:
		Frame();

		Frame(int new_width, int new_height, std::string new_frame_str);

		void setWidth(int new_width);

		int getWidth() const;

		void setHeight(int new_height);

		int getHeight() const;

		void setString(std::string new_frame_str);

		std::string getString() const;

		//draw self, cetnered at position with color
		//top left coord = 0,0
		int draw(Vector position, Color color) const;
	};

}
#endif