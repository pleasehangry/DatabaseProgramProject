#include<iostream>
#include "Time.h"
#include "DoHoa.h"
#pragma once

using namespace std;

class LichChieu
{
private:
    string MaLichChieu;
    string TenPhim;
    string Ngay;
    string Gio;
    string PhongChieu;

public:
    LichChieu(string = "Unknown", string = "Unknown", string = "Unknown", string = "Unknown", string = "Unknown");
    ~LichChieu();

    void setMaLichChieu(string);
    void setTenPhim(string);
    void setNgay(string);
    void setGio(string);
    void setPhongChieu(string);

    string getMaLichChieu();
    string getTenPhim();
    string getNgay();
    string getGio();
    string getPhongChieu();

    void Display();
};

