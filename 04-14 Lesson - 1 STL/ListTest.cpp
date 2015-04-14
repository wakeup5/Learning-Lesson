#include "ListTest.h"

ListTest::ListTest()
{
	/*
	_list.push_back(10);
	_list.push_front(20);

	for (int i = 0; i < 10; i++)
	{
		_list.push_back(i * 111);
	}
	*/

	for (int i = 0; i < 10; i++)
	{
		_list.insert(_list.begin(), i * 123);
	}

	for (_lIterator = _list.begin(); _lIterator != _list.end(); _lIterator++)
	{
		cout << *_lIterator << endl;
	}


}


ListTest::~ListTest()
{
}
