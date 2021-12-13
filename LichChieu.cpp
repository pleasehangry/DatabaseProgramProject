#include "LichChieu.h"
#include <iomanip>

LichChieu::LichChieu(string MaLichChieu, string TenPhim, string Ngay, string Gio, string PhongChieu)
{
    this->MaLichChieu = MaLichChieu;
    this->TenPhim = TenPhim;
    this->Ngay = Ngay;
    this->Gio = Gio;
    this->PhongChieu = PhongChieu;
}

void LichChieu::setMaLichChieu(string MaLichChieu){
    this->MaLichChieu = MaLichChieu;
}
void LichChieu::setTenPhim(string TenPhim){
    this->TenPhim = TenPhim;
}
void LichChieu::setNgay(string Ngay){
    this->Ngay = Ngay;
}
void LichChieu::setGio(string Gio){
    this->Gio = Gio;
}
void LichChieu::setPhongChieu(string PhongChieu){
    this->PhongChieu = PhongChieu;
}

string LichChieu::getMaLichChieu(){
    return this->MaLichChieu;
}
string LichChieu::getTenPhim(){
    return this->TenPhim;
}
string LichChieu::getNgay(){
    return this->Ngay;
}
string LichChieu::getGio(){
    return this->Gio;
}
string LichChieu::getPhongChieu(){
    return this->PhongChieu;
}


void LichChieu::Display(){
    cout <<char(179)<< setw(20-1) << left << this->MaLichChieu<<char(179);
    cout << setw(30-1) << left << this->TenPhim <<char(179);
    cout << setw(20-1) << left << this->Ngay <<char(179);
    cout << setw(20-1) << left << this->Gio <<char(179);
    cout << setw(20-1) << left << this->PhongChieu <<char(179)<< endl;
}

LichChieu::~LichChieu()
{
}

string LichChieu::Xuat(){
    string l;
    if(this->getGio() == "9:00 PM") l = "xuat3";
    else if(this->getGio() == "5:00 PM") l = "xuat1";
    else if(this->getGio() == "7:00 PM") l = "xuat2";
    return l;
}


istream& operator>>(istream& i, LichChieu& e){
    system("cls");
    CanLe();
    SetColor(0,3);
    cout << "Nhap Ma Lich Chieu: ";
    fflush(stdin);
     SetColor(0,15);
    getline(i,e.MaLichChieu);
     SetColor(0,15);
    CanLe();
    cout << "Nhap Ten Phim: ";
    fflush(stdin);
     SetColor(0,15);
    getline(i,e.TenPhim);
     SetColor(0,15);
    CanLe();
    cout << "Nhap Que Quan: ";
    fflush(stdin);
     SetColor(0,15);
    getline(i,e.Ngay);
     SetColor(0,15);
    CanLe();
    cout << "Nhap Ngay: ";
    fflush(stdin);
     SetColor(0,15);
    getline(i,e.Gio);
    CanLe();
    cout << "Nhap Gio :";
    fflush(stdin);
     SetColor(0,15);
    getline(i,e.PhongChieu);
    return i;
}

