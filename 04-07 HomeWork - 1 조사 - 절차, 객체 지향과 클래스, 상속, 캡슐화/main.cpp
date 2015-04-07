//�������� - ������ ������ �Ⱦ� ������ ������� ó���ϴ� ��.
//��ü���� - ��ü�� ���� �Լ��� ȣ���Ͽ� ó���ϴ� ��.
//Ŭ���� - ��ü�� ����� ���� ������ Ʋ.
//��� - ���� Ŭ������ ����� �״�� ����ϱ� ���� ��.
//ĸ��ȭ - �Ϻ� �ڷᰡ �ִ� ��� ������ �޼ҵ带 ���������� ������ �Ұ��� �ϵ��� �ϰ�, �޼ҵ带 �̿��Ͽ� ���������� ��ȸ�� �����ϵ��� �� ��.


//�ڵ� ����
//��������
//5*5
//0�� �ϴ� ������. �� �� ������
//�ѹ��е� 2468 �����¿� Ű�� ������ �ٷ� ������.
//���ڴ� 1~24�� ä����.
//�����¿츦 ������ 0�� �ش��ϴ� ���� ��ġ�� �ٲ�. ���� ��� �ȿ�����.
//�� �ȿ����� �����Ӱ� ������.
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
void positionChange(int, int);
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
	case 72: case 56:
		result = INPUT_ARROW_UP;
		break;
	case 75: case 52:
		result = INPUT_ARROW_LEFT;
		break;
	case 77: case 54:
		result = INPUT_ARROW_RIGHT;
		break;
	case 80: case 50:
		result = INPUT_ARROW_DOWN;
		break;
	case 224: default :
		result = INPUT_ARROW_NONE;
		break;
	}
	printf("input : %d\n", input);

	return result;
}

void createBoardAndSuffle()
{
	//int dest, sour, temp;

	for (int i = 0; i < 25; i++)
	{
		board[i / 5][i % 5] = 24 - i;//���ڰ� �Ųٷ� ������.
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



//������� : �Ӹ���� �����ϸ� �ȴ�. Ŭ���� Ȥ�� �Լ����� �� �� �ֵ��� ������ �ۼ��Ѵ�.
//cpp(�ҽ�)���� : 