#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));

	/*
	int num = rand();
	int num2 = rand();
	int num3 = rand();

	cout << "ù��° ������ " << num << endl;
	cout << "�ι�° ������ " << num2 << endl;
	cout << "����° ������ " << num3 << endl;

	*/

	/*
	int num1 = rand() % 45 + 1;
	int num2 = rand() % 45 + 1;
	int num3 = rand() % 45 + 1;
	int num4 = rand() % 45 + 1;
	int num5 = rand() % 45 + 1;
	int num6 = rand() % 45 + 1;

	cout << num1 << ", " << num2 << ", " << num3 << ", " << num4 << ", " << num5 << ", " << num6 << endl;
	*/

	/*
	int min = 11;
	int max = 21;
	int num = (rand() % (max - min)) + min;

	cout << "11 ~ 21������ ���� : " << num << endl;
	*/

	int min = 0;
	int max = 1000;

	int randNum;
	int inputNum;

	int round = 10;

	cout << "���� ���߱� ����." << endl;

	randNum = (rand() % (max - min + 1)) + min;
	cout << "���ڰ� �����Ǿ����ϴ�." << min << " ~ " << max << endl;

	while (true)
	{
		cout << "���� �Է� : ";
		cin >> inputNum;

		if (inputNum < min && inputNum > max)
		{
			cout << "������ �Ѿ����ϴ�. �ٽ� �Է��Ͻÿ�." << endl;
			continue;
		}

		if (inputNum < randNum)
		{
			cout << "�Է��� ���ں��� Ů�ϴ�." << endl;
		}
		else if (inputNum > randNum)
		{
			cout << "�Է��� ���ں��� �۽��ϴ�." << endl;
		}
		else if (inputNum == randNum)
		{
			cout << "����!" << endl;
			break;
		}

		round--;
		cout << "���� ���� �� : " << round << endl;
		if (round <= 0)
		{
			cout << "����. ���ڴ� " << randNum << " �̾����ϴ�~!" << endl;
			break;
		}
	}

	return 0;
}