#include<iostream>
#include<iomanip>
#pragma once
using namespace std;

class Ve
{
private:
    string MaVe;
    string MaPhim;
    string LoaiKhachHang;
    int GiaLoaiVe;
    int SoLuong;
    int SoVeDaBan;
    
public:
    Ve(string = "Unknown", string = "Unknown", string = "Unknown",int = 45000,int = 0,int = 0);
    ~Ve();
    string GetMaVe();
    int ThanhTien();

    void Display();

    void setMaVe(string);
    void setMaPhim(string);
    void setLoaiKhachHang(string);
    void setGiaLoaiVe(int);
    void setSoLuong(int);
    void setSoVeDaBan(int);
    void ThemSoVeDaBan(int);

    string  getMaVe();
    string  getMaPhim();
    string  getLoaiKhachHang();
    int getGiaLoaiVe();
    int getSoLuong();
    int getSoVeDaBan();
};

