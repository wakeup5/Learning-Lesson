#include "Aaa.h"
#include <iostream>

using namespace std;

Aaa::Aaa()
{
	printf("Aaa 클래스 생성자\n");
	cout << "a" << endl;
}

Aaa::~Aaa()
{
	printf("Aaa 클래스 소멸자 %d\n", this->b);
}

Bbb::Bbb()
{
	printf("Bbb %d", this->b);
}

Bbb::a()
{
	printf("%dsssssss", this->b);
}