#pragma once
#include "inven.h"
class player
{
private:
	int _fund;
	inven* _inven;

public:
	player(void);
	~player(void);

	inven* getInven();
	int getFund();
	void setFund(int);
};

