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

	/*
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}
	*/

	//while문
	/*
	while (true)
	{
		break;
		continue;
	}
	*/

	//조건문
	//if문

	/*
	int playerHP = 500;
	int enemyAtk = 99;

	while (true)
	{
		playerHP -= enemyAtk;

		cout << "플레이어의 피 : " << playerHP << endl;

		if (playerHP < 0)
		{
			cout << "으앙 쥬금" << endl;
			break;
		}
	}
	*/
	

	/*
	int age;
	int height;

	cout << "나이 : ";
	cin >> age;

	cout << "키 : ";
	cin >> height;

	if (age < 20 && height < 150)
	{
		cout << "잡혀간다" << endl;
	} 
	else if (age >= 20 && age > 20 && height >= 150 && height < 170)
	{
		cout << "적당?" << endl;
	}
	else
	{
		cout << "음.. 모르겟다" << endl;
	}
	*/

	return 0;
}