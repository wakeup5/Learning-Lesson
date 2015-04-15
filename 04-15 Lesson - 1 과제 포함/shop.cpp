#include "shop.h"


shop::shop(void)
{
}


shop::~shop(void)
{
}

//������ ���� �Լ�
void shop::itemSetup()
{
	tagItemInfo armor1;
	armor1.itemKind = ITEM_ARMOR;
	armor1.name = "�������� ��������";
	armor1.description = "������ �� ������ �ƴ����� �ϵ� ���� �Ծ ������ �Ǿ��ٰ� (ī����)";
	armor1.attribute = 3;
	armor1.price = 10000;
	_vItem.push_back(armor1);

	tagItemInfo armor2;
	armor2.itemKind = ITEM_ARMOR;
	armor2.name = "������ ������ ���ױ�";
	armor2.description = "��Ż��ŭ�̳� �ʴ��ʴ��ϴ�";
	armor2.attribute = 10;
	armor2.price = 5000;
	_vItem.push_back(armor2);

	tagItemInfo armor3;
	armor3.itemKind = ITEM_ARMOR;
	armor3.name = "�������� ����";
	armor3.description = "���־� ���̴� ���� ���� ������ ����̴�";
	armor3.attribute = 8;
	armor3.price = 30000;
	_vItem.push_back(armor3);

	tagItemInfo weapon1;
	weapon1.itemKind = ITEM_WEAPON;
	weapon1.name = "������ �и�ġ";
	weapon1.description = "���� �̹�¯�� �׷��� �ʴٴ�!";
	weapon1.attribute = 20;
	weapon1.price = 13000;
	_vItem.push_back(weapon1);

	tagItemInfo weapon2;
	weapon2.itemKind = ITEM_WEAPON;
	weapon2.name = "�ѿ����� �����꽺 ĵ";
	weapon2.description = "��溸�� ��ô���� ������ ��� ������....";
	weapon2.attribute = 30;
	weapon2.price = 500;
	_vItem.push_back(weapon2);

	tagItemInfo weapon3;
	weapon3.itemKind = ITEM_WEAPON;
	weapon3.name = "�������� �ּҽ�";
	weapon3.description = "�˰��� ĸ���̽�";
	weapon3.attribute = 10;
	weapon3.price = 8000;
	_vItem.push_back(weapon3);

	tagItemInfo acc1;
	acc1.itemKind = ITEM_ACCESORY;
	acc1.name = "�������� ���׾Ȱ�";
	acc1.description = "30�⵿�� �����̸� ��...������";
	acc1.attribute = 15;
	acc1.price = 50000;
	_vItem.push_back(acc1);

	tagItemInfo acc2;
	acc2.itemKind = ITEM_ACCESORY;
	acc2.name = "�ѱ����� ����";
	acc2.description = "���ڵ����� �ܷõ� ����, �״�� �ڵ�� �ű�� ���� ����";
	acc2.attribute = 10;
	acc2.price = 1000;
	_vItem.push_back(acc2);

	tagItemInfo acc3;
	acc3.itemKind = ITEM_ACCESORY;
	acc3.name = "�������� ����";
	acc3.description = "����(a.k.a �󸮾����)�� �İ���";
	acc3.attribute = 30;
	acc3.price = 15000;
	_vItem.push_back(acc3);

	tagItemInfo potion1;
	potion1.itemKind = ITEM_POTION;
	potion1.name = "��ȫ���� �ֽĽ�";
	potion1.description = "HP ȸ���� �ɱ��̳� ���׹̳ʰ� �������� �ʴ´�.. ���ۿ��� ����";
	potion1.attribute = 100;
	potion1.price = 1000;
	_vItem.push_back(potion1);

	tagItemInfo potion2;
	potion2.itemKind = ITEM_POTION;
	potion2.name = "�������� Ư������";
	potion2.description = "HP ȸ�� �߰�, ���ðԵǸ� ���� ���ԵǴ� ������ �Ͼ��";
	potion2.attribute = 300;
	potion2.price = 2500;
	_vItem.push_back(potion2);

}
//������ ����Լ�
void shop::itemOutput(int num)
{
	int i = 0;
	for(i = 0, _viItem = _vItem.begin(); _viItem != _vItem.end(); ++_viItem, i++)
	{
		
		//�׷��� ������ �ɾ��ָ� ���� ����;��ϴ� ������ ����� �ƴϸ� 
		//��Ƽ���� �پ�Ѿ���� ����;��ϴ� ������ ī�װ��� �����ش�
		if(_viItem->itemKind != num) continue;

		//�̷��Ը� �صθ� ���� ��ü ����� ��µȴ�.
		cout << "==================== S H O P =====================" << endl;
		cout << "���� ��ȣ : " << i << endl;
		cout << "�̸� : " << _viItem->name << endl;
		cout << "���� : " << _viItem->price << endl;
		cout << "���� : " << _viItem->attribute << endl;
		cout << "���� : " << _viItem->description << endl;
		cout << "==================================================" << endl;
	}


}

tagItemInfo* shop::getItem(int num)
{
	if(num < 0 || num > _vItem.size())
		return NULL;
	return &_vItem[num];
}