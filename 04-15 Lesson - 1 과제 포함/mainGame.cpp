#include "mainGame.h"


mainGame::mainGame(void)
{
	//초기화
	_shop = new shop;
	_shop->itemSetup();	//상점 클래스의 아이템셋업 함수로 셋팅 먼저 해준다

	//_inven = new inven;
	_player = new player;

	//컴파일 시 메인페이지 띄워놓을 함수
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
	cout << "====== 골 프 타 운 ======" << endl;
	cout << "1. 상점   2. 인벤토리" << endl;
	cout << "========================" << endl;

	cin >> _selectNum;
	system("cls");

	//선택한 곳으로 이동 시켜주자
	setLocation(_selectNum);

}

void mainGame::setShopPage()
{
	while(true)
	{
		system("cls");
		cout << "소지금 : "<< _player->getFund() << endl; 
		cout << "============== S H O P ==============" << endl;
		cout << "1. 방어구  2. 무기구  3. 악세서리 4. 포션" << endl;
		cout << "=====================================" << endl;
		cout << "메인화면으로 돌아가시려면 0번을 누르세요" << endl;

		cin >> _selectNum;
		system("cls");

		//0번을 누르면 메인화면으로 나가주자
		if(_selectNum == 0)
		{
			setMainPage();
			break;
		}

		int input;
		while(true)
		{
			input = 0;
			cout << "소지금 : "<< _player->getFund() << endl; 
			//선택한 아이템을 출력해보자
			_shop->itemOutput(_selectNum);

			cout << "구매 하시려는 상품 번호를 입력.(-1 : 뒤로)" << endl;
			cin >> input;

			if(input == -1)
			{
				break;
			}

			tagItemInfo* item = _shop->getItem(input);
			if(item == NULL)
			{
				cout << "아이템이 없다." << endl;
				continue;
			}

			if(_player->getFund() < item->price)
			{
				cout << "돈 부족" << endl;
				continue;
			}

			_player->setFund(_player->getFund() - item->price);
		
			cout << "아이템을 구매 하였습니다." << endl;
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