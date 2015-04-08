//오버로드 : 메소드 명이 같으나 매개변수 갯수나 변수 타입이 다른 경우를 말한다.
//오버라이딩 : 상속 받은 상위 클래스의 메소드를 하위 클래스에서 재 정의 하는 것.

//race클래스 상속을 통해 5개 종족 클래스 만들기.
//각각 종족클래스 상속을 통해 각각의 직업 5개 만들기.
#include "Human.h"

void main()
{

	HumanWarrior warrior;
	HumanMagician magician;
	HumanRogue rogue;
	HumanArcher archer;
	HumanFighter fighter;

	Human* human = &warrior;
	Race* race = &warrior;

	warrior.myInfoIs();
	human->myInfoIs();
	race->myInfoIs();
}