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
	ITEM_SOLDOUT	//�̳ѹ��� ��
};

//item ����ü
struct tagItemInfo
{
	ITEM itemKind;			//������ ����
	string name;			//������ �̸�
	string description;		//������ ����
	int attribute;			//������ �ɷ�ġ
	int price;				//������ ����
};

class shop
{
private:
	vector<tagItemInfo> _vItem;
	vector<tagItemInfo>::iterator _viItem;

public:
	//������ ���� �Լ�
	void itemSetup();
	//������ ����Լ�
	void itemOutput(int num);

	tagItemInfo* getItem(int num);

	shop(void);
	~shop(void);
};

