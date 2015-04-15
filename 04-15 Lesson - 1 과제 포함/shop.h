#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum ITEM
{
	ITEM_ARMOR = 1,
	ITEM_WEAPON,
	ITEM_ACCESORY,
	ITEM_POTION,
	ITEM_SOLDOUT	//이넘문의 끝
};

//item 구조체
struct tagItemInfo
{
	ITEM itemKind;			//아이템 종류
	string name;			//아이템 이름
	string description;		//아이템 설명
	int attribute;			//아이템 능력치
	int price;				//아이템 가격
};

class shop
{
private:
	vector<tagItemInfo> _vItem;
	vector<tagItemInfo>::iterator _viItem;

public:
	//아이템 셋팅 함수
	void itemSetup();
	//아이템 출력함수
	void itemOutput(int num);

	tagItemInfo* getItem(int num);

	shop(void);
	~shop(void);
};

