#include "VectorTest.h"


VectorTest::VectorTest()
{
	_vector.push_back(100);

	for (int i = 0; i < 10; i++)
	{
		_vector.push_back(i);
	}

	_vector.pop_back();
	_vector.insert(_vector.begin() + 5, 100);
	_vector.erase(_vector.begin() + 4);

	_vector.insert(_vector.end() - 2, 111);
	_vector.erase(_vector.end() - 3);

	cout << _vector.at(5);

	for (_vIterator = _vector.begin(); _vIterator != _vector.end(); _vIterator++)
	{
		cout << *_vIterator << endl;
	}
		
}


VectorTest::~VectorTest()
{
}
