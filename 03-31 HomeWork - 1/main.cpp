//공통된 사항.
//문자열은 전부 입력받는다.
//첫번째 문제 
//문자열을 입력하면 입력받은 문자열이 거꾸로 출력된다.
//두번째 문제
//입력받은 문자열이 짝수번째만 거꾸로 출력된다.
//ex)abcdefg => agcdebf
//세번째 문제
//strtok을 써서 입력받은 문자열이 띄어쓰기를 만나면 잘린다.
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
	
	cout << "1, 2번 문제 입력 > ";
	cin.getline(str, 100);
	cin.clear();
	//cin.ignore();

	cout << "문제 1 - 문자열 거꾸로 출력." << endl;
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		cout << str[i];
	}

	cout << endl << "문제 2 - 문자열 짝수자리만 거꾸로 출력." << endl;
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
	
	cout << endl << "3번 문제입력. 띄어쓰기가 포함된 문장 입력. > ";
	
	cin.getline(str2, 100);

	str3 = strtok(str2, " ");
	cout << str3 << endl;

	while (NULL != (str3 = strtok(NULL, " ")))
	{
		cout << str3 << endl;
	}

	return 0;
}