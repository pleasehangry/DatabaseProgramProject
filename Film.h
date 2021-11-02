#include<iostream>
#include<iomanip>
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
    void Display();
    void Display2();
    void ShowMenu();
    void Phim();
    void searchFilm();
    void TimkiemPhim();
    ~Film();
};