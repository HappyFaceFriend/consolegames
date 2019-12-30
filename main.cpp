#include <iostream>

#include "Engine/Game.h"

int main()
{
	Engine::GameSettings setting;
	Engine::Game game(setting);
	return 0;
}

/*
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
}*/
