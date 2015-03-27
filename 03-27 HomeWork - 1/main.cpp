//������� - ����ü
//����!! - ����ü�� �⺻������ ������� �ڽ��� �Լ��� ������ ����ڰ� �����ϴ� �������¸� �����ϴ� ��. Ŭ������ ������ ����.

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

	int cardLength = 52;
	int cards[52];

	int card1, card2, playerCard;

	int cardTurn = 0;

	int desk, sour, temp; //ī�� ���µ� �ʿ��� ������.

	int playerFund = 100000;
	int minBatting = 10000;
	int winnerFund = 1000000;
	int playerInput;

	int gameTurn = 1;

	bool lose = false;
	bool win = false;

	cout << "========== ������? ���� ==========" << endl;
	cout << "�� �����Դϴ�. 52���� Ʈ���� ī�带 ����, ���ʴ�� ������ ������ ���� �� �ٷ� ���� ī�尡 �ռ� ���� ������ ���� ���̿� �ִ����� ������ ���� �����Դϴ�." << endl
		<< " �÷��̾��� ��������" << playerFund << "�̸� �ּ� ���þ��� " << minBatting << "�Դϴ�."
		<< " 1000000���� ���� �÷��̾�� �����ϸ� ������ ���ư��ϴ�. " << endl;

	cout << "�׷� ������ �����մϴ�." << endl << "=========================================================" << endl;

	cout << "ī�� ���� ���Դϴ�.";

	//ī�� ����.
	for (int i = 0; i < cardLength; i++)
	{
		//���ӿ� �̿�� ī�� �ʱ�ȭ.
		cards[i] = i;
		cout << ".";
	}

	cout << endl << "ī�� ���� �Ϸ�." << endl;
	
	while (true){
		//������ �ʱ�ȭ.
		cardTurn = 0;
		
		cout << "ī�带 ���� ���Դϴ�." << endl;

		//ī�� ����.
		for (int i = 0; i < 1000; i++)
		{
			desk = rand() % cardLength;
			sour = rand() % cardLength;

			temp = cards[desk];
			cards[desk] = cards[sour];
			cards[sour] = temp;
		}
		cout << "ī�带 �������ϴ�." << endl;

		while (true)
		{
			//ī�� ������ ����.
			cout << "========================================" << endl;
			cout << gameTurn << "��° ���Դϴ�." << endl;
			cout << "ī�� ������ �̽��ϴ�.." << endl << endl;
			
			card1 = cards[cardTurn++];
			//cout << cardTurn << ", " << cards[cardTurn] << endl;
			card2 = cards[cardTurn++];
			//cout << cardTurn << ", " << cards[cardTurn] << endl;

			switch (card1 / 13){
			case 0:
				cout << "��";
				break;
			case 1:
				cout << "��";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			}
			switch ((card1 % 13) + 1){
			case 11:
				cout << 'J';
				break;
			case 12:
				cout << 'Q';
				break;
			case 13:
				cout << 'K';
				break;
			default:
				cout << (card1 % 13) + 1;
				break;
			}

			cout << ", ";

			switch (card2 / 13){
			case 0:
				cout << "��";
				break;
			case 1:
				cout << "��";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��";
				break;
			}
			switch ((card2 % 13) + 1){
			case 11:
				cout << 'J';
				break;
			case 12:
				cout << 'Q';
				break;
			case 13:
				cout << 'K';
				break;
			default:
				cout << (card2 % 13) + 1;
				break;
			}

			//����
			while (true)
			{
				playerInput = 0;

				cout << endl << endl << "�����Ͻðٽ��ϱ�?" << endl;
				cout << "������ : " << playerFund << " > ";
				cin >> playerInput;
				
				//�Էµ� ���� �����. ��ó - http://blog.naver.com/sarah7_2000/80198931198
				cin.clear();              
				cin.ignore(INT_MAX, '\n');

				if (playerInput < minBatting || playerInput > playerFund)
				{
					cout << "�߸� �Է��Ͽ����ϴ�." << endl;
					continue;
				}

				cout << playerInput << "�� �����Ͽ����ϴ�." << endl;
				playerFund -= playerInput;

				break;
			}

			//�÷��̾� ī�� ����
			cout << endl << "�÷��̾��� ī�带 �̽��ϴ�." << endl;

			playerCard = cards[cardTurn++];

			switch (playerCard / 13){
			case 0:
				cout << "��";
				break;
			case 1:
				cout << "��";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
				cout << "��" ;
				break;
			}
			switch ((playerCard % 13) + 1){
			case 11:
				cout << 'J';
				break;
			case 12:
				cout << 'Q';
				break;
			case 13:
				cout << 'K';
				break;
			default:
				cout << (playerCard % 13) + 1;
				break;
			}

			cout << "�� ���Խ��ϴ�." << endl;

			//ī�� ��
			if (((playerCard % 13) > (card1 % 13) && (playerCard % 13) < (card2 % 13)) || ((playerCard % 13) > (card2 % 13) && (playerCard % 13) < (card1 % 13)))
			{
				playerFund += playerInput * 2;
				cout << endl << "�¸� �Դϴ�. ���þ��� �ι踦 �޽��ϴ�. ���� �������� " << playerFund << "�Դϴ�." << endl;
			}
			else
			{
				cout << endl << "�й� �Դϴ�. ���þ��� �ҽ��ϴ�. ���� �������� " << playerFund << "�Դϴ�." << endl;
			}

			cout << "========================================" << endl;
			gameTurn++;

			//ī�� ���� ���� ����
			if (cardTurn >= 51)
			{
				cout << endl << "ī�尡 ��� �����Ǿ����ϴ�." << endl;
				break;
			}

			//���� �й� ����
			if (playerFund < minBatting)
			{
				cout << "�÷��̾��� �ݾ��� �ּ� ���þ׺��� �����ϴ�. ���ӿ��� �����ϴ�." << endl;
				lose = true;
				break;
			}

			//���� �¸�����
			if (playerFund > winnerFund)
			{
				cout << "�÷��̾�� ���� " << playerFund << "�� ������ �Ǿ���, �����ϸ� ������ ���ư��ϴ�.. �÷��̾ �̰���ϴ�." << endl;
				win = true;
				break;
			}
		}

		if (lose || win)
		{
			break;
		}
	}
	
	return 0;
}