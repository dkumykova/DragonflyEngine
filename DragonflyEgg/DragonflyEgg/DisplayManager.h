#ifndef __DISPLAY_MANAGER_H__
#define __DISPLAY_MANAGER_H__

#include "Manager.h"
#include "SFML/Graphics.hpp"
#include "Color.h"
#include "Vector.h"

#define DM df::DisplayManager::getInstance()
//defaults for SFML window
const int WINDOW_HORIZONTAL_PIXELS_DEFAULT = 1024;
const int WINDOW_VERTICAL_PIXELS_DEFAULT = 768;
const int WINDOW_HORIZONTAL_CHARS_DEFAULT = 80;
const int WINDOW_VERTICAL_CHARS_DEFAULT = 24;
const int WINDOW_STYLE_DEFAULT = sf::Style::Titlebar;
const sf::Color WINDOW_BACKGROUND_COLOR_DEFAULT = sf::Color::Black;
const std::string WINDOW_TITLE_DEFAULT = "Dragonfly";
const std::string FONT_FILE_DEFAULT = "df-font.ttf";

namespace df {

	class DisplayManager : public Manager {
	private:
		DisplayManager(); //singleton! therefore private
		DisplayManager(DisplayManager const&); //don't allow copies
		void operator = (DisplayManager const&); //don't allow assignment
		
		sf::RenderWindow *window;
		sf::Font font;
		int window_horizontal_pixels;  //x pixels in window
		int window_vertical_pixels; //y pixels in window
		int window_horizontal_chars; //x ascii spaces in window
		int window_vertical_chars; //y ascii spaces in window

	public:

		static DisplayManager &getInstance();
		//sopen graphics window, ready for text based display
		//0 if ok
		int startUp();
		//close window
		void shutDown();
		//draw characyer at window location x, y with color; 0 if ok
		void drawCh(Vector world_pos, char ch, Color color) const;
		//return window's horizontal maximum in characters
		int getHorizontal() const;
		//return window's vertical maximum in characters
		int getVertical() const;
		//return horizontal maximum in pixels
		int getHorizontalPixels() const;
		//return vertical maximum in pixels
		int getVerticalPixels() const;
		//render current window buffer, return 0 if ok
		int swapBuffers();
		//return pointer to window
		sf::RenderWindow* getWindow() const;
		//computer character height, based on window size and font
		float charHeight();
		//compute character width, based on window size and font
		float charWidth();
		//convert ascii spaces x, y to window pixels x, y
		Vector spacesToPixels(Vector spaces);
		//coonvert window pixels x, y to ascii spaces x, y
		Vector pixelsToSpaces(Vector pixels);
		
	};
}
#endif
