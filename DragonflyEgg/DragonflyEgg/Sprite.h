#ifndef __SPRITE_H__
#define __SPRITE_H__
#include "Frame.h"

namespace df {
	class Sprite {
	private:
		int width;
		int height;
		int max_frame_count; //max num frames sprite can have
		int frame_count; 
		Color color; //optional
		int slowdown; //animation slowdown, 1 = none, 0 = stop
		Frame* frames; //array of frames
		std::string label; //text label to identify sprite
		Sprite(); //sprite always has 1 arg, frame count

	public:
		~Sprite();
		Sprite(int max_frames);

		void setWidth(int new_width);

		int getWidth() const;

		void setHeight(int new_height);

		int getHeight() const;

		void setColor(Color new_color);

		Color getColor() const;

		int getFrameCount() const;

		//return -1 if full
		int addFrame(Frame new_frame);

		Frame getFrame(int frame_num) const;

		void setLabel(std::string new_label);

		std::string getLabel() const;

		//set animation slowdown value; value in multiples of GM frame time
		void setSlowdown(int new_slowdown);

		int getSlowdown() const;

		//draw centered at x, y
		int draw(int frame_num, Vector position) const;
	};
}

#endif