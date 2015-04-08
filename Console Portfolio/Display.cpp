#include "Display.h"
#include <Windows.h>
#include <iostream>
#include <string.h>

//#define _CRT_SECURE_NO_WARNINGS

Display::Display()
{
	_mx = 100;
	_my = 40;
}


Display::~Display()
{
	//delete this;
}

void Display::setContents(char* contents)
{
	_contents = contents;
}

void Display::print()
{
	//setXY(50, 38);
	char contents[4000];
	strcpy_s(contents, _contents);

	char* pointer = NULL;
	char* next = NULL;

	pointer = strtok_s(contents, "\n", &next);
	printLine(pointer);

	while ((pointer = strtok_s(NULL, "\n", &next)) != NULL)
	{
		printLine(pointer);
	} 
}

void Display::setXY(int x, int y)
{
	_x = x;
	_y = y;
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Display::setXY()
{
	COORD pos = { _x, _y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Display::printLine(char* line)
{
	if (_y > _my) return;

	_lineX = _mx - _x;
	if (_lineX < 0) _lineX = 0;

	setXY(_x, _y);
	_y++;

	printf("%.*s", _lineX, line);
}