#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include "Manager.h"
#include "Sprite.h"
#include <vector>

#define RM df::ResourceManager::getInstance()

namespace df {
	const int MAX_SPRITES = 1000;

	//delimiters used to parse sprite files; RM knows file format

	const std::string HEADER_TOKEN = "HEADER";
	const std::string BODY_TOKEN = "BODY";
	const std::string FOOTER_TOKEN = "FOOTER";
	const std::string FRAMES_TOKEN = "frames";
	const std::string HEIGHT_TOKEN = "height";
	const std::string WIDTH_TOKEN = "width";
	const std::string COLOR_TOKEN = "color";
	const std::string SLOWDOWN_TOKEN = "slowdown";
	const std::string END_FRAME_TOKEN = "end";
	const std::string VERSION_TOKEN = "version";


	class ResourceManager : public Manager {
	private:
		ResourceManager(); //singleton
		ResourceManager(ResourceManager const&);
		void operator=(ResourceManager const&);
		Sprite* sprites[MAX_SPRITES]; //array of sprites
		int sprite_count; //number of loaded sprites

	public:
		static ResourceManager& getInstance();

		int startUp();
		void shutDown();

		//load sprite from file and assign indidcated label
		int loadSprite(std::string label);

		//find sprite with indicated label
		int unloadSprite(std::string label);

		Sprite* getSprite(std::string label) const;

		//helper functions

		//get next line from file with error checking
		std::string getLine(std::istream *file);

		//read in next section of data from file as vector of strings
		//return vector (empty if error)
		std::vector<std::string> readData(std::istream *file, std::string delim);

		//match token in vector of lines 
		//return corresponding value
		//remove any line that matches from vector
		int matchLineInt(std::vector<std::string> *data, const char *token);

		//same as above but returns string
		std::string matchLineStr(std::vector<std::string> *data, const char *token);

		//match frame lines until "end" clearing all vector
		Frame matchFrame(std::vector<std::string> *data, int width, int height);
	};
}

#endif