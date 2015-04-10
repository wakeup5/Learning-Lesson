#include "Gamble.h"
#include "HighLowSeven.h"
#include "Wolnamppong.h"
#include "NumberBaseball.h"
#include "Bingo.h"
#include "NumberPuzzle.h"

#pragma once
class MainGame
{
private:
	//Gamble* highlowseven;
	//Gamble* wolnamppong;
	Gamble* _playingGame;
public:
	MainGame();
	~MainGame();

	void selectAndStartGame();
};

