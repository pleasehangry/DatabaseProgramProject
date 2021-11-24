#include<iostream>
#include<iomanip>
#include<string>
#include"DoHoa.h"
#pragma once
using namespace std;

class Film
{
private:
    string maPhim;
    string tenPhim;
    string theLoai;
    string thoiLuong;
    string daoDien;
    string dienVien;
    string namCongChieu;
    string quocGia;
public:
    Film(string = "Unknown", string = "Unknown", string = "Unknown", string = "Unknown", string = "Unknown", string = "Unknown", string = "Unknown", string = "Unknown");

    void setMaPhim(string);
    void setTenPhim(string);
    void setTheLoai(string);
    void setThoiLuong(string);
    void setDaoDien(string);
    void setDienVien(string);
    void setNamCongChieu(string);
    void setQuocGia(string);

    string getMaPhim();
    string getTenPhim();
    string getTheLoai();
    string getThoiLuong();
    string getDaoDien();
    string getDienVien();
    string getQuocGia();
    string getNamCongChieu();
    void Display();
    void Display2();
    ~Film();

    //da nang hoa
    friend ostream& operator<<(ostream&, const Film&);
    friend istream& operator>>(istream&, Film&);
};