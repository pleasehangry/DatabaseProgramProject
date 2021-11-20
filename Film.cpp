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
    cout << setw(24) << left << this->dienVien<< char(179)<<endl;
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

istream& operator>>(istream& i, Film& f){

    string maPhim, tenPhim, theLoai, thoiLuong, daoDien, dienVien, namCongChieu, quocGia;
    cout << "Nhap Ma Phim: ";
    i >> maPhim;
     f.maPhim = maPhim;
    cout << "Nhap Ten Phim: ";
    i >> tenPhim;
     f.tenPhim =  tenPhim;
    cout << "Nhap The Loai: ";
    i >> theLoai;
     f.theLoai = theLoai;
    cout << "Nhap Thoi Luong: ";
    i >> thoiLuong;
     f.thoiLuong = thoiLuong;
    cout << "Nhap Dao Dien: ";
    i >> daoDien;
     f.daoDien = daoDien;
    cout << "Nhap Dien Vien: ";
    i >> dienVien;
     f.dienVien = dienVien;
    cout << "Nhap Nam Cong Chieu: ";
    i >>namCongChieu;
    f.namCongChieu;
    cout << "Nhap Quoc Gia: ";
    i >> quocGia;
     f.quocGia = quocGia;
    return i;
}


