#include "ResourceManager.h"
#include "LogManager.h"
#include <string>
#include <iostream>

using namespace df;

ResourceManager::ResourceManager() {
	setType("ResourceManager");
	sprite_count = 0;
	//sprites already initialized
}
ResourceManager &ResourceManager::getInstance() {
	static ResourceManager resourceManager;
	return resourceManager;
}

int ResourceManager::startUp() {
	sprite_count = 0;
	if (Manager::startUp()) {
		LM.writeLog("Error starting resource manager");
		return -1;
	}
}
void ResourceManager::shutDown() {
	delete sprites; //delete array
	Manager::shutDown();
}

//load sprite from file and assign indidcated label
int ResourceManager::loadSprite(std::string label) {
	
	//open file name
	//read all header lines
	//parse header

	//read all body lines
	//new sprite with frame count
	/*for each frame, add frame to sprite*/
	//add label to sprite

	//read all foote rlines
	//parse footer

	//close file

	//add label to sprite
	return 0;
}

//find sprite with indicated label
int ResourceManager::unloadSprite(std::string label) {
	for (int i = 0; i < sprite_count - 1; i++) {
		if (label == sprites[i]->getLabel()) {
			delete sprites[i];

			//scoot over remaining sprites
			for (int j = i; j < sprite_count - 2; j++) {
				sprites[j] = sprites[j + i];
			}

			sprite_count--;
			LM.writeLog("success unloading sprite");
			return 0;
		}
	}
	return -1;
}

Sprite* ResourceManager::getSprite(std::string label) const {
	for (int i = 0; i < sprite_count - 1; i++) {
		if (label == sprites[i]->getLabel()) {
			return sprites[i];
		}
	}
	return NULL; //sprite not found
}

std::string ResourceManager::getLine(std::istream* file) {
	std::string line;
	std::getline(*file, line); //error checking needs to be done
	if (!std::getline(*file, line)) {
		LM.writeLog("Error parsing file");
		return "";
	}

	return line;
	
}

//read in next section of data from file as vector of strings
//return vector (empty if error)
std::vector<std::string> ResourceManager::readData(std::istream* file, std::string delim) {
	std::string begin = "<" + delim + ">"; //section beginning
	std::string end = "</" + delim + ">"; //section ending
	std::vector<std::string> data;
	//check for beginning
	std::string s;
	s = getLine(file);
	if (s != begin) {
		LM.writeLog("Error reading data from file");
		return ;
	}

	//read in data until ending or not found
	s = getLine(file);
	while (s != end && !s.empty()) {
		data.push_back(s);
		s = getLine(file);
	}

	//if ending not found then error
	if (s.empty()) {
		LM.writeLog("Error in read data, empty data");
		return;
	}

	return data;
}

//match token in vector of lines 
//return corresponding value
//remove any line that matches from vector
int ResourceManager::matchLineInt(std::vector<std::string>* data, const char* token) {
	//loop through all lines
	auto i = data->begin(); //vector iterator
	int number;
	while (i != data->end()) {
		if (i->compare(0, strlen(token), token)) {
			number = atoi(*data[i].substr(strlen(token) + 1).c_str()); //atoi on line.substr
			i = data->erase(i); //clear from vector
		}
		else {
			i++;
		}
	}
	return number;
}

//same as above but returns string
std::string ResourceManager::matchLineStr(std::vector<std::string>* data, const char* token) {
	//loop through all lines
	auto i = data->begin(); //vector iterator
	std::string s = 0;
	while (i != data->end()) {
		if (i->compare(0, strlen(token), token)) {
			//s = //line.substr(strlen(token) + 1)
			i = data->erase(i); //clear from vector
		}
		else {
			i++;
		}
	}
	return s;
}

Frame ResourceManager::matchFrame(std::vector<std::string>* data, int width, int height) {
	std::string line;
	std::string frame_str;
	

	for (int i = 1; i < height; i++) {
		line = data->front();

		if (line.length() != width) {
			LM.writeLog("error with frame line width");
			return Frame();
		}
		data->erase(data->begin());
		frame_str += line;
	}

	line = data->front();
	if (line != END_FRAME_TOKEN) {
		LM.writeLog("error with frame file end");
		return Frame();
	}

	data->erase(data->begin());
	Frame f = Frame(width, height, frame_str);

	return f;

}