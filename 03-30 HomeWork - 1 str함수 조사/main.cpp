//str �Լ�
//strlen ���ڿ� ���̸� ����
//strcmp �ΰ��� ���ڿ��� ����
//strcpy ���ڿ��� ������
//strcat ���ڿ��� �̾� ����
//strtok ���ڿ��� Ư�� ���ڸ� �������� ����
//strtol ���ڿ����� ���ڸ� �����ؼ� long�� ���ڷ� ��ȯ

//����ü�� ���� �����.
#include <iostream>

using namespace std;

struct Family
{
	char name[10];
	int age;
	float height;
};

int main()
{
	Family me;
	Family brother;

	strcpy_s(me.name, "������");
	me.age = 25;
	me.height = 183.5;

	strcpy_s(brother.name, "�ھƹ���");
	brother.age = 22;
	brother.height = 175.3;

	cout << "�� �̸��� " << me.name << ", ���̴� " << me.age << ", Ű�� " << me.height << endl;
	cout << "�� ������ �̸��� " << brother.name << ", ���̴� " << brother.age << ", Ű�� " << brother.height << endl;

	return 0;
}