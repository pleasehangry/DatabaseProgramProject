#include "LichChieu.h"
#include "QLPhongChieu.h"
#include "QuanLyPhim.h"
#pragma once
class QuanLyLichChieu
{
private:
    LichChieu *p;
    int n;
public:
    QuanLyLichChieu();
    ~QuanLyLichChieu();

    void Add_LichChieu(const LichChieu &f);
    void TieuDeCot();
    void Show();
    int checkMaLichChieu(string s);
    void Update_LichChieu(string m);
    void Delete_LichChieu(string m);
    void setLichChieu();
};