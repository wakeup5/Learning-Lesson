#include "GameMain.h"
#include <iostream>

GameMain::GameMain()
{
}


GameMain::~GameMain()
{
}


template<typename T>
void GameMain::output(T a)
{
	std::cout << a << std::endl;
}
