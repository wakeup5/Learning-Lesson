#include "HighLowSeven.h"
#include "Wolnamppong.h"

void main()
{
	Gamble* wnPpong = new Wolnamppong();
	wnPpong->startGame();
		
	Gamble* hlSeven = new HighLowSeven();
	hlSeven->startGame();

	delete wnPpong;
	delete hlSeven;
}