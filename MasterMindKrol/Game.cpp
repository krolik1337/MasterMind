#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::generate()
{
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		generatedCode[i] = rand() % 8 + 1;
	}
}
