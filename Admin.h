#include"DoHoa.h"
#include "Time.h"
#include "DocFile.h"
#pragma once


void Admin(QuanLyPhim& QLP, QuanLyNhanVien& QLNV,vector<Customer>& CTM, QLPhongChieu& QLPC, QuanLyLichChieu& QLLC, QuanLyVe& QLV, int& SoKhach);
void DangNhap_Admin(QuanLyPhim& QLP, QuanLyNhanVien& QLNV,vector<Customer>& CTM, QLPhongChieu& QLPC, QuanLyLichChieu& QLLC, QuanLyVe& QLV, int& SoKhach);
void Admin_Phim(QuanLyPhim& QLP);
void Admin_PhongChieu(QLPhongChieu& QLPC);
void Admin_LichChieu(QuanLyLichChieu& QLLC);
void Admin_Ve(QuanLyVe& QLV);
void Admin_Khach(vector<Customer>& CTM, int& SoKhach);