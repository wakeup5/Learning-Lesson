#include "mainGame.h"


mainGame::mainGame(void)
{
	//�ʱ�ȭ
	_shop = new shop;
	_shop->itemSetup();	//���� Ŭ������ �����ۼ¾� �Լ��� ���� ���� ���ش�

	//_inven = new inven;
	_player = new player;

	//������ �� ���������� ������� �Լ�
	setMainPage();

	_money = 3000000;
	_selectNum = 0;

}


mainGame::~mainGame(void)
{
	delete _shop;
	delete _player;
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
		system("cls");
		cout << "������ : "<< _player->getFund() << endl; 
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

		int input;
		while(true)
		{
			input = 0;
			cout << "������ : "<< _player->getFund() << endl; 
			//������ �������� ����غ���
			_shop->itemOutput(_selectNum);

			cout << "���� �Ͻ÷��� ��ǰ ��ȣ�� �Է�.(-1 : �ڷ�)" << endl;
			cin >> input;

			if(input == -1)
			{
				break;
			}

			tagItemInfo* item = _shop->getItem(input);
			if(item == NULL)
			{
				cout << "�������� ����." << endl;
				continue;
			}

			if(_player->getFund() < item->price)
			{
				cout << "�� ����" << endl;
				continue;
			}

			_player->setFund(_player->getFund() - item->price);
		
			cout << "�������� ���� �Ͽ����ϴ�." << endl;
			_player->getInven()->addItem(item);

			system("cls");

			
		}
	}

}

void mainGame::setInventoryPage()
{
	int input;
	cout << "==================== I N V E N=========================" << endl;
	_player->getInven()->showInventory();

	cin.ignore();
	cin.clear();
	cin >> input;

	system("cls");
	setMainPage();
}