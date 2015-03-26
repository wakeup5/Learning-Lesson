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

	cout << "첫번째 난수는 " << num << endl;
	cout << "두번째 난수는 " << num2 << endl;
	cout << "세번째 난수는 " << num3 << endl;

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

	cout << "11 ~ 21까지의 난수 : " << num << endl;
	*/

	int min = 0;
	int max = 1000;

	int randNum;
	int inputNum;

	int round = 10;

	cout << "숫자 맟추기 게임." << endl;

	randNum = (rand() % (max - min + 1)) + min;
	cout << "숫자가 지정되었습니다." << min << " ~ " << max << endl;

	while (true)
	{
		cout << "숫자 입력 : ";
		cin >> inputNum;

		if (inputNum < min && inputNum > max)
		{
			cout << "범위를 넘었습니다. 다시 입력하시오." << endl;
			continue;
		}

		if (inputNum < randNum)
		{
			cout << "입력한 숫자보다 큽니다." << endl;
		}
		else if (inputNum > randNum)
		{
			cout << "입력한 숫자보다 작습니다." << endl;
		}
		else if (inputNum == randNum)
		{
			cout << "정답!" << endl;
			break;
		}

		round--;
		cout << "남은 라운드 수 : " << round << endl;
		if (round <= 0)
		{
			cout << "실패. 숫자는 " << randNum << " 이었습니다~!" << endl;
			break;
		}
	}

	return 0;
}