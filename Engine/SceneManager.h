#pragma once

#include <thread>

namespace Engine
{
	class SceneManager
	{
		public:
			SceneManager();
			~SceneManager();
			void UpdateLoop();		
		private:
			std::thread mUpdateThread;
	};
}

