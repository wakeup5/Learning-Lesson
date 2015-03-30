//시작시간 9:41
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	int comNum[3];
	int playerNum[3];
	int input;
	int strike, ball;
	int round = 10;

	//컴 번호 입력.
	while (true)
	{
		comNum[0] = (rand() % 9) + 1;
		comNum[1] = rand() % 10;
		comNum[2] = rand() % 10;

		if (comNum[0] != comNum[1] && comNum[1] != comNum[2] && comNum[0] != comNum[2])
		{
			break;
		}
	}

	while (true)
	{
		strike = 0;
		ball = 0;

		cout << "round " << round << endl;
		//플레이어 입력
		cout << ">";
		cin >> input;

		if (input < 102 || input > 999)
		{
			cout << "잘못 입력." << endl;
			continue;
		}

		playerNum[0] = input / 100;
		playerNum[1] = (input % 100) / 10;
		playerNum[2] = input % 10;

		//비교
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (comNum[i] == playerNum[j])
				{
					if (i == j)
					{
						strike++;
					}
					else
					{
						ball++;
					}
				}	
			}
		}

		//출력
		cout << strike << "strike, " << ball << "ball." << endl;

		//승리조건
		if (strike >= 3)
		{
			cout << "you win!" << endl;
			break;
		}

		//라운드 감소
		round--;
		if (round <= 0)
		{
			cout << "you lose. number is " << comNum[0] << comNum[1] << comNum[2] << endl;
			break;
		}
	}

	return 0;
}

//끝난시간 9:54