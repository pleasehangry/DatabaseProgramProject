#include "DoHoa.h"
#include <iostream>
#include <iomanip>
#define KEY_NONE -1
using namespace std;

int x = 1;
int y = 3;
int h = 2;
int w = 40;
int t_color =11;
int b_color = 1;
int b_color_sang = 75;
int row = 6;
int col = 4;

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
	SetConsoleCursorInfo(handle, &cursor);
}
void GoTo(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x, y};
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
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			GoTo(ix, iy);
			cout << " ";
		}
	}
	//============= ve vien =============
	textcolor(1);
	SetColor(0, t_color); //update
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
void box(int x, int y, int w, int h, int t_color, int b_color, string nd)
{
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			GoTo(ix, iy);
			cout << " ";
		}
	}
	SetColor(0, 7);
	GoTo(x + 1, y + 1);
	cout << nd;
	//============= ve vien =============
	textcolor(1);
	SetColor(b_color, t_color); //update
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
		box(x + (i * w), y, w, h, t_color, b_color); //i = 0 => x,y, i = 1: x,y+2
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
		box(x, y + (i * 2), w, h, t_color, b_color); //i = 0 => x,y, i = 1: x,y+2
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
}
int menu()
{
	int index = 1;
	string a[6] = {"1.Xem Hom Nay Co Phim Gi:", "2.Tim Kiem Phim", "3.Tim Kiem Phim Theo The Loai", 
	"4.Doi Mat Khau","5.Xem thong tin ca nhan","6.Dang xuat"};
	ShowCur(0);
	//----- setting ----

	n_box(x, y, w, h, t_color, b_color, row);
	for (int i = 0; i < row; i++)
	{
		GoTo(x + 1, y + (i * h) + 1);
		cout << a[i];
	}

	//-------------
	int xp = x;
	int yp = y; //toa do thanh sang
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
			thanh_sang(xcu, ycu, w, h, b_color); //rs thanh sang cu
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
