#include "Aaa.h"
#include <iostream>

using namespace std;

Aaa::Aaa()
{
	printf("Aaa Ŭ���� ������\n");
	cout << "a" << endl;
}

Aaa::~Aaa()
{
	printf("Aaa Ŭ���� �Ҹ��� %d\n", this->b);
}

Bbb::Bbb()
{
	printf("Bbb %d", this->b);
}

Bbb::a()
{
	printf("%dsssssss", this->b);
}