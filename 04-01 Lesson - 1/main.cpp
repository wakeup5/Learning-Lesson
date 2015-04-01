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
//숙제
//코드 라인 수가 40 이하.
//for문은 한번에 한번만.
//위의 결과와 똑같이 만듬.