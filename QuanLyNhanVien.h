#include"NhanVien.h"
#include"DoHoa.h"
#pragma once
#include "QuanLy.h"
#include "DoHoa.h"
class QuanLyNhanVien : public QuanLy<NhanVien>
{
private:

public:
    void TieuDeCot();
    void Show();
    int CheckMS(string);
    void Update(string);
    friend void UpdateFile_NV(QuanLyNhanVien&);
    
    //Ham Cho Menu:
    int TimTaiKhoan(string, string);
    void Menu();
    void ThemNhanVien();
    void CapNhatNhanVien();
    void XoaNhanVien();
    void XemThongTinNhanVien();

};