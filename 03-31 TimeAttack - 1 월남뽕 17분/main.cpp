//시작시간 8:42
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int cards[52];
	int sharp[3], num[3];
	int desk, sour, temp;

	int money = 10000;
	int batting;
	int turn = 2;

	//카드 생성
	for (int i = 0; i < 52; i++)
	{
		cards[i] = i;
	}

	//카드 섞기
	for (int i = 0; i < 777; i++)
	{
		desk = rand() % 52;
		sour = rand() % 52;

		temp = cards[desk];
		cards[desk] = cards[sour];
		cards[sour] = temp;
	}

	// 게임 시작
	while (true)
	{

		for (int i = 0; i < 3; i++)
		{
			sharp[i] = cards[i + turn - 2] / 13;
			num[i] = cards[i + turn - 2] % 13;

			if (i >= 2) break;

			switch (sharp[i])
			{
			case 0:
				cout << "♠";
				break;
			case 1:
				cout << "◆";
				break;
			case 2:
				cout << "♥";
				break;
			case 3:
				cout << "♣";
				break;
			}

			switch (num[i])
			{
			case 0:
				cout << "A\t";
				break;
			case 10:
				cout << "J\t";
				break;
			case 11:
				cout << "Q\t";
				break;
			case 12:
				cout << "K\t";
				break;
			default:
				cout << num[i] + 1 << "\t";
				break;
			}
		}

		cout << endl;

		cout << "베팅. 남은 금액 : " << money << endl;
		cout << "> ";
		cin >> batting;

		if (batting < 100 || batting > money)
		{
			cout << "잘못 입력함." << endl;
			continue;
		}

		if (num[2] > num[0] && num[2] < num[1] || num[2] < num[0] && num[2] > num[1])
		{
			money += batting;
			cout << "승리! 돈벌음." << endl;
		}
		else
		{
			money -= batting;
			cout << "패배! 돈 잃음" << endl;
		}

		if (money < 100)
		{
			cout << "남은 돈이 없어 게임에서 짐." << endl;
		}

		turn += 3;
	}

	return 0;
}
//끝난시간 8:56