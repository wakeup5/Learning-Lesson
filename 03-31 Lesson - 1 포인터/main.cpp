#include <iostream>

using namespace std;

int main()
{
	//������ 
	/*
	int a = 10;
	int* b;

	cout << &a;
	*/

	//*�� ����Ű�°�. &�� ���� ����Ű�� �ּҰ�.

	//*b = a;

	//cout << b;

	char* aa = "abcde";
	char* bb = ("adcbe");

	//cout << strcmp(aa, bb);

	//cout << &"abcde";

	const char *a = "��ȣ";
	int num = strlen(a);

	cout << &"11" << ", " << &"11";

	return 0;
}