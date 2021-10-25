#include <iostream>
#include "Film.h"
using namespace std;


Film::Film(string maPhim, string tenPhim, string theLoai, int thoiLuong, string daoDien, string dienVien, int namCongChieu, string quocGia)
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
void Film::setThoiLuong(int thoiLuong)
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
void Film::setNamCongChieu(int namCongChieu)
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
int Film::getThoiLuong()
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
void Film::Display()
{
    cout << maPhim;
    cout << setw(25) << tenPhim;
    cout << setw(25) << theLoai;
    cout << setw(25) << thoiLuong;
    cout << setw(25) << daoDien;
    cout << setw(25) << dienVien << endl;
}

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

Film::~Film(){}