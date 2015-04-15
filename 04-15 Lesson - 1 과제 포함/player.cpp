#include "player.h"


player::player(void)
{
	_inven = new inven;
	_fund = 100000;
}


player::~player(void)
{
}
inven* player::getInven()
{
	return _inven;
}

int player::getFund()
{
	return _fund;
}

void player::setFund(int fund)
{
	_fund = fund;
}