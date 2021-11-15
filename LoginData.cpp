#include "LoginData.h"



Customer::Customer(string Gmail, string MatKhau,string HoTen, int SoDu)
{
    this->SoDu = SoDu;
    this->Gmail = Gmail;
    this->MatKhau = MatKhau;
    this->HoTen = HoTen;
    if(SoDu > 1000000){
        this->LoaiKhachHang = "Vip";
    }
    else{
        this->LoaiKhachHang = "Member";
    }
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

void Customer::setSoDu(int SoDu){
    this->SoDu = SoDu;
}
int Customer::getSoDu(){
    return this->SoDu;
}

bool Customer::CheckSoDu(int giave){
    if(this->SoDu > giave){
        this->SoDu -= giave;
        return true;
    }
    return false;
}

void Customer::NapTien(){
    int SoTaiKhoan;
    int SoTien;
    cout << "Nhap So Tai Khoan Ngan Hang: ";
    cin >> SoTaiKhoan;
    cout << "Nhap So Tien Ban Muon Nap: ";
    cin >> SoTien;
    if(SoTien <0) cout << "So Tien Khong Hop Le" << endl;
    else {
        this->SoDu += SoTien;
        cout << "Nap Tien Thanh Cong!" << endl;
    }
}

bool Customer::checkTaiKhoan(string gmail, string mk){
    if(this->Gmail == gmail && this->MatKhau == mk){
        return true;
    }
    return false;
}



void Customer::Show(){
    cout << setw(20-1) << left << this->HoTen << "| ";
    cout << setw(20-1) << left << this->Gmail << "| ";
    cout << setw(20-1) << left << this->MatKhau << "| ";
    cout << setw(20-1) << left << this->SoDu << "| ";
    cout << setw(20-1) << left << this->LoaiKhachHang<< endl;
}

