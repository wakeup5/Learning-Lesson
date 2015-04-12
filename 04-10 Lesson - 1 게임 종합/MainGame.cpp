#include "MainGame.h"
#include <iostream>

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	delete _playingGame;
}

void MainGame::selectAndStartGame()
{
	int input;

	while (true)
	{
		printf("게임 선택\n");
		printf("1. 하이로우세븐\n");
		printf("2. 월남뽕\n");
		printf("3. 숫자야구\n");
		printf("4. 빙고\n");
		printf("5. 숫자퍼즐\n");
		printf("6. 섯다\n");
		
		printf(" > ");
		scanf_s("%d", &input, 10);

		switch (input)
		{
		case 1:
			_playingGame = new HighLowSeven();
			break;
		case 2:
			_playingGame = new Wolnamppong();
			break;
		case 3:
			_playingGame = new NumberBaseball();
			break;
		case 4:
			_playingGame = new Bingo();
			break;
		case 5:
			_playingGame = new NumberPuzzle();
			break;
		case 6:
			_playingGame = new Sutda();
			break;
		default:
			printf("잘못 입력하였습니다.\n");
			continue;
		}

		break;
	}
	_playingGame->startGame();
}