#include <iostream>

using namespace std;

int main()
{
	//포인터 
	/*
	int a = 10;
	int* b;

	cout << &a;
	*/

	//*는 가리키는것. &는 값을 가리키는 주소값.

	//*b = a;

	//cout << b;

	char* aa = "abcde";
	char* bb = ("adcbe");

	//cout << strcmp(aa, bb);

	//cout << &"abcde";

	const char *a = "야호";
	int num = strlen(a);

	cout << &"11" << ", " << &"11";

	return 0;
}