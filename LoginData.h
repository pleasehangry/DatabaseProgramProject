#include<iostream>
#pragma once
#include<string>
#include<iomanip>
#include<vector>
#include<map>
#include <cstring>
using namespace std;

class Customer
{
private:
    string Gmail;
    string MatKhau;
    int SoDu;
public:
    string LoaiKhachHang;
    string HoTen;
    Customer(string = "Unknown", string = "Unknown",string = "Unknown", int = 50000);
    ~Customer();
    void setGmail(string);
    void setMatKhau(string);
    void setSoDu(int);
    int getSoDu();
    string getGmail();
    string getMatKhau();
    bool checkTaiKhoan(string, string);
    bool CheckSoDu(int);
    void NapTien();
    void Show();
    void Show2();
    Customer& operator=(const Customer&);
};

void Display(vector<Customer>& CTM,int& SoKhach);
void ThemNguoiDung(vector<Customer>& CTM,int& SoKhach);
void Menu_Khach(vector<Customer>& CTM,int& SoKhach);
void XoaNguoiDung(vector<Customer>& CTM,int& SoKhach);
void CapNhatNguoiDung(vector<Customer>& CTM,int& SoKhach);
void NapTienNguoiDung(vector<Customer>& CTM,int& SoKhach);
void TimKiemNguoiDung(vector<Customer>& CTM,int& SoKhach);