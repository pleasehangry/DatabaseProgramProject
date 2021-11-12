#include<iostream>

using namespace std;

class Ve
{
private:
    string MaVe;
    string TenLoaiVe;
    string LoaiPhim;
    string LoaiKhachHang;
    int GiaLoaiVe;
public:
    Ve(string, string, string, string, int);
    Ve();
    ~Ve();
    string GetMaVe();
    void Display();
};
