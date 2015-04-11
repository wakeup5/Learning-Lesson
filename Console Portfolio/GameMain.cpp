#include <iostream>
#include "GameMain.h"

GameMain::GameMain()
	: _story(new Story())
{
	system("mode CON COLS=129 LINES=65");
}


GameMain::~GameMain()
{
	//delete _sound;
	//delete _story;
}

void GameMain::startGame()
{
	//getSound()->playBGM(SOUND_BGM_OPENING1);
	getStory()->opening();

	std::cin.get();
}

/*
Sound* GameMain::getSound()
{
	return _sound;
}
*/

Story* GameMain::getStory()
{
	return _story;
}