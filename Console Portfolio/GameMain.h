#include "Story.h"
#include "Sound.h"

#pragma once
class GameMain
{
private:
	//Sound* _sound;
	Story* _story;

public:
	GameMain();
	~GameMain();
	
	void startGame();

	//Sound* getSound();
	Story* getStory();

};

