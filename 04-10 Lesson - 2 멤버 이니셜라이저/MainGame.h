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

//��� �̴ϼȶ�����
//��ü ������ ���ÿ� ��� �ʱ�ȭ
MainGame::MainGame(int hp, int atk)
	:hp(hp), atk(atk)
{

}
