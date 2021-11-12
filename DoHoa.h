#pragma once
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>   
using namespace std;
void GoTo(SHORT posX, SHORT posY); 
void draw(int a,int b,int c, int d);
void SetColor(int backgound_color, int text_color);
void box(int x, int y, int w, int h, int t_color, int b_color, string nd);