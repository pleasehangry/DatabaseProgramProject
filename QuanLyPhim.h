#include "Film.h"
#include <string>
#include "DoHoa.h"
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
    void TieuDeCot();
    string getFimlName(int);
    void Add_Film(const Film&);
    int checkMSFilm(string);
    int IndexOf(string);
    friend void UpdateFile_Phim(QuanLyPhim&);
    void Update_Film(string);
    void Delete_Film(string);
    void XemTheloaiPhim();
    void XemDSPhimCuaTheLoai(string);
    void TimKiemPhim();
    void MenuChoKhach();
    friend void XemLichChieuCuaPhim(string);
};