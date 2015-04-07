//��������
//��ü����
//Ŭ����
//���
//ĸ��ȭ


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

using namespace std;

enum INPUT_ARROW
{
	INPUT_ARROW_UP, INPUT_ARROW_DOWN, INPUT_ARROW_LEFT, INPUT_ARROW_RIGHT
};

INPUT_ARROW getArrow();
void createBoardAndSuffle();
void print();

int board[5][5];

void main()
{
	srand((unsigned int)time(NULL));
	createBoardAndSuffle();
	while (true)
	{
		switch (getArrow())
		{
		case INPUT_ARROW_UP:
			
			break;
		case INPUT_ARROW_DOWN:

			break;
		case INPUT_ARROW_LEFT:

			break;
		case INPUT_ARROW_RIGHT:

			break;
		}
		print();
	}
}

INPUT_ARROW getArrow()
{
	int input;
	INPUT_ARROW result = INPUT_ARROW_UP;
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
	}

	return result;
}

void createBoardAndSuffle()
{
	int dest, sour, temp;

	for (int i = 0; i < 25; i++)
	{
		board[i / 5][i % 5] = 24 - i;
	}
		
	for (int i = 0; i < 1000; i++)
	{
		dest = (rand() % 24);
		sour = (rand() % 24);

		temp = board[dest / 5][dest % 5];
		board[dest / 5][dest % 5] = board[sour / 5][sour % 5];
		board[sour / 5][sour % 5] = temp;
	}	
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
}

//������� : �Ӹ���� �����ϸ� �ȴ�. Ŭ���� Ȥ�� �Լ����� �� �� �ֵ��� ������ �ۼ��Ѵ�.
//cpp(�ҽ�)���� : 