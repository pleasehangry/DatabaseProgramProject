#include "DoHoa.h"
#include <iostream>
#include <string>
#define MAX 100
using namespace std;
int x = 50;int y = 5;
//===============

void GoTo(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}
void draw(int a,int b,int c, int d){
	   GoTo(a,b);for (int i=a;i<=c;i++) cout << "_";
	   GoTo(a,d);for (int i=a;i<=c;i++) cout << "_";
	   for (int i=1;i<=d-b;i++) {GoTo(a-1,b+i);cout << "|" << endl;}
	   for (int i=1;i<=d-b;i++) {GoTo(c+1,b+i);cout << "|" << endl;}
}
void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
//========= l?y t?a d? y c?a con tr? hi?n t?i =======
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}


//============= d?t m�u cho ch? =========
// void SetColor(WORD color)
// {
// 	HANDLE hConsoleOutput;
// 	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

// 	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
// 	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

// 	WORD wAttributes = screen_buffer_info.wAttributes;
// 	color &= 0x000f;
// 	wAttributes &= 0xfff0;
// 	wAttributes |= color;

// 	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
// }
//============== l�m ?n tr? chu?t ===========
void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}
//======= tr? v? m� ph�m ngu?i d�ng b?m =========
int inputKey()
{
	if (_kbhit()) //true
	{
		int key = _getch();

		if (key == 224)
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return KEY_NONE;
	}
	return KEY_NONE;
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
