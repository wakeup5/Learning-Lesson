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
	printf("Aaa Ŭ���� �Ҹ��� %d\n", this->a);
}
