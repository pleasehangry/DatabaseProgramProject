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
    cout << " " << setw(20-1) << left << this->MaLichChieu << "| ";
    cout << setw(30-1) << left << this->TenPhim << "| ";
    cout << setw(20-1) << left << this->Ngay << "| ";
    cout << setw(20-1) << left << this->Gio << "| ";
    cout << setw(20-1) << left << this->PhongChieu;
}

LichChieu::~LichChieu()
{
}


istream& operator>>(istream& i, LichChieu& e){
    system("cls");
    cout << "Nhap Ma Lich Chieu: ";
    fflush(stdin);
    getline(i,e.MaLichChieu);
    cout << "Nhap Ten Phim: ";
    fflush(stdin);
    getline(i,e.TenPhim);
    cout << "Nhap Que Quan: ";
    fflush(stdin);
    getline(i,e.Ngay);
    cout << "Nhap Ngay: ";
    fflush(stdin);
    getline(i,e.Gio);
    cout << "Nhap Gio :";
    fflush(stdin);
    getline(i,e.PhongChieu);
    return i;
}

