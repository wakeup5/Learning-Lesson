//����
//STL - ���ø����� �ۼ��� ���ʸ� Ŭ������ �Լ��� ��Ƶ� ���̺귯��.
//�����̳� - �����͸� �����ϰ� �˻��ϴ� ��.
//���� - ũ�Ⱑ ���ϴ� �迭?
//����Ʈ - �������� ���� ���� Ȥ�� �˻��� ����.
//���� - ���߿� �� ���� ���� ���´�.. 
//ť - ���� �� ���� ���� ���´�..
//��ť - ����Ʈ�� ���ʿ��� ���� ���Դ� �� �� �ִ� ���ð� ť�� ���ĳ��� ��
//�� - Ű, �� ���·� �����
//���ͷ����� - ����ִ� ������ ������� ���� �ϱ� ���� Ŭ����.
//�̱۸�ũ�帮��Ʈ - �ϳ��� ���ҿ� ���� ���Ҹ� ����Ű�� �ּҰ� ����� ����Ʈ. ���� �������� �ۿ� Ž���� �ȵȴ�. ����Ʈ �߰��� ������ ���� ������ ������. �˻��� ����Ʈ���� ������
//����ũ�帮��Ʈ - �̱۸�ũ�帮��Ʈ�� �����ϱ� ����. ���� �������� Ž���� ����.

//�ڵ�����
#pragma once

template <typename T>
class arraySample
{
public:
	T* buffer;//�����͸� ���� ����
	int size;//�������� ����

	//����Ʈ1
	void Add(T num)
	{
		if (size != 0)//����� 0�� �ƴҶ�
		{
			T* temp;
			temp = new T[size + 1];//���� �������� 1�� ū ���ø� Ÿ�� �迭�� ����
			memcpy(temp, buffer, size * sizeof(T));//���� ������ �ִ� ������ temp������ ����. - �޸� ��ü�� ����
			delete[] buffer;//���� �۹� ���� �޸� ����
			buffer = temp;//
		}
		buffer[size++] = num;//������ ���ҿ� �Ű����� �� �Է�
	}

	int GetSize()//���� ������ ����
	{
		return size;
	}

	//����Ʈ2
	T operator[](int index) const//�Ϲ� �迭[] ó�� ���� �����ϵ���
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
	arraySample<int> asi;//��Ʈ�� ����Ʈ ����

	asi.Add(57);//�� �Է�
	asi.Add(100);
	asi.Add(777);
	asi.Add(321039201);

	for (int i = 0; i < asi.GetSize(); i++)//4���� �Է� �Ǿ������Ƿ� 4�� ��
	{
		cout << "�迭 ���� ������ : " << asi[i] << endl;//������� ���
	}

	arraySample<float> asf;

	asf.Add(3.14);
	asf.Add(7.11);

	for (int i = 0; i < asf.GetSize(); i++)
	{
		cout << "�迭 ���� �Ǽ��� : " << asf[i] << endl;
	}

	arraySample<char*> ascc;

	ascc.Add("���� ���� ���� �����µ�~");
	ascc.Add("���� �ȴ�");
	ascc.Add("ĸƾ �� �� ������ ����");

	for (int i = 0; i < ascc.GetSize(); i++)
	{
		cout << "�迭 ���� ���ڿ��� : " << ascc[i] << endl;
	}

	arraySample<char> asc;

	asc.Add('A');
	asc.Add('V');
	asc.Add('E');

	for (int i = 0; i < asc.GetSize(); i++)
	{
		cout << "�迭 ���� ������ : " << asc[i] << endl;
	}


}