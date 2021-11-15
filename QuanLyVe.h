#include "Ve.h"
#include<string>
#include<iomanip>
#pragma once
class QuanLyVe
{
private:
    Ve *p;
    int n;
public:
    QuanLyVe(/* args */);
    ~QuanLyVe();
    void Show();
    void Add_Ve(Ve);
    int checkMaVe(string);
    void Update_Ve(string);
    void Delete_Ve(string);
    void setLoaiVe();
    int GetMaVe(string = "Unknown", string = "Member");
    friend void DatVe(int);
    friend void UpdateFile_Ve(QuanLyVe&);
    // da nang hoa
    Ve& operator[](const int&);
};