#include <iostream>

using namespace std;

int main()
{
	/*
	//배열 초기화. 
	int num[5] = {1, 2, 3, 4, 5};

	int num2[3];
	num2[0] = 1;
	num2[1] = 2;
	num2[2] = 3;

	int num3[10];
	for (int i = 0; i < 10; i++)
	{
		num3[i] = i + 1;
	}
	*/

	int num = 5;
	
	printf("다음 숫자는 : %d\n", num);

	int number;

	scanf_s("%d", &number);
	printf("입력한 값은 %d", number);

	return 0;
}