//#include "GameMain.h"
#pragma once

static enum SOUND_PLAY
{
	SOUND_BGM_OPENING1,
	SOUND_BGM_LIFE1,
	SOUND_BGM_LIFE2,
	SOUND_BGM_FUN,
	SOUND_BGM_SAD1,
	SOUND_BGM_SAD2,
	SOUND_BGM_ENEMY,
	SOUND_BGM_DARK,
	SOUND_BGM_QUESTION,
	SOUND_BGM_URSENCY1,
	SOUND_BGM_URSENCY2,
	SOUND_BGM_TENSION,
	SOUND_BGM_SUSPENSE,
	SOUND_BGM_SAD_ENDING
};

class Sound
{
private:
	//GameMain* _game;
public:
	Sound();
	~Sound();

	static void playBGM(int);
	static void stop();
};

