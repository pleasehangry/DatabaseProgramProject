#include "LichChieu.h"
#include "QLPhongChieu.h"
#include "QuanLyPhim.h"
#include "QuanLy.h"
#pragma once 
class QuanLyLichChieu : public QuanLy<LichChieu>
{
private:
public:
    void TieuDeCot();
    void Show();
    int CheckMS(string s);
    void Update(string m);

    friend void UpdateFile_LichChieu(QuanLyLichChieu& QLLC);
    friend void DatVe(int);

    void XemLichChieuCuaPhim(string);

    // Menu
    void Menu();
    void setLichChieu();
    void CapNhatLichChieu();
    void XoaLichChieu();
};