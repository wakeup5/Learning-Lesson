//������� - ����ü
//time attack - ���ھ߱� �ڵ� �ܿ��� 15�� �ȿ� �ϼ�. ���ϸ� ����.

//Ʈ���� �����̵�, ���̾�, ��Ʈ, Ŭ�ι� a ~ k���� 52��.

//������? �����̶�?
//ī�� 52���� ����. ī�� ��ġ�� ���ʿ� ����.
//������ 52�� ������ ������ ��. ���ӳ����ٰ� �ٽ� ���� ����.
//ī�� ������ ����.

//������ ��.
//�� �������� �־����.
//�ּ� ���þ��� �ִ�.

//���� ī�带 � ó�� �� ���� ���� ���̿� ������ �¸�, �ƴϸ� �й�.

//����� ������ 3���� ī�带 ������ ������ 49���� ������ ����.

//�̱�� �ι�, ���� ����.

//52�� �� �����ϸ� �ٽ� ���´�.

// �ΰ��� ���ų� ������ ���� �ΰ��� ������ �ּ� ������ �ϰ� �׳� �ѱ��. - ���� ��
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand(time(NULL));
	
	int cardLength = 13 * 4;
	int cards[cardLength];
	char cardView[cardLength][3];

	int card1, card2, playerCard;
	int cardPattern, cardNumber;

	int cardsTurn = 0;

	int desk, sour, temp; //ī�� ���µ� �ʿ��� ������.

	int playerFund = 100000;
	int minBatting = 1000;

	int gameTurn = 1;

	bool lose = false;

	cout << "========== ������? ���� ==========" << endl;
	cout << "�� �����Դϴ�. 52���� Ʈ���� ī�带 ����, ���ʴ�� ������ ������ ���� �� �ٷ� ���� ī�尡 �ռ� ���� ������ ���� ���̿� �ִ����� ������ ���� �����Դϴ�. �÷��̾��� ��������"
		<< playerFund << "�̸� �ּ� ���þ��� "
		<< minBatting << "�Դϴ�." << endl;

	cout << "�׷� ������ �����մϴ�." << endl << "=========================================================" << endl;

	cout << "ī�� ���� ���Դϴ�.";

	//ī�� ����.
	for (int i = 0; i < cardsLength; i++)
	{
		//���ӿ� �̿�� ī�� ��ġ �ֱ�.
		cards[i] = i;
		
		//������ ī�忡 ���� �ֱ�.
		if (i / 13 == 0) cardView[i] = "��";
		else if (i / 13 == 1) cardView[i] = "��";
		else if (i / 13 == 2) cardView[i] = "��";
		else if (i / 13 == 3) cardView[i] = "��";

		//������ ī�忡 ���� �ֱ�.
		if (i % 13 == 10) cardView[i][2] = 'J';
		else if (i % 13 == 11) cardView[i][2] = 'Q';
		else if (i % 13 == 12) cardView[i][2] = 'K';
		else cardView[i][2] = i + 1;

		cout << ".";
	}

	for (int i = 0; i < cardLength; i++)
	{
		cout << cardView[i] << endl;
	}

	cout << endl << "ī�� ���� �Ϸ�." << endl;
	
	while (true){
		
		cout << "ī�带 ���� ���Դϴ�." << endl;

		//ī�� ����.
		for (int i = 0, i < 1000; i++)
		{
			desk = rand() % cardLength;
			sour = rand() % cardLength;

			temp = cards[desk];
			cards[desk] = cards[sour];
			cards[sour] = cards[desk];
		}
		cardTurn = 0;
		cout << "ī�带 �������ϴ�." << endl;

		while (true)
		{
			cout << gameTurn << "��° ���Դϴ�." << endl;
			cout << "ī�� ������ �̽��ϴ�.." << endl;
			card1 = cards[cardTurn++];
			card2 = cards[cardTurn++];

			cardPattern = card1 / 4;

		}

	}

	


	return 0;
}