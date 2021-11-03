#include "Ve.h"

Ve::Ve(){}

Ve::Ve(string MaVe, string TenLoaiVe, string LoaiPhim, string LoaiKhachHang, int GiaLoaiVe){
    this->MaVe = MaVe;
    this->TenLoaiVe = TenLoaiVe;
    this->LoaiPhim = LoaiPhim;
    this->LoaiKhachHang = LoaiKhachHang;
    this->GiaLoaiVe = GiaLoaiVe;
}

Ve::~Ve(){}

void Ve::Display(){
    cout << "Ma Ve: " << this->MaVe  << endl;
    cout << "Ten Loai Ve: " << this->TenLoaiVe << endl;
    cout << "Loai Phim: " << this->LoaiPhim << endl;
    cout << "Loai Khach Hang: " << this->LoaiKhachHang << endl;
    cout << "Gia Ve: " << this->GiaLoaiVe << endl;
}