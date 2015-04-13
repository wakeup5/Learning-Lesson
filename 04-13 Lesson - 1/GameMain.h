#include <iostream>
#pragma once
class GameMain
{
public:
	GameMain();
	~GameMain();

	//함수 템플릿
	template<typename T>
	void output(T a);
};

