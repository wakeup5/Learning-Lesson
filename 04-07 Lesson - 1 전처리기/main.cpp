#include <iostream>

//디파인문
#define ENEMY_MAX 200
#define CASH


using namespace std;

void main()
{

	//ifdef ~ else ~ endif 문
#ifdef CASH
	cout << "A" << endl;
#else
	cout << "B" << endl;
#endif

	//static
	//항상 메모리에 할당되어 전역에서 접근이 가능하다.
	static int num = 100;

	//const
	//상수 값이 변하지 않는 고유의 값
	const int num2 = 100;

}