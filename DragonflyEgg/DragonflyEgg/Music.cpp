#include "Music.h"
#include "LogManager.h"

using namespace df;


Music::Music() {

}
int Music::loadMusic(std::string filename) {
	if (music.openFromFile(filename) == false) {
		LM.writeLog("Error loading music file!");
		return -1;
	}
	return 0;
}
void Music::setLabel(std::string new_label) {
	label = new_label;
}
std::string Music::getLabel() const {
	return label;
}
void Music::play(bool loop) {
	music.play();
}
void Music::stop() {
	music.stop();
}
void Music::pause() {
	music.pause();
}
sf::Music* Music::getMusic() {
	sf::Music* pointer = &music;
	return pointer;
}