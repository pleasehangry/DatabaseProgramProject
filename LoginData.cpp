#include "LoginData.h"



Customer::Customer(string Gmail, string MatKhau, string LoaiKhachHang)
{
    this->Gmail = Gmail;
    this->MatKhau = MatKhau;
    this->HoTen = Gmail;
    this->LoaiKhachHang = LoaiKhachHang;
}

Customer::~Customer()
{
}


void Customer::setGmail(string Gmail){
    this->Gmail = Gmail;
}

void Customer::setMatKhau(string MatKhau){
    this->MatKhau = MatKhau;
}

string Customer::getGmail(){
    return this->Gmail;
}

string Customer::getMatKhau(){
    return this->MatKhau;
}
