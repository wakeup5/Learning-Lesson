#include <iostream>

//�����ι�
#define ENEMY_MAX 200
#define CASH


using namespace std;

void main()
{

	//ifdef ~ else ~ endif ��
#ifdef CASH
	cout << "A" << endl;
#else
	cout << "B" << endl;
#endif

	//static
	//�׻� �޸𸮿� �Ҵ�Ǿ� �������� ������ �����ϴ�.
	static int num = 100;

	//const
	//��� ���� ������ �ʴ� ������ ��
	const int num2 = 100;

}