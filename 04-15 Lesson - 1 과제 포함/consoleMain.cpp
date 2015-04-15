#include "mainGame.h"

void main()
{
	//클래스는 보통 동적할당을 해준다

	mainGame* mg = new mainGame;

	delete mg;
}