#include <iostream>
#include <time.h>

using namespace std;

//����ü : ��������ü
struct Hero
{
	int HP;
	int MP;
	int atk;
	int def;
};

int main()
{
	Hero doraEmong;
	Hero sonOKong;
	Hero mario;
	int select;
	Hero selectHero;

	doraEmong.HP = 50;
	doraEmong.MP = 1000;
	doraEmong.atk = 100;
	doraEmong.def = 200;
	
	sonOKong.HP = 10000;
	sonOKong.MP = 200;
	sonOKong.atk = 1000;
	sonOKong.def = 500;
	
	mario.HP = 1000;
	mario.MP = 0;
	mario.atk = 200;
	mario.def = 100;
	
	cout << "������ �����Ͻÿ�." << endl;
	cin >> select;

	switch (select){
	case 0:
		cout << "���󿡸��� ����." << endl;
		selectHero = doraEmong;
		break;
	case 1:
		cout << "�տ����� ����." << endl;
		selectHero = sonOKong;
		break;
	case 2:
		cout << "�������� ����." << endl;
		selectHero = mario;
		break;
	default:
		cout << "���� ����. ���󿡸��� ���õ˴ϴ�." << endl;
		selectHero = doraEmong;
		break;
	}

	cout << "������ ������ �Ǵ� " << selectHero.HP
		<< ", ��������Ʈ�� " << selectHero.MP
		<< ", ���ݷ��� " << selectHero.atk
		<< ", ������ " << selectHero.def
		<< "�Դϴ�." << endl;

	return 0;
}