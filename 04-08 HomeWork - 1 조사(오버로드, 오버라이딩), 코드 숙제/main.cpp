//�����ε� : �޼ҵ� ���� ������ �Ű����� ������ ���� Ÿ���� �ٸ� ��츦 ���Ѵ�.
//�������̵� : ��� ���� ���� Ŭ������ �޼ҵ带 ���� Ŭ�������� �� ���� �ϴ� ��.

//raceŬ���� ����� ���� 5�� ���� Ŭ���� �����.
//���� ����Ŭ���� ����� ���� ������ ���� 5�� �����.
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