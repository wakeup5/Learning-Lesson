#pragma once
class Display
{
protected:
	int _x, _y, _mx, _my, _lineX;
	char*_contents;

	void printLine(char*);
	void setXY(int, int);
	void setXY();
public:
	Display();
	~Display();
	void print();
	void setContents(char*);
};

class Dialogue : public Display
{

};
