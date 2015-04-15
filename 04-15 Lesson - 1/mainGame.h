#pragma once
#include "shop.h"
#include "inven.h"

using namespace std;

enum LOCATION
{
	LOCATION_SHOP = 1,	//1�� ������ ���� 
	LOCATION_INVEN		//2�� ������ �κ�
};


class mainGame
{
private:
	shop* _shop;		//���� Ŭ����
	inven* _inven;		//�κ� Ŭ����
	LOCATION _location;	//�����̼� �̳ѹ�
	int _money;			//������
	int _selectNum;		//���ù�ȣ

public:
	void setLocation(int number);	//��ġ�� �̵��� �Լ�
	void setMainPage();				//����Ŭ�󽺷� ���ƿ� �Լ�
	void setShopPage();				//����
	void setInventoryPage();		//�κ�


	mainGame(void);
	~mainGame(void);
};

