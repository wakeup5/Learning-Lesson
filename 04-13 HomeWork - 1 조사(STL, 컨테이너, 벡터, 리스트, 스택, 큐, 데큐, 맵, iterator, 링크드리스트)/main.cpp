//조사
//STL - 템플릿으로 작성된 제너릭 클래스와 함수를 모아둔 라이브러리.
//컨테이너 - 데이터를 저장하고 검색하는 곳.
//벡터 - 크기가 변하는 배열?
//리스트 - 데이터의 삽입 삭제 혹은 검색을 위함.
//스택 - 나중에 들어간 놈이 먼저 나온다.. 
//큐 - 먼저 들어간 놈이 먼저 나온다..
//데큐 - 리스트의 양쪽에서 들어갔다 나왔다 할 수 있는 스택과 큐를 합쳐놓은 것
//맵 - 키, 값 형태로 저장됨
//이터레이터 - 들어있는 값들을 순서대로 나열 하기 위한 클래스.
//싱글링크드리스트 - 하나의 원소에 다음 원소를 가리키는 주소가 저장된 리스트. 한쪽 방향으로 밖에 탐색이 안된다. 리스트 중간에 데이터 삽입 삭제가 빠르다. 검색이 리스트보다 느리다
//더블링크드리스트 - 싱글링크드리스트를 보완하기 위함. 양쪽 방향으로 탐색이 가능.

//코딩숙제
#pragma once

template <typename T>
class arraySample
{
public:
	T* buffer;//데이터를 담을 변수
	int size;//데이터의 갯수

	//뽀인트1
	void Add(T num)
	{
		if (size != 0)//사이즈가 0이 아닐때
		{
			T* temp;
			temp = new T[size + 1];//현재 갯수보다 1이 큰 템플릿 타입 배열을 만듬
			memcpy(temp, buffer, size * sizeof(T));//버퍼 변수에 있던 내용을 temp변수에 복사. - 메모리 자체를 복사
			delete[] buffer;//기존 퍼버 변수 메모리 해제
			buffer = temp;//
		}
		buffer[size++] = num;//마지막 원소에 매개변수 값 입력
	}

	int GetSize()//현재 갯수를 리턴
	{
		return size;
	}

	//뽀인트2
	T operator[](int index) const//일반 배열[] 처럼 접근 가능하도록
	{
		return buffer[index];
	}


	arraySample(void)
	{
		size = 0;
		buffer = new T[1];

	}
	~arraySample(void)
	{
		delete[] buffer;
	}
};

//#include "arraySample.h"
#include <iostream>

using namespace std;

void main()
{
	arraySample<int> asi;//인트형 리스트 만듬

	asi.Add(57);//값 입력
	asi.Add(100);
	asi.Add(777);
	asi.Add(321039201);

	for (int i = 0; i < asi.GetSize(); i++)//4개가 입력 되어있으므로 4번 돔
	{
		cout << "배열 샘플 정수형 : " << asi[i] << endl;//순서대로 출력
	}

	arraySample<float> asf;

	asf.Add(3.14);
	asf.Add(7.11);

	for (int i = 0; i < asf.GetSize(); i++)
	{
		cout << "배열 샘플 실수형 : " << asf[i] << endl;
	}

	arraySample<char*> ascc;

	ascc.Add("찬서 요즘 포텐 터지는뒈~");
	ascc.Add("현제 안뇽");
	ascc.Add("캡틴 형 날 가져여 엉엉");

	for (int i = 0; i < ascc.GetSize(); i++)
	{
		cout << "배열 샘플 문자열형 : " << ascc[i] << endl;
	}

	arraySample<char> asc;

	asc.Add('A');
	asc.Add('V');
	asc.Add('E');

	for (int i = 0; i < asc.GetSize(); i++)
	{
		cout << "배열 샘플 문자형 : " << asc[i] << endl;
	}


}