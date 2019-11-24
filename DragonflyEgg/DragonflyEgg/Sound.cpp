#include "Sound.h"
#include "ResourceManager.h"
#include "LogManager.h"
using namespace df;

Sound::Sound() {
	sound_buffer = sf::SoundBuffer();
}
Sound::~Sound() {
	sound.resetBuffer();
}

//load sound bugger from file
int Sound::loadSound(std::string filename) {
	

	if (sound_buffer.loadFromFile(filename) == false) {
		LM.writeLog("Error loading sound!");
		return -1;
	}
	
	sound.setBuffer(sound_buffer);
	
}

void Sound::setLabel(std::string new_label) {
	label = new_label;
}

std::string Sound::getLabel() const {
	return label;
}

void Sound::play(bool loop) {
	if (loop) {
		sound.setLoop(true);
	}
	sound.play();
}

void Sound::stop() {
	sound.stop();
}

void Sound::pause() {
	sound.pause();
}

sf::Sound Sound::getSound() const {
	return sound;
}