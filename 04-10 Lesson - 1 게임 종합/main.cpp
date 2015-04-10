#include "MainGame.h"

void main()
{
	MainGame* game = new MainGame();

	game->selectAndStartGame();

	delete game;
}