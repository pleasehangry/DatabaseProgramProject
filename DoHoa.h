#pragma once
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <vector>
#include <string>   
using namespace std;
#include <stdio.h>
#include <conio.h>
#include<ctime> /* thu vi?n h? tr? v? th?i gian th?c */
#define KEY_NONE	-1
void GoTo(int posX, int posY); 
//void draw(int a,int b,int c, int d);
void SetColor(int backgound_color, int text_color);
int whereX();
int whereY();
void ShowCur(bool CursorVisibility);
//int inputKey();
void textcolor(int x);
void box(int x, int y,int w,int h,int t_color,int b_color);
void box(int x, int y,int w,int h,int t_color,int b_color,string nd);
void n_box(int x, int y, int w, int h, int t_color, int b_color, int row);
int menu(vector<string>&);
void thanh_sang(int x, int y, int w, int h, int b_color);
void n_box_ngang(int x, int y,int w,int h,int t_color,int b_color, int col);