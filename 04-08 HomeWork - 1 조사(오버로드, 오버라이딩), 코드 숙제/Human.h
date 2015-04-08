#pragma once
#include "Race.h"

class Human : public Race
{
public:
	Human();
	~Human();
	void myInfoIs();
};

class HumanWarrior : public Human
{
public:
	HumanWarrior();
	~HumanWarrior();
	void myInfoIs();
};

class HumanMagician : public Human
{
public:
	HumanMagician();
	~HumanMagician();
};

class HumanRogue : public Human
{
public:
	HumanRogue();
	~HumanRogue();
};

class HumanArcher : public Human
{
public:
	HumanArcher();
	~HumanArcher();
};

class HumanFighter : public Human
{
public:
	HumanFighter();
	~HumanFighter();
};
