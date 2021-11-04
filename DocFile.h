#include<iostream>
#include<fstream>
#include <stdlib.h>
#include "QLPhongChieu.h"
#include "QuanLyPhim.h"
#include "QuanLyNhanVien.h"
#include "LoginData.h"
#include <string>
#include <vector>
#include <algorithm>
#include "QuanLyLichChieu.h"
#pragma once
using namespace std;

void DocFile(QuanLyNhanVien& QLNV,QuanLyPhim& QLP, QLPhongChieu& QLPC ,vector<Customer>& CTM, int& SoKhach);
void DocFile_Khach(vector<Customer>&, int&);
void DocFile_Phim(QuanLyPhim&);
void DocFile_PC(QLPhongChieu&);
void DocFile_NV(QuanLyNhanVien&);
void DocFile_LichChieu(QuanLyLichChieu&);

void UpdateFile_Phim(QuanLyPhim&);
void UpdateFile_NV(QuanLyNhanVien&);
void UpdateFile_PC(QLPhongChieu&);
void UpdateFile_Khach(vector<Customer>&, int&);
void UpdateFile_LichChieu(QuanLyLichChieu&);