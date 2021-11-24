#include "Ve.h"

Ve::Ve(string MaVe, string MaPhim, string LoaiKhachHang, int GiaLoaiVe, int SoLuong, int SoVeDaBan){
    this->MaVe = MaVe;
    this->MaPhim = MaPhim;
    this->LoaiKhachHang = LoaiKhachHang;
    this->GiaLoaiVe = GiaLoaiVe;
    this->SoLuong = SoLuong;
    this->SoVeDaBan = SoVeDaBan;
}

Ve::~Ve(){}
string Ve::GetMaVe()
{
    return this->MaVe;
}

void Ve::setMaVe(string MaVe){
    this->MaVe = MaVe;
}
void Ve::setMaPhim(string MaPhim){
    this->MaPhim = MaPhim;
}
void Ve::setLoaiKhachHang(string LoaiKhachHang){
    this->LoaiKhachHang = LoaiKhachHang;
}
void Ve::setGiaLoaiVe(int GiaLoaiVe){
    this->GiaLoaiVe = GiaLoaiVe;
}
void Ve::setSoLuong(int SoLuong){
    this->SoLuong = SoLuong;
}
void Ve::setSoVeDaBan(int SoVeDaBan){
    this->SoVeDaBan = SoVeDaBan;
}

void Ve::ThemSoVeDaBan(int x){
    this->SoVeDaBan +=x;
}

string Ve::getMaVe(){
    return this->MaVe;
}
string Ve::getMaPhim(){
    return this->MaPhim;
}
string Ve::getLoaiKhachHang(){
    return this->LoaiKhachHang;
}
int Ve::getGiaLoaiVe(){
    return this->GiaLoaiVe;
}
int Ve::getSoLuong(){
    return this->SoLuong;
}
int Ve::getSoVeDaBan(){
    return this->SoVeDaBan;
}

int Ve::ThanhTien(){
    return this->SoVeDaBan * this->GiaLoaiVe;
}


void Ve::Display(){
    cout<<char(179)<< setw(15-1) << left << this->MaVe <<char(179);
    cout << setw(15-1) << left << this->MaPhim << char(179);
    cout << setw(20-1) << left << this->LoaiKhachHang << char(179);
    cout << setw(15-1) << left << this->GiaLoaiVe <<char(179);
    cout << setw(15-1) << left << this->SoLuong << char(179);
    cout << setw(15-1) << left << this->SoVeDaBan << char(179);
    cout << setw(15-1) << left << this->ThanhTien() << char(179)<<  endl;
}
