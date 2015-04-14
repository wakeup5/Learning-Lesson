#pragma once
#include <iostream>
#include <list>

using namespace std;

class ListTest
{
public:
	list<int> _list;
	list<int>::iterator _lIterator;

	ListTest();
	~ListTest();
};

