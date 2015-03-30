#include <iostream>
#include <time.h>

using namespace std;

//구조체 : 변수집합체
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
	
	cout << "영웅을 선택하시오." << endl;
	cin >> select;

	switch (select){
	case 0:
		cout << "도라에몽을 선택." << endl;
		selectHero = doraEmong;
		break;
	case 1:
		cout << "손오공을 선택." << endl;
		selectHero = sonOKong;
		break;
	case 2:
		cout << "마리오를 선택." << endl;
		selectHero = mario;
		break;
	default:
		cout << "랜덤 선택. 도라에몽이 선택됩니다." << endl;
		selectHero = doraEmong;
		break;
	}

	cout << "선택한 영웅의 피는 " << selectHero.HP
		<< ", 마나포인트는 " << selectHero.MP
		<< ", 공격력은 " << selectHero.atk
		<< ", 방어력은 " << selectHero.def
		<< "입니다." << endl;

	return 0;
}