#include <iostream>

using namespace std;

int main()
{
	char c;
	int n1;
	float n2;
	bool b;
	int n3;

	cout << "���ϴ´�� �Է��Ͻÿ�." << endl;
	cout << "'Y' Ȥ�� 'N'�� �Է��ϰ� ���͸� ġ�ÿ�." << endl;
	cout << "�Է� : ";

	cin >> c;

	//������ �Է��ϸ� �긣�� �������� ã�ƺ��� �Էµ� ���� �������� �ѱ��� �ʰ� ����� �ڵ���ϴ�.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();

	if (c == 'Y')
	{
		cout << "'Y'�� �Է��Ͽ���." << endl;
	}
	else if (c == 'N')
	{
		cout << "'N'�� �Է��Ͽ���." << endl;
	}
	else
	{
		cout << "���߼�." << endl;
		//return 0;
	}

	cout << endl << "���� �ΰ��� �Է¹��� ���̿�. �ϳ��� 5 ~ 15������ ������, �ٸ� �ϳ��� 1.1 ~ 1.9 ������ �Ǽ��� �Է��Ͻÿ�." << endl;
	cout << "���� �Է� : ";
	cin >> n1;

	//������ �Է��ϸ� �긣�� �������� ã�ƺ��� �Էµ� ���� �������� �ѱ��� �ʰ� ����� �ڵ���ϴ�.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();

	cout << "�Ǽ� �Է� : ";
	cin >> n2;

	//������ �Է��ϸ� �긣�� �������� ã�ƺ��� �Էµ� ���� �������� �ѱ��� �ʰ� ����� �ڵ���ϴ�.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();

	if ((n1 >= 5 && n1 < 15) && (n2 >= 1.1 && n2 < 1.9))
	{
		cout << "������ " << n1 << ", �Ǽ��� " << n2 << "�� �Է��Ͽ���. ���� ���Ͽ���." << endl;
	}
	else if (n1 >= 5 && n1 < 15)
	{
		cout << "������ " << n1 << "�� �� �Է��Ͽ����� �Ǽ��� " << n2 << "�� �Է��Ͽ���. �ϳ��� ���ܼ�." << endl;
	}
	else if (n2 >= 1.1 && n2 < 1.9)
	{
		cout << "�Ǽ��� " << n2 << "�� �� �Է��Ͽ����� ������ " << n1 << "�� �Է��Ͽ���. �ϳ��� ���ܼ�." << endl;
	}
	else
	{
		cout << "���߼�." << endl;
	}

	cout << endl << "�̹��� ���� Ȥ�� �����̿�. �˾Ƽ� �Է��Ͻÿ�." << endl;
	cout << "�Է� : ";
	cin >> b;

	//������ �Է��ϸ� �긣�� �������� ã�ƺ��� �Էµ� ���� �������� �ѱ��� �ʰ� ����� �ڵ���ϴ�.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();
	
	if (b)
	{
		cout << "���� �Է��Ͽ���." << endl;
	}
	else
	{
		cout << "������ �Է��Ͽ���." << endl;
	}

	cout << endl << "�������̿�. ����� Ű�� �Է��Ͻÿ�." << endl;
	cout << "�Է� : ";
	cin >> n3;

	//������ �Է��ϸ� �긣�� �������� ã�ƺ��� �Էµ� ���� �������� �ѱ��� �ʰ� ����� �ڵ���ϴ�.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.clear();

	if (n3 < 0)
	{
		cout << "����� Ű�� ���̳ʽ� �ΰ̴ϱ�.." << endl;
	}
	else if (n3 >= 0 && n3 < 100)
	{
		cout << "�������� ~ ������" << endl;
	}
	else if (n3 >= 100 && n3 < 150)
	{
		cout << "ȭ����.." << endl;
	}
	else if (n3 >= 150 && n3 < 180)
	{
		cout << "good" << endl;
	}
	else{
		cout << "ũ��." << endl;
	}

	return 0;
}
/*
 * ������?
 * ��Ģ�� ���� ������ ���� �̾ƿ��°�.
 *
 * switch��?
 * �ϳ��� ������ ���� ���� �ڵ带 �б��Ŵ!! ���� if ~ else if ~ else�� ���ɶ� ������� ��� �� �� �ִ�.
 *
 * switch(����){
 * case ��1:
 *		�������� ��1�϶� ó��
 *		break;
 * case ��2:
 *		�������� ��2�϶� ó��
 *		break;
 * defualt :
 *		�������� case���� ���� �ش������.
 *
 * }
 */