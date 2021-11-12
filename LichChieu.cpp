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