#include "PhongChieu.h"
#include<iostream>
#include "QuanLy.h"
#pragma once
using namespace std;
class QLPhongChieu : public QuanLy<PhongChieu>
{
private:
public:
    void Show();
    int CheckMS(string s);
    void Update(string);

    friend void UpdateFile_PC(QLPhongChieu&);
    friend void DatVe(int);
    // Menu
    void Menu();
    void ThemPhongChieu();
    void CapNhatPhongChieu();
    void XoaPhongChieu();
    void XemThongTinPhongChieu();
};