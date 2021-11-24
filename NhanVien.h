#include<iostream>
#include<string>
#include<conio.h>
#include"DoHoa.h"
#pragma once
using namespace std;

class NhanVien
{
private:
    string MaNhanVien;
    string HoTen;
    string NgaySinh;
    string QueQuan;
    string SoDienThoai;
    string SoCMT;
    string ChucVu;
    string PhanQuyen;
    string TaiKhoan;
    string MatKhau;
public:
    NhanVien(string = "Unknown", string = "Unknown", string = "Unknown", string = "Unknown", string = "Unknown", string = "Unknown", string = "Unknown", string = "Unknown", string = "admin", string = "password");
    ~NhanVien();
    string getMaNV();
    string getHoTen();
    string getNgaySinh();
    string getQueQuan();
    string getSDT();
    string getSoCMT();
    string getChucVu();
    string getPhanQuyen();
    string getTaiKhoan();
    string getMatKhau();

    void setMaNV(string );
    void setHoTen(string );
    void setNgaySinh(string );
    void setQueQuan(string );
    void setSDT(string );
    void setSoCMT(string );
    void setChucVu(string );
    void setPhanQuyen(string );
    void setTaiKhoan(string );
    void setMatKhau(string );

    void Display();
    void Display2();
    //Da Nang Hoa;
    friend istream& operator>>(istream& i,NhanVien&);
};