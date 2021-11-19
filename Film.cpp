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
    cout << " " << setw(9) << left << this->maPhim << "| ";
    cout << setw(30-1) << left << this->tenPhim << "| ";
    cout << setw(25-1) << left << this->theLoai << "| ";
    cout << setw(15-1) << left << this->thoiLuong << "| ";
    cout << setw(25-1) << left << this->daoDien << "| ";
    cout << setw(40-1) << left << this->dienVien << endl;
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
    getline(i,e.maPhim);
    cout << "Nhap Ten Phim: ";
    fflush(stdin);
    getline(i,e.tenPhim);
    cout << "Nhap The Loai: ";
    fflush(stdin);
    getline(i,e.theLoai);
    cout << "Nhap Thoi Luong: ";
    fflush(stdin);
    getline(i,e.thoiLuong);
    cout << "Nhap Dao Dien :";
    fflush(stdin);
    getline(i,e.daoDien);
    cout << "Nhap Dien Vien:";
    fflush(stdin);
    getline(i,e.dienVien);
    cout << "Nhap Nam Cong Chieu: ";
    fflush(stdin);
    getline(i,e.namCongChieu);
    cout << "Nhap Quoc Gia :";
    fflush(stdin);
    getline(i,e.quocGia);
    return i;
}
