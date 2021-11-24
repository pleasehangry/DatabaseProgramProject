#include <iostream>
#include "Film.h"
using namespace std;


Film::Film(string maPhim, string tenPhim, string theLoai, string thoiLuong, string daoDien, string dienVien, string namCongChieu, string quocGia)
{
    this->maPhim = maPhim;
    this->tenPhim = tenPhim;
    this->theLoai = theLoai;
    this->thoiLuong = thoiLuong;
    this->daoDien = daoDien;
    this->dienVien = dienVien;
    this->namCongChieu = namCongChieu;
    this->quocGia = quocGia;
}
Film::~Film()
{
}

void Film::setMaPhim(string maPhim)
{
    this->maPhim = maPhim;
}
void Film::setTenPhim(string tenPhim)
{
    this->tenPhim = tenPhim;
}
void Film::setTheLoai(string theLoai)
{
    this->theLoai = theLoai;
}
void Film::setThoiLuong(string thoiLuong)
{
    this->thoiLuong = thoiLuong;
}
void Film::setDaoDien(string daoDien)
{
    this->daoDien = daoDien;
}
void Film::setDienVien(string dienVien)
{
    this->dienVien = dienVien;
}
void Film::setNamCongChieu(string namCongChieu)
{
    this->namCongChieu = namCongChieu;
}
void Film::setQuocGia(string quocGia)
{
    this->quocGia = quocGia;
}

string Film::getMaPhim()
{
    return maPhim;
}
string Film::getTenPhim()
{
    return tenPhim;
}
string Film::getTheLoai()
{
    return theLoai;
}
string Film::getThoiLuong()
{
    return thoiLuong;
}
string Film::getDaoDien()
{
    return daoDien;
}
string Film::getDienVien()
{
    return dienVien;
}
string Film::getQuocGia()
{
    return quocGia;
}
string Film::getNamCongChieu()
{
    return namCongChieu;
}

void Film::Display()
{
    cout << char(179)<< setw(9) << left << this->maPhim <<char(179);
    cout << setw(29) << left << this->tenPhim <<char(179);
    cout << setw(24) << left << this->theLoai << char(179);
    cout << setw(14) << left << this->thoiLuong << char(179);
    cout << setw(24) << left << this->daoDien << char(179);
    cout << setw(39) << left << this->dienVien<< char(179)<<endl;
}


// display2 de xem chi tiet phim
void Film::Display2(){
    cout << "Ma Phim: " << this->maPhim << endl;
    cout << "Ten Phim: " << this->tenPhim << endl;
    cout << "The Loai: " << this->theLoai << endl;
    cout << "Thoi Luong: " <<this->thoiLuong << endl;
    cout << "Dao Dien: " << this->daoDien << endl;
    cout << "Dien Vien: " << this->dienVien << endl;
    cout << "Nam Cong Chieu: " << this->namCongChieu << endl;
    cout << "Quoc Gia: " << this->quocGia << endl;
}

//da nang hoa
ostream& operator<<(ostream& o, const Film& f){
    cout << " " << setw(9) << left << f.maPhim << "| ";
    cout << setw(30-1) << left << f.tenPhim << "| ";
    cout << setw(25-1) << left << f.theLoai << "| ";
    cout << setw(15-1) << left << f.thoiLuong << "| ";
    cout << setw(25-1) << left << f.daoDien << "| ";
    cout << setw(40-1) << left << f.dienVien << endl;
    return o;
}

istream& operator>>(istream& i, Film& e){
    system("cls");
    cout << "Nhap Ma Phim: ";
    fflush(stdin);
    SetColor(0,2);
    getline(i,e.maPhim);
    SetColor(0,9);
    cout << "Nhap Ten Phim: ";
    fflush(stdin);
    SetColor(0,2);
    getline(i,e.tenPhim);
    SetColor(0,9);
    cout << "Nhap The Loai: ";
    fflush(stdin);
    SetColor(0,2);
    getline(i,e.theLoai);
    SetColor(0,9);
    cout << "Nhap Thoi Luong: ";
    fflush(stdin);
    SetColor(0,2);
    getline(i,e.thoiLuong);
    SetColor(0,9);
    cout << "Nhap Dao Dien :";
    fflush(stdin);
    SetColor(0,2);
    getline(i,e.daoDien);
    SetColor(0,9);
    cout << "Nhap Dien Vien:";
    fflush(stdin);
    SetColor(0,2);
    getline(i,e.dienVien);
    SetColor(0,9);
    cout << "Nhap Nam Cong Chieu: ";
    fflush(stdin);
    SetColor(0,2);
    getline(i,e.namCongChieu);
    SetColor(0,9);
    cout << "Nhap Quoc Gia :";
    fflush(stdin);
    SetColor(0,2);
    getline(i,e.quocGia);
    return i;
}
