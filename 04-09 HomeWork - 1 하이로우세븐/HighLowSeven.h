#pragma once
struct CardPosition
{
	int x;
	int y;
};

enum GAME_RESULT
{
	GAME_HIGH_WIN, GAME_LOW_WIN, GAME_SEVEN_WIN, GAME_LOSE
};

class HighLowSeven
{
private:
	int _cards[52];
	int _viewCards[4];
	int _playerCard;

	int _cardTurn;
	int _gameTurn;
	CardPosition* _cardPosition;

	int _fund;

	int _lineX, _lineY;

	void createCards();
	void suffleCards();
	void printCard(int, int = 0, int = 0);
	void printBackCard(int = 0, int = 0);
	int batting();
	int selectHighLowSeven();
	GAME_RESULT checkCard(int, int);
	void clearDisplayAndCursor();

public:
	HighLowSeven();
	~HighLowSeven();
	void startGame(void);

	int getFund();
	void setFund(int);
};

