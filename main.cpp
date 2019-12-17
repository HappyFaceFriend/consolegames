#include <iostream>

void InitializeSettings(GameSettings& settings)
{
	//settings.windowSize(1,1)
}

int main(int argc, char** argv) {
{
	GameSettings setting;
	InitializeSettings(setting);
	Engine::Game game(setting);
	while(game.IsOver())
		game.GameLoop();
	
	return 0;
}
