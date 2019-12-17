#pragma once

namespace Engine
{
	class Game
	{
	public:
		Game(GameSettings setting);
		~Game();
		
		void GameLoop();
		void IsOver();
				
	};
}
