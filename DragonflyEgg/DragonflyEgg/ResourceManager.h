#ifndef __RESOURCE_MANAGER_H__
#define __RESOURCE_MANAGER_H__

#include "Manager.h"
#include "Sprite.h"
#include <vector>
#include "SpriteResourceManager.h"

#define RM df::ResourceManager::getInstance()

namespace df {


	class ResourceManager : public SpriteResourceManager {
	private:
		ResourceManager(); //singleton
		ResourceManager(ResourceManager const&);
		void operator=(ResourceManager const&);

	public:
		static ResourceManager& getInstance();

		int startUp();
		void shutDown();

	};
}

#endif