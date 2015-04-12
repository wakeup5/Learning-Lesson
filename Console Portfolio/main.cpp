#include "GameMain.h"

void main()
{
	GameMain* game = new GameMain();
	game->startGame();

	delete game;
}