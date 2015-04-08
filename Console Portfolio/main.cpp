#include "Display.h"
#include <iostream>
#include <string.h>

void main()
{
	Display display;
	char* contents =
		"11111\n"
		"22222\n"
		"33333\n";
	display.setContents(contents);
	display.print();
}