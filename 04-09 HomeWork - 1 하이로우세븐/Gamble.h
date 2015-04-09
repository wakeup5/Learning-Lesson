#pragma once
struct CardPosition
{
	int x;
	int y;
};

void gotoxy(int x, int y);
void setcolor(int color, int bgcolor);

class Gamble
{
protected:
	int _fund;
	int _minBatting;

	int _lineX, _lineY;

	virtual void createCards();
	virtual void suffleCards();
	virtual void printCard(int, int = 0, int = 0);
	virtual void printBackCard(int = 0, int = 0);

	virtual int batting();
	void clearDisplayAndCursor();
	virtual void printGameInfo();
public:
	Gamble();
	~Gamble();

	virtual void startGame();

	void setFund(int);
	int getFund();
};

