#pragma once
#include "shop.h"
#include "inven.h"

using namespace std;

enum LOCATION
{
	LOCATION_SHOP = 1,	//1번 누르면 상점 
	LOCATION_INVEN		//2번 누르면 인벤
};


class mainGame
{
private:
	shop* _shop;		//상점 클래스
	inven* _inven;		//인벤 클래스
	LOCATION _location;	//로케이션 이넘문
	int _money;			//소지금
	int _selectNum;		//선택번호

public:
	void setLocation(int number);	//위치로 이동할 함수
	void setMainPage();				//메인클라스로 돌아올 함수
	void setShopPage();				//상점
	void setInventoryPage();		//인벤


	mainGame(void);
	~mainGame(void);
};

