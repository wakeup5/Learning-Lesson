#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	int length = 0;

	//for문 공식
	/*
	for (int i = 0; i < 10; i++){
		num += i;
		cout << num << endl;
	}
	*/

	/*
	cout << "원하는 구구단의 단 숫자를 입력하시오." << endl;
	cout << "입력 : ";
	cin >> num;

	cout << "원하는 범위를 입력하시오." << endl;
	cout << "입력 : ";
	cin >> length;

	for (int i = 1; i < length + 1; i++)
	{
		cout << num << " * " << i << " = " << num * i << endl;
	}
	*/

	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}
	
	return 0;
}