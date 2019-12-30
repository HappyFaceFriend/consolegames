#pragma once

#include "GameSettings.h"
#include "SceneManager.h"
#include "Renderer.h"
namespace Engine
{
	class Game
	{
	public:
		Game(GameSettings setting);
		~Game();
		
		void GameLoop();
		void IsOver();
	
	private:
		SceneManager mSceneMgr;
		Renderer mRenderer;
	};
}
