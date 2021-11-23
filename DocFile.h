#include<iostream>
#include<fstream>
#include <stdlib.h>
#include "QLPhongChieu.h"
#include "QuanLyPhim.h"
#include "QuanLyNhanVien.h"
#include "QuanLyVe.h"
#include "LoginData.h"
#include <string>
#include <vector>
#include <algorithm>
#include "QuanLyLichChieu.h"
#pragma once
using namespace std;

void DocFile(QuanLyNhanVien&,QuanLyPhim&,QuanLyLichChieu&, QLPhongChieu&, QuanLyVe& ,vector<Customer>&, int&);
void DocFile_Khach(vector<Customer>&, int&);
void DocFile_Phim(QuanLyPhim&);
void DocFile_PC(QLPhongChieu&);
void DocFile_NV(QuanLyNhanVien&);
void DocFile_LichChieu(QuanLyLichChieu&);
void DocFile_Ve(QuanLyVe&);

void UpdateFile_Phim(QuanLyPhim&);
void UpdateFile_NV(QuanLyNhanVien&);
void UpdateFile_PC(QLPhongChieu&);
void UpdateFile_Khach(vector<Customer>&, int&);
void UpdateFile_LichChieu(QuanLyLichChieu&);
void Update(QuanLyNhanVien&,QuanLyPhim&,QuanLyLichChieu&,QLPhongChieu&,QuanLyVe& ,vector<Customer>&, int&);