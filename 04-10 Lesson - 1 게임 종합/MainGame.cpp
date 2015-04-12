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
		printf("���� ����\n");
		printf("1. ���̷ο켼��\n");
		printf("2. ������\n");
		printf("3. ���ھ߱�\n");
		printf("4. ����\n");
		printf("5. ��������\n");
		printf("6. ����\n");
		
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
			printf("�߸� �Է��Ͽ����ϴ�.\n");
			continue;
		}

		break;
	}
	_playingGame->startGame();
}