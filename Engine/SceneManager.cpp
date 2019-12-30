#include "SceneManager.h"

#include <iostream>

namespace Engine
{
	SceneManager::SceneManager()
	{
		mUpdateThread = std::thread { &SceneManager::UpdateLoop, this };
	}
	
	SceneManager::~SceneManager()
	{
		mUpdateThread.join();
	}
	
	void SceneManager::UpdateLoop()
	{
		while(true)
		std::cout << "Updating " << std::endl;
	}
}
