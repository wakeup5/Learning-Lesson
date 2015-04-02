/* 숙제 1 for문 여러개로 별 찍기.
#include <iostream>

using namespace std;

int main()
{
	int length = 10;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < length; i++)
	{
		for (int j = length - i - 1; j >= 0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}

		for (int k = length - i - 1; k >= 0; k--)
		{
			cout << "*";
		}

		cout << endl;
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = length - 1 - i; j >= 0; j--)
		{
			cout << " ";
		}
		for (int k = 0; k < i + 1; k++)
		{
			cout << "*";
		}
		for (int l = 0; l < i; l++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}
*/

//숙제 2 for문 한개로 별찍기.
/*
#include <iostream>

using namespace std;

int main()
{
	int length = 10;
	for (int i = 0; i < length * length; i++)
	{
		if (i % length < i / length + 1) cout << "*";
		else cout << " ";
		if (i % length == length - 1) cout << endl;
	}
	cout << endl;
	for (int i = 0; i < length * length; i++)
	{
		if (i % length < length - i / length) cout << "*";
		else cout << " ";
		if (i % length == length - 1) cout << endl;
	}
	cout << endl;
	for (int i = 0; i < length * length; i++)
	{
		if (i % length > i / length - 1) cout << "*";
		else cout << " ";
		if (i % length == length - 1) cout << endl;
	}
	cout << endl;
	for (int i = 0; i < length * length * 2; i++)
	{
		if ((i % (length * 2) < (length + 1) + (i / (length * 2))) && (i % (length * 2) > (length - 1) - (i / (length * 2)))) cout << "*";
		else cout << " ";		
		if (i % (length * 2) == length * 2 - 1) cout << endl;
	}
	//숙제 2이상 끝
}
*/


//숙제 3
//빙고게임.
//숫자가 화면에 나옴. 5*5
//숫자가 랜덤. 1~25;
//빙고카운트.
//숫자를 입력하시오.
//숫자를 입력하면 같은 숫자 위치가 #으로 변함.
//한줄 완성되면 빙고카운트 증가.
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int bingoNum[25];
	//int view[5][5];
	int bingo = 0;
	int round = 1;

	int hCheck, vCheck, slashCheck, bslashCheck;

	int input;
	bool isExist = false;

	int dest, sour, temp;

	for (int i = 0; i < 25; i++)
	{
		bingoNum[i] = i + 1;
	}

	for (int i = 0; i < 777; i++)
	{
		dest = rand() % 25;
		sour = rand() % 25;

		temp = bingoNum[dest];
		bingoNum[dest] = bingoNum[sour];
		bingoNum[sour] = temp;
	}

	//게임 시작
	while (true)
	{
		system("cls");

		//판 출력
		cout << "====================" << endl;
		cout << round << " round\t빙고 : " << bingo << endl << endl;
		
		for (int i = 0; i < 25; i++)
		{
			cout << "\t";
			if (bingoNum[i] == -1) cout << "#";
			else cout << bingoNum[i];
			if (i % 5 == 4) cout << endl << endl;
		}

		while (true)
		{
			input = -1;
			isExist = false;

			cout << "번호를 선택하시오." << endl;
			cout << "> ";
			cin >> input;
			cin.clear();

			if (input < 1 || input > 25)
			{
				cout << "다시 입력하시오." << endl;
				continue;
			}
			
			for (int i = 0; i < 25; i++)
			{
				if (bingoNum[i] == input)
				{
					bingoNum[i] = -1;
					isExist = true;
				}
			}

			if (isExist) break;
			else cout << "이미 선택한 번호입니다. 다시 선택하시오." << endl;
		}

		bingo = 0;
		
		//빙고 갯수
		slashCheck = bslashCheck = 0;
		for (int i = 0; i < 5; i++)
		{
			hCheck = vCheck = 0;
			for (int j = 0; j < 5; j++){
				if (bingoNum[i * 5 + j] == -1) hCheck++;//가로줄을 체크함. 1번째 루프면 맨위 한줄 체크
				if (bingoNum[j * 5 + i] == -1) vCheck++;//세로줄을 체크함. 1번째 루프면 맨 왼쪽 한줄 체크
			}

			if (hCheck == 5) bingo++;
			if (vCheck == 5) bingo++;

			if (bingoNum[i * 5 + i] == -1) slashCheck++;
			if (bingoNum[i * (5 - 1)] == -1) bslashCheck++;
		}

		if (slashCheck == 5) bingo++;
		if (bslashCheck == 5) bingo++;

		//승리조건
		if (bingo >= 5)
		{
			cout << "빙고 5개를 달성하였으므로 게임에서 이겼습니다!" << endl;
			break;
		}

		round++;
	}

	return 0;
}