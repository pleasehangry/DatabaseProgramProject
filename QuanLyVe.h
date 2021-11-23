#include "Ve.h"
#include<string>
#include<iomanip>
#include "QuanLy.h"
#pragma once
class QuanLyVe : public QuanLy<Ve>
{
private:
public:
    void Show();
    int CheckMS(string);
    void Update(string);

    int GetMaVe(string = "Unknown", string = "Member");
    void setLoaiVe();
    friend void DatVe(int);
    friend void UpdateFile_Ve(QuanLyVe&);

    void Menu();
    void ThemVe();
    void CapNhatVe();
    void XoaVe();
    void XemThongTinVe();
};