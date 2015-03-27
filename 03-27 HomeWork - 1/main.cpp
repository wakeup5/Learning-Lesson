//조사숙제 - 구조체
//time attack - 숫자야구 코드 외워서 15분 안에 완성. 못하면 깜지.

//트럼프 스페이드, 다이아, 하트, 클로버 a ~ k까지 52장.

//월남뽕? 게임이란?
//카드 52장을 섞음. 카드 뭉치를 한쪽에 놔둠.
//섞어진 52장 가지고 게임을 함. 게임끝난다고 다시 섞지 않음.
//카드 두장을 뽑음.

//배팅을 함.
//내 소지금이 있어야함.
//최소 배팅액이 있다.

//다음 카드를 까서 처음 깐 두장 숫자 사이에 있으면 승리, 아니면 패배.

//결과가 나오면 3개의 카드를 버리고 나머지 49장을 가지고 시작.

//이기면 두배, 지면 날림.

//52장 다 소진하면 다시 섞는다.

// 두개의 같거나 인접한 숫자 두개가 나오면 최소 배팅을 하고 그냥 넘긴다. - 게임 룰
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

	int desk, sour, temp; //카드 섞는데 필요한 변수들.

	int playerFund = 100000;
	int minBatting = 1000;

	int gameTurn = 1;

	bool lose = false;

	cout << "========== 월남뽕? 게임 ==========" << endl;
	cout << "룰 설명입니다. 52장의 트럼프 카드를 섞고, 차례대로 위에서 두장을 뽑은 뒤 바로 다음 카드가 앞서 뽑은 두장의 숫자 사이에 있는지를 가리는 도박 게임입니다. 플레이어의 소지금은"
		<< playerFund << "이며 최소 배팅액은 "
		<< minBatting << "입니다." << endl;

	cout << "그럼 게임을 시작합니다." << endl << "=========================================================" << endl;

	cout << "카드 생성 중입니다.";

	//카드 생성.
	for (int i = 0; i < cardsLength; i++)
	{
		//게임에 이용될 카드 뭉치 넣기.
		cards[i] = i;
		
		//보여줄 카드에 문양 넣기.
		if (i / 13 == 0) cardView[i] = "♠";
		else if (i / 13 == 1) cardView[i] = "♥";
		else if (i / 13 == 2) cardView[i] = "◆";
		else if (i / 13 == 3) cardView[i] = "♣";

		//보여줄 카드에 숫자 넣기.
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

	cout << endl << "카드 생성 완료." << endl;
	
	while (true){
		
		cout << "카드를 섞는 중입니다." << endl;

		//카드 섞기.
		for (int i = 0, i < 1000; i++)
		{
			desk = rand() % cardLength;
			sour = rand() % cardLength;

			temp = cards[desk];
			cards[desk] = cards[sour];
			cards[sour] = cards[desk];
		}
		cardTurn = 0;
		cout << "카드를 섞었습니다." << endl;

		while (true)
		{
			cout << gameTurn << "번째 턴입니다." << endl;
			cout << "카드 두장을 뽑습니다.." << endl;
			card1 = cards[cardTurn++];
			card2 = cards[cardTurn++];

			cardPattern = card1 / 4;

		}

	}

	


	return 0;
}