#include "stdafx.h"
#include "Utils.h"

void gotoxy(int x, int y)
{
	COORD pos = {x, y};
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

int Randomize(int i)
{
	return static_cast<int>(rand()%i);
}

void SetColorText(int newColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), newColor);
}
