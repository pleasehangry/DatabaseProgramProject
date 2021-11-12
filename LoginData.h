#include<iostream>
#pragma once
#include<string>
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
    Customer(string = "Unknown", string = "Unknown", string = "Member");
    ~Customer();
    void setGmail(string);
    void setMatKhau(string);
    string getGmail();
    string getMatKhau();
};