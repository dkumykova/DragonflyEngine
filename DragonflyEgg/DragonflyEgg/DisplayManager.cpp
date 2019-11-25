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
	u = Utility();
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
	window->setKeyRepeatEnabled(false); //disable keyboard repeat so can hold down buttons
	


	LM.writeLog("DisplayManager startup called");
	//everything went well assume
	//call manager startup to ser is started true
	Manager::startUp();

	LM.writeLog("Vertical chars, should be 24: %d", getVertical());
	LM.writeLog("Horizontal chars, should be 80: %d", getHorizontal());
	LM.writeLog("Horizontal pixels, should be 1024: %d", getHorizontalPixels());
	LM.writeLog("Vertical pixels, should be 768: %d", getVerticalPixels());
	//test spaces to pixels and back here
	return 0;

}
//close window
void DisplayManager::shutDown() {
	LM.writeLog("DisplayManager shutdown called	");
	Manager::shutDown();
	window->close();
}
//draw characyer at window location x, y with color; 0 if ok
int DisplayManager::drawCh(Vector world_pos, char ch, Color color) const {
	if (window == NULL) {
		return -1;
	}
	Vector view_pos = u.worldToView(world_pos);
	//convert spaces x,y to pixels x, y
	Vector pixel_pos = spacesToPixels(world_pos);

	//draw background rectangle since text is see through in sfml
	static sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(charWidth(), charHeight()));
	rectangle.setFillColor(WINDOW_BACKGROUND_COLOR_DEFAULT);
	rectangle.setPosition(pixel_pos.getX() - charWidth()/10,
							pixel_pos.getY() + charHeight()/5);
	window->draw(rectangle);

	//create character to draw
	static sf::Text text("", font);
	text.setString(ch);
	text.setStyle(sf::Text::Bold); //bolder looks better

	//scale to right size
	if (charWidth() < charHeight()) {
		text.setCharacterSize(charWidth() * 2);
	}
	else {
		text.setCharacterSize(charHeight() * 2);
	}
	//int count = 1;
	//set sfml color based on dragonfly color
	switch (color) {
	case YELLOW:
		text.setFillColor(sf::Color::Yellow);
		//LM.writeLog("Setting character color to yellow");
		break;
	case RED:
		text.setFillColor(sf::Color::Red);
		//LM.writeLog("Setting character color to red");
		break;
	case WHITE:
		text.setFillColor(sf::Color::White);
		//LM.writeLog("Setting character color to white");
		break;
	case GREEN:
		text.setFillColor(sf::Color::Green);
		//LM.writeLog("Setting character color to yellow");
		break;
	case BLUE:
		text.setFillColor(sf::Color::Blue);
		//LM.writeLog("Setting character color to red");
		break;
	case MAGENTA:
		text.setFillColor(sf::Color::Magenta);
		//LM.writeLog("Setting character color to white");
		break;
	case CYAN:
		text.setFillColor(sf::Color::Cyan);
		//LM.writeLog("Setting character color to yellow");
		break;
	default:
		break;
	}
	//set position in window in pixels
	text.setPosition(pixel_pos.getX(), pixel_pos.getY());

	window->draw(text);
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
	LM.writeLog("swap buffers called");
	if (window == NULL) {
		return -1;
	}

	//show current window
	window->display();

	//clear other window to get ready for next draw
	window->clear();

	return 0;
}
//return pointer to window
sf::RenderWindow* DisplayManager::getWindow() const {
	return window;
}
float DisplayManager::charHeight() const{
	return getVerticalPixels() / getVertical();

}

//compute character width, based on window size and font
float DisplayManager::charWidth() const{
	return getHorizontalPixels() / getHorizontal();
}
//convert ascii spaces x, y to window pixels x, y
Vector DisplayManager::spacesToPixels(Vector spaces) const {
	Vector copy = spaces;
	copy.setX(copy.getX() * charWidth());
	copy.setY(copy.getY() * charHeight());
	return copy;
}
//coonvert window pixels x, y to ascii spaces x, y
Vector DisplayManager::pixelsToSpaces(Vector pixels) const{
	Vector copy = pixels;
	copy.setX(copy.getX() / charWidth());
	copy.setY(copy.getY() / charHeight());

	return copy;
}

int DisplayManager::drawString(Vector pos, std::string str, Justification just, Color color) const{

	//get starting position
	Vector starting_pos = pos;

	switch (just) {
	case CENTER_JUSTIFIED:
		starting_pos.setX(pos.getX() - str.size() / 2);
		break;
	case RIGHT_JUSTIFIED:
		starting_pos.setX(pos.getX() - str.size());
		break;
	case LEFT_JUSTIFIED:
	default:
		break;
	}

	//draw string character by character
	for (int i = 0; i < str.size(); i++) {
		Vector temp_pos(starting_pos.getX() + i, starting_pos.getY());
		drawCh(temp_pos, str[i], color);
	}

	return 0;
}

//implement if have time
bool DisplayManager::setBackgroundColor(int new_color) {
	return true;
}