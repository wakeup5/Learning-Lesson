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
//���� 2�̻� ��

//���� 3
//�������.
//���ڰ� ȭ�鿡 ����. 5*5
//���ڰ� ����. 1~25;
//����ī��Ʈ.
//���ڸ� �Է��Ͻÿ�.
//���ڸ� �Է��ϸ� ���� ���� ��ġ�� #���� ����.
//���� �ϼ��Ǹ� ����ī��Ʈ ����.