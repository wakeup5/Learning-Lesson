//절차지향
//객체지향
//클래스
//상속
//캡슐화


//코딩 숙제
//숫자퍼즐
//5*5
//0은 하단 오른쪽. 즉 맨 마지막
//넘버패드 2468 상하좌우 키만 누르면 바로 움직임.
//숫자는 1~24로 채워짐.
//상하좌우를 누르면 0과 해당하는 숫자 위치가 바뀜. 벽일 경우 안움직임.
//그 안에서는 자유롭게 움직임.
#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h>

using namespace std;

enum INPUT_ARROW
{
	INPUT_ARROW_NONE, INPUT_ARROW_UP, INPUT_ARROW_DOWN, INPUT_ARROW_LEFT, INPUT_ARROW_RIGHT
};

INPUT_ARROW getArrow();
void createBoardAndSuffle();
void print();
void findZero();
void positionChange(int, int, int, int);
void moveUp();
void moveDown();
void moveLeft();
void moveRight();

int board[5][5];
int x = 0, y = 0;

void main()
{
	srand((unsigned int)time(NULL));
	createBoardAndSuffle();
	while (true)
	{
		findZero();
		print();
		switch (getArrow())
		{
		case INPUT_ARROW_UP:
			moveUp();
			break;
		case INPUT_ARROW_DOWN:
			moveDown();
			break;
		case INPUT_ARROW_LEFT:
			moveLeft();
			break;
		case INPUT_ARROW_RIGHT:
			moveRight();
			break;
		default:
			continue;
		}
	}
}

INPUT_ARROW getArrow()
{
	int input;
	INPUT_ARROW result = INPUT_ARROW_NONE;
	input = _getch();

	switch (input)
	{
	case 72:
		result = INPUT_ARROW_UP;
		break;
	case 75:
		result = INPUT_ARROW_LEFT;
		break;
	case 77:
		result = INPUT_ARROW_RIGHT;
		break;
	case 80:
		result = INPUT_ARROW_DOWN;
		break;
	case 224:
	default :
		result = INPUT_ARROW_NONE;
	}
	printf("input : %d\n", input);

	return result;
}

void createBoardAndSuffle()
{
	int dest, sour, temp;

	for (int i = 0; i < 25; i++)
	{
		board[i / 5][i % 5] = 24 - i;
	}
	/*
	for (int i = 0; i < 1000; i++)
	{
		dest = (rand() % 24);
		sour = (rand() % 24);

		temp = board[dest / 5][dest % 5];
		board[dest / 5][dest % 5] = board[sour / 5][sour % 5];
		board[sour / 5][sour % 5] = temp;
	}	
	*/
}

void print()
{
	system("cls");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d\t", board[i][j]);
		}
		printf("\n");
	}
	printf("\n\ny : %d, x : %d\n", y, x);
}

void findZero(void)
{
	for (int i = 0; i < 25; i++)
	{
		if (board[i / 5][i % 5] == 0)
		{
			x = i % 5;
			y = i / 5;
			return;
		}
	}
}

void positionChange(int n3, int n4)
{
	int temp;

	temp = board[y][x];
	board[y][x] = board[n3][n4];
	board[n3][n4] = temp;

	x = n4;
	y = n3;
}

void moveUp()
{
	if (y <= 0) return;

	findZero();
	positionChange(y--, x);
}

void moveDown()
{
	if (y >= 4) return;

	findZero();
	positionChange(y++, x);
}

void moveLeft()
{
	if (x <= 0) return;

	findZero();
	positionChange(y, x--);
}

void moveRight()
{
	if (x >= 4) return;

	findZero();
	positionChange(y, x++);
}



//헤더파일 : 머리라고 생각하면 된다. 클래스 혹은 함수등을 알 수 있도록 원형을 작성한다.
//cpp(소스)파일 : 