#include "Gamble.h"
#include <iostream>
#include <time.h>
#include <Windows.h>

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

Gamble::Gamble()
{
	srand((unsigned int)time(NULL));
	_fund = 0;
	_minBatting = 1;
	_lineX = 0;
	_lineY = 0;
}


Gamble::~Gamble()
{
}

int Gamble::getFund()
{
	return _fund;
}

void Gamble::setFund(int fund)
{
	_fund = fund;
}


void Gamble::clearDisplayAndCursor()
{
	gotoxy(_lineX, _lineY + 6);
	printf("                                                ");
	gotoxy(_lineX, _lineY + 7);
	printf("                                                ");
	gotoxy(_lineX, _lineY + 6);
}

int Gamble::batting()
{
	int input;
	int fund = getFund();

	while (true)
	{
		clearDisplayAndCursor();

		input = 0;
		printf("베팅 (최소 : %d) > ", _minBatting);
		fflush(stdin);
		scanf_s("%d", &input);

		if (input < _minBatting || input > fund)
		{
			printf("잘못 입력하였습니다.\n");
			continue;
		}

		setFund(fund - input);
		break;
	}

	return input;
}

void Gamble::createCards()
{
}
void Gamble::suffleCards()
{
}
void Gamble::printCard(int card, int x, int y)
{
}
void Gamble::printBackCard(int x, int y)
{
}
void Gamble::printGameInfo()
{
}
void Gamble::startGame()
{
}