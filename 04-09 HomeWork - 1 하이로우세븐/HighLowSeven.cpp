#include "HighLowSeven.h"
#include <time.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>

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

HighLowSeven::HighLowSeven()
{
	srand((unsigned int)time(NULL));
	_cardPosition = new CardPosition[5];
	_cardPosition[0] = { 1, 1 };
	_cardPosition[1] = { 9, 1 };
	_cardPosition[2] = { 17, 1 };
	_cardPosition[3] = { 25, 1 };
	_cardPosition[4] = { 33, 1 };

	_cardTurn = 0;
	_gameTurn = 1;

	_fund = 10000;

	_lineX = 0;
	_lineY = 0;
}


HighLowSeven::~HighLowSeven()
{
	delete _cardPosition;
}

void HighLowSeven::createCards()
{
	for (int i = 0; i < 52; i++)
	{
		_cards[i] = i;
	}
}

void HighLowSeven::suffleCards()
{
	int temp, dest, sour;

	for (int i = 0; i < 500; i++)
	{
		dest = rand() % 52;
		sour = rand() % 52;

		temp = _cards[dest];
		_cards[dest] = _cards[sour];
		_cards[sour] = temp;
	}

	for (int i = 0; i < 52; i++)
	{
	}
}

void HighLowSeven::printCard(int card, int y, int x)
{
	gotoxy(x, _lineY + y);
	printf("┌──┐\n");
	gotoxy(x, _lineY + y + 1);
	printf("│    │\n");
	gotoxy(x, _lineY + y + 2);
	printf("│");
	switch (card / 13)
	{
	case 0:
		printf("♤");
		break;
	case 1:
		printf("◆");
		break;
	case 2:
		printf("♥");
		break;
	case 3:
		printf("♧");
		break;
	}
	switch (card % 13)
	{
	case 0:
		printf("%2c", 'A');
		break;
	case 10:
		printf("%2c", 'J');
		break;
	case 11:
		printf("%2c", 'Q');
		break;
	case 12:
		printf("%2c", 'K');
		break;
	default:
		printf("%2d", card % 13 + 1);
		break;
	}
	printf("│\n");
	gotoxy(x, _lineY + y + 3);
	printf("│    │\n");
	gotoxy(x, _lineY + y + 4);
	printf("└──┘\n");
}

void HighLowSeven::printBackCard(int y, int x)
{
	gotoxy(x, _lineY + y);
	printf("┌──┐\n");
	gotoxy(x, _lineY + y + 1);
	printf("│////│\n");
	gotoxy(x, _lineY + y + 2);
	printf("│////│");
	gotoxy(x, _lineY + y + 3);
	printf("│////│\n");
	gotoxy(x, _lineY + y + 4);
	printf("└──┘\n");
}

int HighLowSeven::batting()
{
	int input;
	int fund = getFund();

	while (true)
	{
		clearDisplayAndCursor();

		input = 0;
		printf("베팅 > ");
		fflush(stdin);
		scanf_s("%d", &input);

		if (input < 0 || input > fund)
		{
			printf("잘못 입력하였습니다.\n");
			continue;
		}

		setFund(fund - input);
		break;
	}

	return input;
}

int HighLowSeven::getFund()
{
	return _fund;
}

void HighLowSeven::setFund(int fund)
{
	_fund = fund;
}

int HighLowSeven::selectHighLowSeven()
{
	int select = 0;
	int input;

	while (true)
	{
		clearDisplayAndCursor();

		input = 0;
		printf("1: 로우, 2: 세븐, 3: 하이\n");
		fflush(stdin);
		scanf_s("%d", &input);

		if (input < 0 || input > 3)
		{
			printf("잘못 입력하였습니다.\n");
			continue;
		}

		select = input;
		break;
	}

	return select;
}

GAME_RESULT HighLowSeven::checkCard(int select, int card)
{
	GAME_RESULT result = GAME_LOSE;
	int cardNum = card % 13 + 1;

	switch (select)
	{
	case 1:
		if (cardNum < 7) result = GAME_LOW_WIN;
		break;
	case 2:
		if (cardNum == 7) result = GAME_SEVEN_WIN;
		break;
	case 3:
		if (cardNum > 7) result = GAME_HIGH_WIN;
		break;
	}

	return result;
}

void HighLowSeven::clearDisplayAndCursor()
{
	gotoxy(_lineX, _lineY + 6);
	printf("                                       \n                                            \n");

	gotoxy(_lineX, _lineY + 6);
}

void HighLowSeven::startGame()
{
	int select;
	int battingFund;
	GAME_RESULT gameResult = GAME_LOSE;

	char* gameEndInput = "n";

	printf("==========하이로우세븐==========\n");
	printf("카드를 생성 중입니다..\n");
	createCards();
	printf("카드생성 완료.\n");

	printf("카드를 섞는 중입니다..\n");
	suffleCards();
	printf("카드 섞기 완료.\n");

	printf("게임을 시작합니다.\n");
	Sleep(1000);
	while (true)
	{
		system("cls");
		gotoxy(_lineX, _lineY);
		printf("                                   \r소지금 : %d, 남은 카드수 : %d", getFund(), 52 - _cardTurn - 5);
		for (int i = 0; i < 4; i++)
		{
			printCard(_cards[_cardTurn + i], _cardPosition[i].y, _cardPosition[i].x);
			//printf("%d\n", _cards[_cardTurn + i]);
		}
		printBackCard(_cardPosition[4].y, _cardPosition[4].x);

		//베팅
		battingFund = batting();

		gotoxy(_lineX, _lineY);
		printf("                                   \r소지금 : %d, 남은 카드수 : %d", getFund(), 52 - _cardTurn - 5);

		//하이, 로우, 세븐 선택
		select = selectHighLowSeven();

		//마지막 패 보여주기
		printCard(_cards[_cardTurn + 4], _cardPosition[4].y, _cardPosition[4].x);

		//카드 비교
		gameResult = checkCard(select, _cards[_cardTurn + 4]);

		clearDisplayAndCursor();
		switch (gameResult)
		{
		case GAME_HIGH_WIN: case GAME_LOW_WIN:
			setFund(getFund() + battingFund * 2);
			printf("이겼습니다!");
			break;
		case GAME_SEVEN_WIN:
			setFund(getFund() + battingFund * 13);
			printf("13배!! 이겼습니다!");
			break;
		case GAME_LOSE:
			printf("졌습니다.");
			break;
		}
		gotoxy(_lineX, _lineY);
		printf("                                   \r소지금 : %d, 남은 카드수 : %d", getFund(), 52 - _cardTurn - 5);

		Sleep(1000);

		_cardTurn++;
		if (_cardTurn + 5 > 52)
		{
			clearDisplayAndCursor();
			printf("카드가 소진되었습니다.\n카드를 다시 섞습니다.\n");
			Sleep(1000);
			suffleCards();
			_cardTurn = 0;
		}

		//패배
		if (getFund() <= 0)
		{
			clearDisplayAndCursor();
			printf("모든 돈을 잃었습니다. 게임을 종료합니다.\n");
			break;
		}

		//게임 유지 여부 - 좀더 보강해서 포트폴리오에 사용
		/*
		gotoxy(_lineX, _lineY + 6);
		printf("\n                                       \n                                            \n");

		gotoxy(_lineX, _lineY + 6);
		printf("게임을 계속하시겟습니까? > ");
		scanf_s("%s", &gameEndInput);

		if (strcmp(gameEndInput, "n") == 0 || strcmp(gameEndInput, "N") == 0)
		{
			gotoxy(_lineX, _lineY + 6);
			printf("\n                                       \n                                            \n");

			gotoxy(_lineX, _lineY + 6);
			printf("게임을 종료합니다.\n");
			break;
		}
		*/

	}
}
