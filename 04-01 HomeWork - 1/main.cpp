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
#include <iostream>

using namespace std;

int main()
{
	int length = 20;
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
	return 0;
}
//숙제 2이상 끝

//숙제 3
//빙고게임.
//숫자가 화면에 나옴. 5*5
//숫자가 랜덤. 1~25;
//빙고카운트.
//숫자를 입력하시오.
//숫자를 입력하면 같은 숫자 위치가 #으로 변함.
//한줄 완성되면 빙고카운트 증가.