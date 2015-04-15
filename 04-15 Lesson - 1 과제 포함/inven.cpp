#include "inven.h"


inven::inven(void)
{
}


inven::~inven(void)
{
}

void inven::showInventory()
{
	for(_viItem = _vItem.begin(); _viItem != _vItem.end(); _viItem++)
	{
		cout << "===============================================" << endl;
		cout << "ÀÌ¸§ : " << _viItem->name << endl;
	}
}

void inven::addItem(tagItemInfo* item)
{
	_vItem.push_back(*item);
}