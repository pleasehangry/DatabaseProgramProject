#include "DoHoa.h"
#include <iostream>
#include <iomanip>
#define KEY_NONE -1
using namespace std;

int x = 70;
int y = 5;
int h = 2;
int w = 40;
int b_color_sang = 75;
int t_color=7;
int b_color=8;
int row = 4;
int col = 4;

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
	SetConsoleCursorInfo(handle, &cursor);
}
void GoTo(SHORT posX, SHORT posY)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {posX, posY};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
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

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void box(int x, int y, int w, int h, int t_color, int b_color)
{
	// textcolor(b_color);
	// for (int iy = y + 1; iy <= y + h - 1; iy++)
	// {
	// 	for (int ix = x + 1; ix <= x + w - 1; ix++)
	// 	{
	// 		GoTo(ix, iy);
	// 		cout << " ";
	// 	}
	// }
	//============= ve vien =============
	textcolor(1);
	SetColor(0, t_color); // update
	if (h <= 1 || w <= 1)
		return;
	for (int ix = x; ix <= x + w; ix++)
	{
		GoTo(ix, y);
		cout << char(196);
		GoTo(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		GoTo(x, iy);
		cout << char(179);
		GoTo(x + w, iy);
		cout << char(179);
	}
	GoTo(x, y);
	cout << char(218);
	GoTo(x + w, y);
	cout << char(191);
	GoTo(x, y + h);
	cout << char(192);
	GoTo(x + w, y + h);
	cout << char(217);
	GoTo(x+1,y+1);
}
void box(int x, int y, int w, int h, int t_color, int b_color, string nd)
{
	// textcolor(b_color);
	// w=whereX();
	SetColor(0, 7);
	GoTo(x + 1, y + 1);
	cout << nd;
	//============= ve vien =============
	textcolor(1);
	SetColor(b_color, t_color); // update
	if (h <= 1 || w <= 1)
		return;
	for (int ix = x; ix <= x + w; ix++)
	{
		GoTo(ix, y);
		cout << char(196);
		GoTo(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		GoTo(x, iy);
		cout << char(179);
		GoTo(x + w, iy);
		cout << char(179);
	}
	GoTo(x, y);
	cout << char(218);
	GoTo(x + w, y);
	cout << char(191);
	GoTo(x, y + h);
	cout << char(192);
	GoTo(x + w, y + h);
	cout << char(217);
}
void n_box_ngang(int x, int y, int w, int h, int t_color, int b_color, int col)
{
	for (int i = 0; i < col; i++)
	{
		box(x + (i * w), y, w, h, t_color, b_color); // i = 0 => x,y, i = 1: x,y+2
		if (i != 0)
		{
			GoTo(x + (i * w), y);
			cout << char(194);
			GoTo(x + (i * w), y + h);
			cout << char(193);
		}
	}
}
void n_box(int x, int y, int w, int h, int t_color, int b_color, int row)
{
	for (int i = 0; i < row; i++)
	{
		box(x, y + (i * 2), w, h, t_color, b_color); // i = 0 => x,y, i = 1: x,y+2
		if (i != 0)
		{
			GoTo(x, y + (i * 2));
			cout << char(195);
			GoTo(x + w, y + (i * 2));
			cout << char(180);
		}
	}
}
void bang(int x, int y, int w, int h, int t_color, int b_color, int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		n_box_ngang(x, y + (i * h), w, h, t_color, b_color, col);
		GoTo(x, y + (i * h));
		if (i != 0)
		{
			GoTo(x, y + (i * h));
			cout << char(195);
			GoTo(x + w, y + (i * h));
			cout << char(180);
		}
	}
}

void thanh_sang(int x, int y, int w, int h, int b_color)
{
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{

		GoTo(x + w - 2, iy);
		cout << " ";
	}
	SetColor(0,15);
}
int menu(vector<string>& a)
{  int t_color=1,b_color=0;

	int index = 10;
	ShowCur(0);
	//----- setting ----
	int row = a.size();
	n_box(x, y, w, h, t_color, b_color, row);
	for (int i = 0; i < row; i++)
	{
		GoTo(x + 1, y + (i * h) + 1);
		cout << a[i];
	}

	//-------------
	int xp = x;
	int yp = y; // toa do thanh sang
	int xcu = xp;
	int ycu = yp;
	bool kt = true;
	while (true)
	{
		//------ in ----
		if (kt == true)
		{
			//----- back space ----
			GoTo(xcu, ycu);
			thanh_sang(xcu, ycu, w, h, b_color); // rs thanh sang cu
			xcu = xp;
			ycu = yp;
			//-------------
			thanh_sang(xp, yp, w, h, b_color_sang);
			kt = false;
		}
		//----- dieu khien ---- //----- di chuyen ----
		if (_kbhit())
		{
			int i = (yp - y) / h + 1;
			char c = _getch();
			if (c == 13)
			{
				GoTo(x, y + row * h + 1);
				SetColor(0, 1);
				return i;
			}

			//---- speed ----

			if (c == -32)
			{
				kt = true; // d? b?m
				c = _getch();
				if (c == 72)
				{
					if (yp != y)
						yp -= 2;
					else
					{
						yp = y + h * (row - 1);
					}
				}
				else if (c == 80)
				{
					if (yp != y + h * (row - 1))
						yp += 2;
					else
					{
						yp = y;
					}
				}
			}
		}
	}
	return index;
}
int menu2(vector<string>& a)
{
	int index = 10;
	ShowCur(0);
	//----- setting ----
	int row = a.size();
	int x = 5;
	int y = whereY();
	n_box(x, y, w + 2, h, t_color, b_color, row);
	for (int i = 0; i < row; i++)
	{
		GoTo(x + 1, y + (i * h) + 1);
		cout << a[i];
	}

	//-------------
	int xp = x;
	int yp = y; // toa do thanh sang
	int xcu = xp;
	int ycu = yp;
	bool kt = true;
	while (true)
	{
		//------ in ----
		if (kt == true)
		{
			//----- back space ----
			GoTo(xcu, ycu);
			thanh_sang(xcu, ycu, w, h, b_color); // rs thanh sang cu
			xcu = xp;
			ycu = yp;
			//-------------
			thanh_sang(xp, yp, w, h, b_color_sang);
			kt = false;
		}
		//----- dieu khien ---- //----- di chuyen ----
		if (_kbhit())
		{
			int i = (yp - y) / h + 1;
			char c = _getch();
			if (c == 13)
			{
				GoTo(x, y + row * h + 1);
				SetColor(0, 1);
				return i;
			}

			//---- speed ----

			if (c == -32)
			{
				kt = true; // d? b?m
				c = _getch();
				if (c == 72)
				{
					if (yp != y)
						yp -= 2;
					else
					{
						yp = y + h * (row - 1);
					}
				}
				else if (c == 80)
				{
					if (yp != y + h * (row - 1))
						yp += 2;
					else
					{
						yp = y;
					}
				}
			}
		}
	}
	return index;
}
void CanLe(int x, int y){
	GoTo(x,y);
}
