#include <iostream>

using namespace std;

int main()
{
	int num = 0;
	int length = 0;

	//for�� ����
	/*
	for (int i = 0; i < 10; i++){
		num += i;
		cout << num << endl;
	}
	*/

	/*
	cout << "���ϴ� �������� �� ���ڸ� �Է��Ͻÿ�." << endl;
	cout << "�Է� : ";
	cin >> num;

	cout << "���ϴ� ������ �Է��Ͻÿ�." << endl;
	cout << "�Է� : ";
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

	//while��
	/*
	while (true)
	{
		break;
		continue;
	}
	*/

	//���ǹ�
	//if��

	/*
	int playerHP = 500;
	int enemyAtk = 99;

	while (true)
	{
		playerHP -= enemyAtk;

		cout << "�÷��̾��� �� : " << playerHP << endl;

		if (playerHP < 0)
		{
			cout << "���� ���" << endl;
			break;
		}
	}
	*/
	

	/*
	int age;
	int height;

	cout << "���� : ";
	cin >> age;

	cout << "Ű : ";
	cin >> height;

	if (age < 20 && height < 150)
	{
		cout << "��������" << endl;
	} 
	else if (age >= 20 && age > 20 && height >= 150 && height < 170)
	{
		cout << "����?" << endl;
	}
	else
	{
		cout << "��.. �𸣰ٴ�" << endl;
	}
	*/

	return 0;
}