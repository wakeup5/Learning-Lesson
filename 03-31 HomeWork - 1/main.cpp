//����� ����.
//���ڿ��� ���� �Է¹޴´�.
//ù��° ���� 
//���ڿ��� �Է��ϸ� �Է¹��� ���ڿ��� �Ųٷ� ��µȴ�.
//�ι�° ����
//�Է¹��� ���ڿ��� ¦����°�� �Ųٷ� ��µȴ�.
//ex)abcdefg => agcdebf
//����° ����
//strtok�� �Ἥ �Է¹��� ���ڿ��� ���⸦ ������ �߸���.
//ex) i love you
//i
//love
//you
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	char str[100];
	char str2[100];
	char* str3 = NULL;
	
	cout << "1, 2�� ���� �Է� > ";
	cin.getline(str, 100);
	cin.clear();
	//cin.ignore();

	cout << "���� 1 - ���ڿ� �Ųٷ� ���." << endl;
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		cout << str[i];
	}

	cout << endl << "���� 2 - ���ڿ� ¦���ڸ��� �Ųٷ� ���." << endl;
	for (int i = 0; i < strlen(str); i++)
	{
		if (i % 2 == 0)
		{
			cout << str[i];
		}
		else
		{
			cout << str[strlen(str) - i - (strlen(str) % 2 == 0 ? 0 : 1)];
		}
	}
	
	cout << endl << "3�� �����Է�. ���Ⱑ ���Ե� ���� �Է�. > ";
	
	cin.getline(str2, 100);

	str3 = strtok(str2, " ");
	cout << str3 << endl;

	while (NULL != (str3 = strtok(NULL, " ")))
	{
		cout << str3 << endl;
	}

	return 0;
}