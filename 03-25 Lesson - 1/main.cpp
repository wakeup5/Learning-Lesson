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

	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}
	
	return 0;
}