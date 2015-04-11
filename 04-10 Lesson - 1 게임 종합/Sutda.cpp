#include "Sutda.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

Sutda::Sutda()
{
	_lineX = 10;
	_lineY = 10;
	_fund = 10000;
	_minBatting = 100;

	_cardPosition = new CardPosition[16];
	_cardPosition[0] = { 0, 2 };
	_cardPosition[1] = { 8, 2 };
	_cardPosition[2] = { 0, 7 };
	_cardPosition[3] = { 8, 7 };
	_cardPosition[4] = { 0, 12 };
	_cardPosition[5] = { 8, 12 };
	_cardPosition[6] = { 0, 17 };
	_cardPosition[7] = { 8, 17 };
	_cardPosition[8] = { 0, 22 };
	_cardPosition[9] = { 8, 22 };
	_cardPosition[10] = { 0, 27 };
	_cardPosition[11] = { 8, 27 };
	_cardPosition[12] = { 0, 32 };
	_cardPosition[13] = { 8, 32 };
	_cardPosition[14] = { 0, 37 };
	_cardPosition[15] = { 8, 37 };

}


Sutda::~Sutda()
{
}

void Sutda::createCards()
{
	for (int i = 0; i < 20; i++)
	{
		_cards[i] = i;
	}
}

void Sutda::suffleCards()
{
	int temp, dest, sour;

	for (int i = 0; i < 500; i++)
	{
		dest = rand() % 20;
		sour = rand() % 20;

		temp = _cards[dest];
		_cards[dest] = _cards[sour];
		_cards[sour] = temp;
	}

}

void Sutda::printCard(int card, int y, int x)
{
	gotoxy(_lineX + x, _lineY + y);
	printf("┌──┐\n");
	gotoxy(_lineX + x, _lineY + y + 1);
	printf("│");
	cardName(card);
	printf("│\n");
	gotoxy(_lineX + x, _lineY + y + 2);
	printf("└──┘\n");
}

void Sutda::printBackCard(int y, int x)
{
	gotoxy(_lineX + x, _lineY + y);
	printf("┌──┐\n");
	gotoxy(_lineX + x, _lineY + y + 1);
	printf("│////│");
	gotoxy(_lineX + x, _lineY + y + 2);
	printf("└──┘\n");
}

void Sutda::clearDisplayAndCursor()
{
	gotoxy(_lineX + 20, _lineY + 1);
	printf("                                                ");
	gotoxy(_lineX + 20, _lineY + 2);
	printf("                                                ");
	gotoxy(_lineX + 20, _lineY + 1);
}

void Sutda::cardName(int card)
{
	printf("%2d%s", (card / 2) + 1, (card % 2 == 0 ? "●" : "○"));
}

void Sutda::inputGamePlayers()
{
	int input;
	char inputStr[20];

	while (true)
	{
		clearDisplayAndCursor();
		printf("시작할 인원 수 입력.(3~8) > ");
		scanf_s("%d", &input);

		if (input < 3 || input > 8)
		{
			printf("\n다시 입력하시오.\n");
			continue;
		}

		_personsNumber = input;
		_players = new tagPlayer[_personsNumber];
		break;
	}
	//입원 이름 입력
	strcpy_s(_players[0].name, "플레이어");
	for (int i = 1; i < _personsNumber; i++)
	{
		clearDisplayAndCursor();
		printf("%d번째 이름을 입력하시오. > ", i + 1);
		scanf_s("%s", &inputStr, 20);
		strcpy_s(_players[i].name, inputStr);
	}
}

void Sutda::giveOutCard()
{
	for (int i = 0; i < _personsNumber; i++)
	{
		_players[i].cards[0] = _cards[_cardTurn++];
		_players[i].cards[1] = _cards[_cardTurn++];

		_players[i].pa = getCardPa(_players[i].cards[0], _players[i].cards[1]);
	}
}

int Sutda::batting()
{
	int input;
	char inputStr[100];
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
			clearDisplayAndCursor();
			printf("잘못 입력하였습니다.\n");
			continue;
		}

		setFund(fund - input);
		break;
	}

	clearDisplayAndCursor();
	printf("담보 입력 > ");

	scanf_s("%s", &inputStr, 100);
	strcpy_s(_players[0].dambo, inputStr);

	return input;
}

void Sutda::printGameInfo()
{
	gotoxy(_lineX, _lineY);
	printf("소지금 : %d           ", getFund());
}

void Sutda::startGame()
{
	printf("섯다 게임 실행 중..");
	inputGamePlayers();
	createCards();
	while (true)
	{
		_cardTurn = 0;
		suffleCards();
		giveOutCard();
		printGameInfo();

		gotoxy(_lineX, _lineY + _cardPosition[0].y - 1);
		printf("%s 의 패", _players[0].name);
		printCard(_players[0].cards[0], _cardPosition[0].y, _cardPosition[0].x);
		printCard(_players[0].cards[1], _cardPosition[1].y, _cardPosition[1].x);
		for (int i = 1; i < _personsNumber; i++)
		{
			gotoxy(_lineX, _lineY + _cardPosition[i * 2].y - 1);
			printf("%s 의 패", _players[i].name);
			printBackCard(_cardPosition[i*2].y, _cardPosition[i*2].x);
			printBackCard(_cardPosition[i * 2 + 1].y, _cardPosition[i * 2 + 1].x);
		}

		batting();
		printGameInfo();

		gotoxy(_lineX, _lineY + _cardPosition[0].y - 1);
		printf("%s 의 패", _players[0].name);
		for (int i = 1; i < _personsNumber; i++)
		{
			gotoxy(_lineX, _lineY + _cardPosition[i * 2].y - 1);
			printf("%s 의 패", _players[i].name);
			printCard(_players[0].cards[i], _cardPosition[i * 2].y, _cardPosition[i * 2].x);
			printCard(_players[0].cards[i], _cardPosition[i * 2 + 1].y, _cardPosition[i * 2 + 1].x);
		}
		_getch();
	}
}

SUTDA_JOKBO Sutda::getCardPa(int card1, int card2)
{
	SUTDA_JOKBO result = GGUT;
	if (card1 == GANG3 && card2 == GANG8 || card1 == GANG8 && card2 == GANG3)
	{
		result = GANGTTANG_38;
	}
	else if ((card1 == GANG1 && card2 == GANG8 || card1 == GANG8 && card2 == GANG1)
		|| (card1 == GANG3 && card2 == GANG8 || card1 == GANG8 && card2 == GANG3))
	{
		result = GANGTTANG_1813;
	}
	else if (card1 == AL10 && card2 == DDI10 || card1 == DDI10 && card2 == AL10)
	{
		result = TTANG_10;
	}
	else if (card1 == AL9 && card2 == DDI9 || card1 == DDI9 && card2 == AL9)
	{
		result = TTANG_9;
	}
	else if (card1 == GANG8 && card2 == DDI8 || card1 == DDI8 && card2 == GANG8)
	{
		result = TTANG_8;
	}
	else if (card1 == AL7 && card2 == DDI7 || card1 == DDI7 && card2 == AL7)
	{
		result = TTANG_7;
	}
	else if (card1 == AL6 && card2 == DDI6 || card1 == DDI6 && card2 == AL6)
	{
		result = TTANG_6;
	}
	else if (card1 == AL5 && card2 == DDI5 || card1 == DDI5 && card2 == AL5)
	{
		result = TTANG_5;
	}
	else if (card1 == AL4 && card2 == DDI4 || card1 == DDI4 && card2 == AL4)
	{
		result = TTANG_4;
	}
	else if (card1 == GANG3 && card2 == DDI3 || card1 == DDI3 && card2 == GANG3)
	{
		result = TTANG_3;
	}
	else if (card1 == AL2 && card2 == DDI2 || card1 == DDI2 && card2 == AL2)
	{
		result = TTANG_2;
	}
	else if (card1 == GANG1 && card2 == DDI1 || card1 == DDI1 && card2 == GANG1)
	{
		result = TTANG_1;
	}
	else if (card1 == GANG1 && card2 == DDI1 || card1 == DDI1 && card2 == GANG1)
	{
		result = TTANG_1;
	}
	else if ((card1 == DDI2 && card2 == DDI1 || card1 == DDI1 && card2 == DDI2) ||
		(card1 == GANG1 && card2 == DDI2 || card1 == DDI2 && card2 == GANG1) ||
		(card1 == DDI1 && card2 == AL2 || card1 == AL2 && card2 == DDI1) ||
		(card1 == GANG1 && card2 == AL2 || card1 == AL2 && card2 == GANG1)
		)
	{
		result = ALI;
	}
	else if ((card1 == DDI4 && card2 == DDI1 || card1 == DDI1 && card2 == DDI4) ||
		(card1 == GANG1 && card2 == DDI4 || card1 == DDI4 && card2 == GANG1) ||
		(card1 == DDI1 && card2 == AL4 || card1 == AL4 && card2 == DDI1) ||
		(card1 == GANG1 && card2 == AL4 || card1 == AL4 && card2 == GANG1)
		)
	{
		result = DOKSA;
	}
	else if ((card1 == DDI9 && card2 == DDI1 || card1 == DDI1 && card2 == DDI9) ||
		(card1 == GANG1 && card2 == DDI9 || card1 == DDI9 && card2 == GANG1) ||
		(card1 == DDI1 && card2 == AL9 || card1 == AL9 && card2 == DDI1) ||
		(card1 == GANG1 && card2 == AL9 || card1 == AL9 && card2 == GANG1)
		)
	{
		result = GUBBING;
	}
	else if ((card1 == DDI10 && card2 == DDI1 || card1 == DDI1 && card2 == DDI10) ||
		(card1 == GANG1 && card2 == DDI10 || card1 == DDI10 && card2 == GANG1) ||
		(card1 == DDI1 && card2 == AL10 || card1 == AL10 && card2 == DDI1) ||
		(card1 == GANG1 && card2 == AL10 || card1 == AL10 && card2 == GANG1)
		)
	{
		result == JANGBBING;
	}
	else if ((card1 == DDI10 && card2 == DDI4 || card1 == DDI4 && card2 == DDI10) ||
		(card1 == AL4 && card2 == DDI10 || card1 == DDI10 && card2 == AL4) ||
		(card1 == DDI4 && card2 == AL10 || card1 == AL10 && card2 == DDI4) ||
		(card1 == AL4 && card2 == AL10 || card1 == AL10 && card2 == AL4)
		)
	{
		result = JANGSA;
	}
	else if ((card1 == DDI6 && card2 == DDI4 || card1 == DDI4 && card2 == DDI6) ||
		(card1 == AL4 && card2 == DDI6 || card1 == DDI6 && card2 == AL4) ||
		(card1 == DDI4 && card2 == AL6 || card1 == AL6 && card2 == DDI4) ||
		(card1 == AL4 && card2 == AL6 || card1 == AL6 && card2 == AL4)
		)
	{
		result = SERUK;
	}
	else if (((card1 / 2) + 1) + (((card2 / 2) + 1) == 9) || ((card1 / 2) + 1) + (((card2 / 2) + 1) == 19))
	{
		result = GAPO;
	}
	else if (((card1 / 2) + 1) + (((card2 / 2) + 1) < 9 && ((card1 / 2) + 1) + (((card2 / 2) + 1) > 0) ||
		((card1 / 2) + 1) + (((card2 / 2) + 1) < 19) && (card1 / 2) + 1) + (((card2 / 2) + 1) > 10))
	{
		result = GGUT;
	}
	else if (((card1 / 2) + 1) + (((card2 / 2) + 1) == 10))
	{
		result = MANGTONG;
	}
	else if ((card1 == GANG3 && card2 == AL7) || (card2 == AL7 && card1 == GANG3))
	{
		result = TTANGJAP;
	}
	else if ((card1 == AL4 && card2 == DDI9) || (card2 == AL4 && card1 == DDI9) ||
		(card1 == DDI4 && card2 == DDI9) || (card2 == DDI4 && card1 == DDI9) ||
		(card1 == DDI4 && card2 == AL9) || (card2 == DDI4 && card1 == AL9))

	{
		result = GUSA;
	}
	else if ((card1 == AL4 && card2 == AL9) || (card2 == AL4 && card1 == AL9))
	{
		result = SAGUPATO;
	}

	return result;
}