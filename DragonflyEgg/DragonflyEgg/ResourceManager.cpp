#include "ResourceManager.h"
#include "LogManager.h"
#include <string>
#include <iostream>

using namespace df;

ResourceManager::ResourceManager() {
	setType("ResourceManager");
	//sprite_count = 0;
	//sprites already initialized
	sound_count = 0;
	music_count = 0;
}
ResourceManager &ResourceManager::getInstance() {
	static ResourceManager resourceManager;
	return resourceManager;
}

int ResourceManager::startUp() {
	//sprite_count = 0;
	if (Manager::startUp()) {
		LM.writeLog("Error starting resource manager");
		return -1;
	}
}
void ResourceManager::shutDown() {
	//delete sprites; //delete array
	Manager::shutDown();
}
int ResourceManager::loadSound(std::string filename, std::string label) {
	if (sound_count == MAX_SOUNDS) {
		LM.writeLog("Sound array full");
		return -1;
	}

	if (sound[sound_count].loadSound(filename) == -1) {
		LM.writeLog("Unable to load from file in RM");
		return -1;
	}

	//all set
	sound[sound_count].setLabel(label);
	sound_count++;
	return 0;
}

int ResourceManager::unloadSound(std::string label) {
	for (int i = 0; i < sound_count; i++) {
		if (label == sound[i].getLabel()) {
			//scoot over remaining sounds
			for (int j = 0; j < sound_count - 2; j++) {
				sound[j] = sound[j + 1];
			}

			sound_count--;
			return 0;
		}
	}
	return -1; //sound not found
}

Sound* ResourceManager::getSound(std::string label) {
	for (int i = 0; i < sound_count; i++) {
		if (label == sound[i].getLabel()) {
			return &sound[i];

		}
	}
	return NULL; //sound not found
}

int ResourceManager::loadMusic(std::string filename, std::string label) {
	if (music_count == MAX_MUSICS) {
		LM.writeLog("Music array full");
		return -1;
	}

	if (music[music_count].loadMusic(filename) == -1) {
		LM.writeLog("Unable to load from file in RM");
		return -1;
	}

	//all set
	music[music_count].setLabel(label);
	music_count++;
	return 0;
}

int ResourceManager::unloadMusic(std::string label) {
	for (int i = 0; i < music_count; i++) {
		if (label == music[i].getLabel()) {
			//scoot over remaining sounds
			music[i].setLabel("");

			music_count--;
			return 0;
		}
	}
	return -1; //sound not found
}

Music* ResourceManager::getMusic(std::string label) {
	for (int i = 0; i < music_count; i++) {
		if (label == music[i].getLabel()) {
			return &music[i];

		}
	}
	return NULL; //music not found
}

