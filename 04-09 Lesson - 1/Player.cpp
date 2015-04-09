#include "Player.h"

Player::Player()
{
	_hp = 0;
	_mp = 0;
	_str = 0;
	_dex = 0;
	_agi = 0;
	_atk = 0;
	_def = 0;
}

Player::~Player()
{
}

int Player::getHp()
{
	return _hp;
}

void Player::setHp(int hp)
{
	_hp = hp;
}

int Player::getMp()
{
	return _mp;
}

void Player::setMp(int mp)
{
	_mp = mp;
}

int Player::getStr()
{
	return _str;
}

void Player::setStr(int str)
{
	_str = str;
}

int Player::getDex()
{
	return _dex;
}

void Player::setDex(int dex)
{
	_dex = dex;
}

int Player::getAgi()
{
	return _agi;
}

void Player::setAgi(int agi)
{
	_agi = agi;
}

int Player::getAtk()
{
	return _atk;
}

void Player::setAtk(int atk)
{
	_atk = atk;
}

int Player::getDef()
{
	return _def;
}

void Player::setDef(int def)
{
	_def = def;
}