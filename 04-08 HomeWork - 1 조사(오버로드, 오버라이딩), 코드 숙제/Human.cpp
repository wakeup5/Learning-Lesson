#include "Human.h"
#include <iostream>

Human::Human()
{
	race = "Human";
	printf("%s - ", race);
}

Human::~Human()
{
}

void Human::myInfoIs()
{
	printf("�ΰ� ���� Ŭ����\n");
}

HumanWarrior::HumanWarrior()
{
	job = "Warrior";
	printf("%s\n", job);
}

HumanWarrior::~HumanWarrior()
{
}

void HumanWarrior::myInfoIs()
{
	printf("�ΰ� ������ Ŭ����\n");
}

HumanMagician::HumanMagician()
{
	job = "Magician";
	printf("%s\n", job);
}

HumanMagician::~HumanMagician()
{
}

HumanRogue::HumanRogue()
{
	job = "Rogue";
	printf("%s\n", job);
}

HumanRogue::~HumanRogue()
{
}

HumanArcher::HumanArcher()
{
	job = "Archer";
	printf("%s\n", job);
}

HumanArcher::~HumanArcher()
{
}

HumanFighter::HumanFighter()
{
	job = "Fighter";
	printf("%s\n", job);
}

HumanFighter::~HumanFighter()
{
}
