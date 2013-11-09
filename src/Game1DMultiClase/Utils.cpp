#include "stdafx.h"
#include "Utils.h"

void gotoxy(int x, int y)
{
	COORD pos = {x, y};
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

int Randomize(int ini, int fin)
{

	return static_cast<int>(rand()%(fin - ini) + ini);
}

void SetColorText(int newColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), newColor);
}

void hidecursor(void) {
	HANDLE hdl;
	hdl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO t;
	t.bVisible = false;
	SetConsoleCursorInfo(hdl, &t);
}
