#include "shop.h"


shop::shop(void)
{
}


shop::~shop(void)
{
}

//아이템 셋팅 함수
void shop::itemSetup()
{
	tagItemInfo armor1;
	armor1.itemKind = ITEM_ARMOR;
	armor1.name = "동진이의 갈색셔츠";
	armor1.description = "원래는 그 색깔이 아니지만 하도 오래 입어서 갈색이 되었다고 (카더라)";
	armor1.attribute = 3;
	armor1.price = 10000;
	_vItem.push_back(armor1);

	tagItemInfo armor2;
	armor2.itemKind = ITEM_ARMOR;
	armor2.name = "반장의 찢어진 난닝구";
	armor2.description = "멘탈만큼이나 너덜너덜하다";
	armor2.attribute = 10;
	armor2.price = 5000;
	_vItem.push_back(armor2);

	tagItemInfo armor3;
	armor3.itemKind = ITEM_ARMOR;
	armor3.name = "선중이의 자켓";
	armor3.description = "멋있어 보이는 자켓 정작 주인은 모쏠이다";
	armor3.attribute = 8;
	armor3.price = 30000;
	_vItem.push_back(armor3);

	tagItemInfo weapon1;
	weapon1.itemKind = ITEM_WEAPON;
	weapon1.name = "찬서의 뿅망치";
	weapon1.description = "나의 미미짱은 그렇지 않다능!";
	weapon1.attribute = 20;
	weapon1.price = 13000;
	_vItem.push_back(weapon1);

	tagItemInfo weapon2;
	weapon2.itemKind = ITEM_WEAPON;
	weapon2.name = "한울이의 석류쥬스 캔";
	weapon2.description = "언뜻보면 투척무기 같지만 사실 찍어내리는....";
	weapon2.attribute = 30;
	weapon2.price = 500;
	_vItem.push_back(weapon2);

	tagItemInfo weapon3;
	weapon3.itemKind = ITEM_WEAPON;
	weapon3.name = "가연이의 핫소스";
	weapon3.description = "알고보니 캡사이신";
	weapon3.attribute = 10;
	weapon3.price = 8000;
	_vItem.push_back(weapon3);

	tagItemInfo acc1;
	acc1.itemKind = ITEM_ACCESORY;
	acc1.name = "선중이의 뿔테안경";
	acc1.description = "30년동안 동정이면 마...마법을";
	acc1.attribute = 15;
	acc1.price = 50000;
	_vItem.push_back(acc1);

	tagItemInfo acc2;
	acc2.itemKind = ITEM_ACCESORY;
	acc2.name = "한길이의 연필";
	acc2.description = "손코딩으로 단련된 연필, 그대로 코드로 옮기면 뻑이 난다";
	acc2.attribute = 10;
	acc2.price = 1000;
	_vItem.push_back(acc2);

	tagItemInfo acc3;
	acc3.itemKind = ITEM_ACCESORY;
	acc3.name = "동성이의 발찌";
	acc3.description = "고영욱(a.k.a 얼리어답터)의 후계자";
	acc3.attribute = 30;
	acc3.price = 15000;
	_vItem.push_back(acc3);

	tagItemInfo potion1;
	potion1.itemKind = ITEM_POTION;
	potion1.name = "수홍이의 핫식스";
	potion1.description = "HP 회복은 쪼금이나 스테미너가 내려가질 않는다.. 부작용이 심함";
	potion1.attribute = 100;
	potion1.price = 1000;
	_vItem.push_back(potion1);

	tagItemInfo potion2;
	potion2.itemKind = ITEM_POTION;
	potion2.name = "진한이의 특제포션";
	potion2.description = "HP 회복 중간, 마시게되면 씨익 웃게되는 현상이 일어난다";
	potion2.attribute = 300;
	potion2.price = 2500;
	_vItem.push_back(potion2);

}
//아이템 출력함수
void shop::itemOutput(int num)
{
	int i = 0;
	for(i = 0, _viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem, i++)
	{
		
		//그래서 조건을 걸어주면 내가 보고싶어하는 숫자의 목록이 아니면 
		//컨티뉴로 뛰어넘어버려 보고싶어하는 아이템 카테고리만 보여준다
		if(_viItem->itemKind != num) continue;

		//이렇게만 해두면 벡터 전체 목록이 출력된다.
		cout << "==================== S H O P =====================" << endl;
		cout << "상점 번호 : " << i << endl;
		cout << "이름 : " << _viItem->name << endl;
		cout << "가격 : " << _viItem->price << endl;
		cout << "성능 : " << _viItem->attribute << endl;
		cout << "설명 : " << _viItem->description << endl;
		cout << "==================================================" << endl;
	}


}

tagItemInfo* shop::getItem(int num)
{
	if(num < 0 || num > _vItem.size())
		return NULL;
	return &_vItem[num];
}