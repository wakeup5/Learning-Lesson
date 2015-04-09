#pragma once
class Player
{
public:
	Player();
	~Player();
private:
	int _hp;
	int _mp;
	int _str;
	int _dex;
	int _agi;
	int _atk;
	int _def;
public:
	int getHp();
	void setHp(int);
	int getMp();
	void setMp(int);
	int getStr();
	void setStr(int);
	int getDex();
	void setDex(int);
	int getAgi();
	void setAgi(int);
	int getAtk();
	void setAtk(int);
	int getDef();
	void setDef(int);	

};
