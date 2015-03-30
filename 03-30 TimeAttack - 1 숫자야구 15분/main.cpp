//���۽ð� 9:41
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

	//�� ��ȣ �Է�.
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
		//�÷��̾� �Է�
		cout << ">";
		cin >> input;

		if (input < 102 || input > 999)
		{
			cout << "�߸� �Է�." << endl;
			continue;
		}

		playerNum[0] = input / 100;
		playerNum[1] = (input % 100) / 10;
		playerNum[2] = input % 10;

		//��
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

		//���
		cout << strike << "strike, " << ball << "ball." << endl;

		//�¸�����
		if (strike >= 3)
		{
			cout << "you win!" << endl;
			break;
		}

		//���� ����
		round--;
		if (round <= 0)
		{
			cout << "you lose. number is " << comNum[0] << comNum[1] << comNum[2] << endl;
			break;
		}
	}

	return 0;
}

//�����ð� 9:54