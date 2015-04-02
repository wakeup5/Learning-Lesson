/* ���� 1 for�� �������� �� ���.
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

//���� 2 for�� �Ѱ��� �����.
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
	//���� 2�̻� ��
}
*/


//���� 3
//�������.
//���ڰ� ȭ�鿡 ����. 5*5
//���ڰ� ����. 1~25;
//����ī��Ʈ.
//���ڸ� �Է��Ͻÿ�.
//���ڸ� �Է��ϸ� ���� ���� ��ġ�� #���� ����.
//���� �ϼ��Ǹ� ����ī��Ʈ ����.
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

	//���� ����
	while (true)
	{
		system("cls");

		//�� ���
		cout << "====================" << endl;
		cout << round << " round\t���� : " << bingo << endl << endl;
		
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

			cout << "��ȣ�� �����Ͻÿ�." << endl;
			cout << "> ";
			cin >> input;
			cin.clear();

			if (input < 1 || input > 25)
			{
				cout << "�ٽ� �Է��Ͻÿ�." << endl;
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
			else cout << "�̹� ������ ��ȣ�Դϴ�. �ٽ� �����Ͻÿ�." << endl;
		}

		bingo = 0;
		
		//���� ����
		slashCheck = bslashCheck = 0;
		for (int i = 0; i < 5; i++)
		{
			hCheck = vCheck = 0;
			for (int j = 0; j < 5; j++){
				if (bingoNum[i * 5 + j] == -1) hCheck++;//�������� üũ��. 1��° ������ ���� ���� üũ
				if (bingoNum[j * 5 + i] == -1) vCheck++;//�������� üũ��. 1��° ������ �� ���� ���� üũ
			}

			if (hCheck == 5) bingo++;
			if (vCheck == 5) bingo++;

			if (bingoNum[i * 5 + i] == -1) slashCheck++;
			if (bingoNum[i * (5 - 1)] == -1) bslashCheck++;
		}

		if (slashCheck == 5) bingo++;
		if (bslashCheck == 5) bingo++;

		//�¸�����
		if (bingo >= 5)
		{
			cout << "���� 5���� �޼��Ͽ����Ƿ� ���ӿ��� �̰���ϴ�!" << endl;
			break;
		}

		round++;
	}

	return 0;
}