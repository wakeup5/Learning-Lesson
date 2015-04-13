#pragma once

template<typename T>
class Array
{
public:
	T* buffer;
	int size;

	Array()
	{
		size = 0;
		buffer = new T[1];
	}

	~Array()
	{
		delete[] buffer;
	}

	void add(T t)
	{
		if (size != 0)
		{

		}
	}
};

