#include "DisplayManager.h"
#include "LogManager.h"

using namespace df;

DisplayManager::DisplayManager() {
	setType("DisplayManager");
	window = NULL;
	window_horizontal_pixels = WINDOW_HORIZONTAL_PIXELS_DEFAULT;
	window_vertical_pixels = WINDOW_VERTICAL_PIXELS_DEFAULT;
	window_horizontal_chars = WINDOW_HORIZONTAL_CHARS_DEFAULT;
	window_vertical_chars = WINDOW_VERTICAL_CHARS_DEFAULT;
}

DisplayManager &DisplayManager::getInstance() {
	static DisplayManager displayManager;
	return displayManager;
}

int DisplayManager::startUp() {
	if (window != NULL) {
		return 0;
	}

	window = new sf::RenderWindow(sf::VideoMode(window_horizontal_pixels, window_vertical_pixels),
			WINDOW_TITLE_DEFAULT);

	window->setMouseCursorVisible(false);
	window->setVerticalSyncEnabled(true);

	font.loadFromFile(FONT_FILE_DEFAULT);

	//everything went well assume
	//call manager startup to ser is started true
	return 0;

}
//close window
void DisplayManager::shutDown() {
	window->close();
}
//draw characyer at window location x, y with color; 0 if ok
void DisplayManager::drawCh(Vector world_pos, char ch, Color color) const {

}
//return window's horizontal maximum in characters
int DisplayManager::getHorizontal() const {
	return window_horizontal_chars;
}
//return window's vertical maximum in characters
int DisplayManager::getVertical() const {
	return window_vertical_chars;
}
//return horizontal maximum in pixels
int DisplayManager::getHorizontalPixels() const {
	return window_horizontal_pixels;
}
//return vertical maximum in pixels
int DisplayManager::getVerticalPixels() const {
	return window_vertical_pixels;
}
//render current window buffer, return 0 if ok
int DisplayManager::swapBuffers() {
	//do stuff
}
//return pointer to window
sf::RenderWindow* DisplayManager::getWindow() const {
	return window;
}
float DisplayManager::charHeight() {
	return getVerticalPixels() / getVertical();

}
//compute character width, based on window size and font
float DisplayManager::charWidth() {
	return getHorizontalPixels() / getHorizontal();
}
//convert ascii spaces x, y to window pixels x, y
Vector DisplayManager::spacesToPixels(Vector spaces) {
	Vector copy = spaces;
	copy.setX(copy.getX() * charWidth());
	copy.setY(copy.getY() * charHeight());
	return copy;
}
//coonvert window pixels x, y to ascii spaces x, y
Vector DisplayManager::pixelsToSpaces(Vector pixels) {
	Vector copy = pixels;
	copy.setX(copy.getX() / charWidth());
	copy.setY(copy.getY() / charHeight());

	return copy;
}