#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include "Manager.h"
#include "Sprite.h"
#include <vector>
#include "SpriteResourceManager.h"
#include "Music.h"
#include "Sound.h"

#define RM df::ResourceManager::getInstance()

namespace df {
	const int MAX_SOUNDS = 128;
	const int MAX_MUSICS = 128;


	class ResourceManager : public SpriteResourceManager {
	private:
		ResourceManager(); //singleton
		ResourceManager(ResourceManager const&);
		void operator=(ResourceManager const&);
		Sound sound[MAX_SOUNDS]; //array of sound buffers
		int sound_count; //count numbver of loaded sounds
		Music music[MAX_MUSICS]; //array of music buffers
		int music_count; //count number of loaded musics

	public:
		static ResourceManager& getInstance();

		int startUp();
		void shutDown();

		int loadSound(std::string filename, std::string label);

		int unloadSound(std::string label);

		Sound* getSound(std::string label);

		int loadMusic(std::string filename, std::string label);

		int unloadMusic(std::string label);

		Music* getMusic(std::string label);

	};
}

#endif