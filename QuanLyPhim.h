#include "Film.h"
#include"DoHoa.h"
#include<string>
#include "QuanLy.h"
#include <cstring>
#pragma once
class QuanLyPhim : public QuanLy<Film>
{
private:
public:
    void Show();
    void TieuDeCot();
    int CheckMS(string);
    void Update(string);
    friend void UpdateFile_Phim(QuanLyPhim&);


    void XemTheloaiPhim();
    void XemDSPhimCuaTheLoai();
    void TimKiemPhim();
    string getFimlName(int);
    friend void XemLichChieuCuaPhim(string);
    // Menu
    void Menu();
    void ThemPhim();
    void CapNhatPhim();
    void XoaPhim();
    void XemThongTinPhim();
};