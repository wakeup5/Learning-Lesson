#pragma once
class MainGame
{
private:
	int hp;
	int atk;
public:
	MainGame(int, int);
	MainGame();
	~MainGame();
};

//멤버 이니셜라이저
//객체 생성과 동시에 멤버 초기화
MainGame::MainGame(int hp, int atk)
	:hp(hp), atk(atk)
{

}
