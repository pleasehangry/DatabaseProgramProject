#include "DoHoa.h"
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

void box(int x, int y, int w, int h, int t_color, int b_color, string nd){

    SetColor(1,5);
    for (int iy = y+1; iy < y + h-1; iy++)
    {
        for (int ix = x + 1; ix < x + w-1; ix++)
        {
            GoTo(ix, iy); cout << " ";
        }
        
    }
    SetColor(0,6); GoTo(x + 1, y + 1); cout << nd;
    SetColor(0,3);
    if(w <= 1 || h <= 1) return;
    for (int ix = x; ix < x + w; ix++)
    {
        GoTo(ix, y);
        cout << char(196);
        GoTo(ix, y+h);
        cout << char(196);
    }
    for (int iy = 0; iy < y + h; iy++)
    {
        GoTo(x, iy);
        cout << char(179);  
        GoTo(x+h, iy);
        cout << char(179);
    }
    GoTo(x,y); cout << char(218);
    GoTo(x,y+h); cout << char(192);
    GoTo(x+w,y+h); cout << char(217);
    GoTo(x+w,y); cout << char(191);
    
    
}