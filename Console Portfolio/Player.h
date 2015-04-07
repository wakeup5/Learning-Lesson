#include <list>
#include "Skill.h"

#pragma once
class Player
{
public:
	Player();
	~Player();

	int getLevel();
	int getExp();
	int getCurrentHp();
	int getMaxHp();
	int getCurrentMp();
	int getMaxMp();
	int getStr();
	int getDex();
	float getAgi();
	int getStamina();
	Skill& getSkills();

private:
	int _level;
	int _exp;
	int _currentHp;
	int _maxHp;
	int _currentMp;
	int _maxMp;
	int _str;
	int _dex;
	float _agi;
	int _stamina;
	Skill _skills[];
};

