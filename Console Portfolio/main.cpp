//#include "Display.h"
#include <iostream>
//#include <string.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

void main()
{
	PlaySound(TEXT("track01.wav"), NULL, SND_ASYNC);
	std::cin.get();
}