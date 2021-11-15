#include "Film.h"
#include"DoHoa.h"
#include<string>
#pragma once
class QuanLyPhim
{
private:
    Film *p;
    int n;
public:
    QuanLyPhim();
    ~QuanLyPhim();
    void Show();
    void Add_Film(const Film&);
    void TieuDeCot();
    int checkMSFilm(string);
    int IndexOf(string);
    friend void UpdateFile_Phim(QuanLyPhim&);
    void Update_Film(string);
    void Delete_Film(string);
    void XemTheloaiPhim();
    void XemDSPhimCuaTheLoai();
    void TimKiemPhim();
    void MenuChoKhach();
    string getFimlName(int);
    friend void XemLichChieuCuaPhim(string);
    // da nang hoa
    Film& operator[](const int&);
};