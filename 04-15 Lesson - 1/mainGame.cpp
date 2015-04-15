#include "mainGame.h"


mainGame::mainGame(void)
{
	//�ʱ�ȭ
	_shop = new shop;
	_shop->itemSetup();	//���� Ŭ������ �����ۼ¾� �Լ��� ���� ���� ���ش�

	_inven = new inven;

	//������ �� ���������� ������� �Լ�
	setMainPage();

	_money = 3000000;
	_selectNum = 0;

}


mainGame::~mainGame(void)
{
	delete _shop;
	delete _inven;
}

void mainGame::setLocation(int number)
{
	switch(number)
	{
		case LOCATION_SHOP:
			setShopPage();
		break;
		case LOCATION_INVEN:
			setInventoryPage();
		break;
		default:
			setMainPage();
		break;
	}
}

void mainGame::setMainPage()
{
	cout << "====== �� �� Ÿ �� ======" << endl;
	cout << "1. ����   2. �κ��丮" << endl;
	cout << "========================" << endl;

	cin >> _selectNum;
	system("cls");

	//������ ������ �̵� ��������
	setLocation(_selectNum);

}

void mainGame::setShopPage()
{
	while(true)
	{
		cout << "============== S H O P ==============" << endl;
		cout << "1. ��  2. ���ⱸ  3. �Ǽ����� 4. ����" << endl;
		cout << "=====================================" << endl;
		cout << "����ȭ������ ���ư��÷��� 0���� ��������" << endl;

		cin >> _selectNum;
		system("cls");

		//0���� ������ ����ȭ������ ��������
		if(_selectNum == 0)
		{
			setMainPage();
			break;
		}

		//������ �������� ����غ���
		_shop->itemOutput(_selectNum);

		cout << "������ �������� �ƹ�Ű�� ��������" << endl;
		cin >> _selectNum;
		system("cls");
	}

}

void mainGame::setInventoryPage()
{
	cout << "==================== I N V E N=========================" << endl;
	_inven->showInventory();
}