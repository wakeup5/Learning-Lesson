#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "shop.h"

using namespace std;

class inven
{
private:
	vector<tagItemInfo> _vItem;
	vector<tagItemInfo>::iterator _viItem;

public:
	void showInventory();
	void addItem(tagItemInfo*);

	inven(void);
	~inven(void);
};

