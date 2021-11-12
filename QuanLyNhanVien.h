#include"NhanVien.h"
#pragma once
class QuanLyNhanVien
{
private:
    NhanVien *p;
    static int ind;
    int n;
public:
    QuanLyNhanVien();
    ~QuanLyNhanVien();
    void Show();
    void Add_NV(NhanVien);
    int checkMSNV(string);
    int IndexOf(string);
    void Update_NV(string);
    void Delete_NV(string);
    friend void UpdateFile_NV(QuanLyNhanVien&);
};