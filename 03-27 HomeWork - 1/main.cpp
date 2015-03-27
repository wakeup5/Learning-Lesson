//조사숙제 - 구조체
//숙제!! - 구조체는 기본형태의 변수들과 자신의 함수를 가지며 사용자가 지정하는 변수형태를 지정하는 것. 클래스와 역할이 같다.

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

	int cardLength = 52;
	int cards[52];
	char cardView[52][5] = 
		{"♠ A", "♠ 2", "♠ 3", "♠ 4", "♠ 5", "♠ 6", "♠ 7", "♠ 8", "♠ 9", "♠10", "♠ J", "♠ Q", "♠ K",
		"◆ A", "◆ 2", "◆ 3", "◆ 4", "◆ 5", "◆ 6", "◆ 7", "◆ 8", "◆ 9", "◆10", "◆ J", "◆ Q", "◆ K",
		"♥ A", "♥ 2", "♥ 3", "♥ 4", "♥ 5", "♥ 6", "♥ 7", "♥ 8", "♥ 9", "♥10", "♥ J", "♥ Q", "♥ K",
		"♣ A", "♣ 2", "♣ 3", "♣ 4", "♣ 5", "♣ 6", "♣ 7", "♣ 8", "♣ 9", "♣10", "♣ J", "♣ Q", "♣ K"};

	int card1, card2, playerCard;

	int cardTurn = 0;

	int desk, sour, temp; //카드 섞는데 필요한 변수들.

	int playerFund = 100000;
	int minBatting = 10000;
	int winnerFund = 1000000;
	int playerInput;

	int gameTurn = 1;

	bool lose = false;
	bool win = false;


	//게임 시작
	cout << "========== 월남뽕? 게임 ==========" << endl;
	cout << "룰 설명입니다. 52장의 트럼프 카드를 섞고, 차례대로 위에서 두장을 뽑은 뒤 바로 다음 카드가 앞서 뽑은 두장의 숫자 사이에 있는지를 가리는 도박 게임입니다." << endl
		<< " 플레이어의 소지금은" << playerFund << "이며 최소 배팅액은 " << minBatting << "입니다."
		<< " 1000000원을 벌면 플레이어는 만족하며 집으로 돌아갑니다. " << endl;

	cout << "그럼 게임을 시작합니다." << endl << "=========================================================" << endl;

	cout << "카드 생성 중입니다.";

	//카드 생성.
	for (int i = 0; i < cardLength; i++)
	{
		//게임에 이용될 카드 초기화.
		cards[i] = i;
		cout << cardView[cards[i]];
	}

	cout << endl << "카드 생성 완료." << endl;
	
	while (true){
		//변수들 초기화.
		cardTurn = 0;
		
		cout << "카드를 섞는 중입니다." << endl;

		//카드 섞기.
		for (int i = 0; i < 1000; i++)
		{
			desk = rand() % cardLength;
			sour = rand() % cardLength;

			temp = cards[desk];
			cards[desk] = cards[sour];
			cards[sour] = temp;
		}
		cout << "카드를 섞었습니다." << endl;

		while (true)
		{
			//카드 두장을 뽑음.
			cout << "========================================" << endl;
			cout << gameTurn << "번째 턴입니다." << endl;
			cout << "카드 두장을 뽑습니다.." << endl << endl;
			
			card1 = cards[cardTurn++];
			card2 = cards[cardTurn++];

			cout << "┌──┐ ┏━━┓ ┌──┐" << endl;
			cout << "│    │ ┃////┃ │    │" << endl;
			cout << "│" << cardView[card1] << "│ ┃////┃ │" << cardView[card2] << "│" << endl;
			cout << "│    │ ┃////┃ │    │" << endl;
			cout << "└──┘ ┗━━┛ └──┘" << endl;

			//베팅
			while (true)
			{
				cout <<  endl << "얼마를 베팅하시겟습니까?" << " 소지금 : " << playerFund << endl;
				cout << "> ";
				cin >> playerInput;
				
				//입력 버퍼 지움.
				cin.clear();              
				cin.ignore(INT_MAX, '\n');

				if (playerInput >= minBatting && playerInput <= playerFund)
				{
					break;
				}

				cout << "잘못 입력하였습니다." << endl;
			}
			
			if (playerInput == playerFund)
			{
				cout << "올인!!" << endl;
			}
			else
			{
				cout << playerInput << "을 베팅하였습니다." << endl;
			}

			playerFund -= playerInput;

			//플레이어 카드 뽑음
			cout << endl << "플레이어의 카드를 뽑습니다." << endl << endl;

			playerCard = cards[cardTurn++];

			cout << "┌──┐ ┏━━┓ ┌──┐" << endl;
			cout << "│    │ ┃    ┃ │    │" << endl;
			cout << "│" << cardView[card1] << "│ ┃" << cardView[playerCard] << "┃ │" << cardView[card2] << "│" << endl;
			cout << "│    │ ┃    ┃ │    │" << endl;
			cout << "└──┘ ┗━━┛ └──┘" << endl;

			//카드 비교
			if (((playerCard % 13) > (card1 % 13) && (playerCard % 13) < (card2 % 13)) || ((playerCard % 13) > (card2 % 13) && (playerCard % 13) < (card1 % 13)))
			{
				playerFund += playerInput * 2;
				cout << endl << "승리 입니다. 배팅액의 두배를 받습니다. 현재 소지금은 " << playerFund << "입니다." << endl;
			}
			else
			{
				cout << endl << "패배 입니다. 배팅액을 잃습니다. 현재 소지금은 " << playerFund << "입니다." << endl;
			}

			cout << "========================================" << endl;
			gameTurn++;

			//카드 전부 소진 여부
			if (cardTurn >= 51)
			{
				cout << endl << "카드가 모두 소진되었습니다." << endl;
				break;
			}

			//게임 패배 조건
			if (playerFund < minBatting)
			{
				cout << "플레이어의 금액이 최소 배팅액보다 낮습니다. 게임에서 졌습니다. 울면서 집으로 갑니다.." << endl;
				lose = true;
				break;
			}

			//게임 승리조건
			if (playerFund > winnerFund)
			{
				cout << "플레이어는 무려 " << playerFund << "를 가지게 되었고, 만족하며 집으로 돌아갑니다.. 플레이어가 이겼습니다." << endl;
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