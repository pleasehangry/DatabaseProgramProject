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
    string getFimlName(int);
    void Update_Film(string);
    void Delete_Film(string);
    void XemTheloaiPhim();
    void XemDSPhimCuaTheLoai(string);
    void TimKiemPhim();
    void MenuChoKhach();   
};