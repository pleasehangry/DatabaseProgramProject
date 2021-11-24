#include "Admin.h"


void DangNhap_Admin( QuanLyPhim& QLP, QuanLyNhanVien& QLNV,vector<Customer>& CTM, QLPhongChieu& QLPC, QuanLyLichChieu& QLLC, QuanLyVe& QLV, int& SoKhach){
    system("cls");
    string taikhoan,mk;
    system("cls");
    GoTo(70,5);
    cout << "Nhap Tai Khoan: ";cin >> taikhoan;
    GoTo(70,7);
    cout << "Nhap Mat Khau: "; cin >> mk;    
    int index = QLNV.TimTaiKhoan(taikhoan,mk);
    if(taikhoan == "0"){
        DangNhap_Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
    }
    if(index == -1){
        system("cls");
        DangNhap_Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        SetColor(0,4);
        CanLe();
        cout << "Tai Khoan Hoac Mat Khau Khong Dung!";
        getch();
    }
    else{
        if(QLNV[index].getChucVu() == "Nhan Vien Quan Ly Ve"){
            Admin_Ve(QLV);
        }
        else if(QLNV[index].getChucVu() == "Nhan Vien Quan Ly Phim"){
            Admin_Phim(QLP);
        }
        else if(QLNV[index].getChucVu() == "Nhan Vien Quan Ly Phong Chieu"){
            Admin_PhongChieu(QLPC);
        }
        else if(QLNV[index].getChucVu() == "Nhan Vien Quan Ly Khach"){
            Admin_Khach(CTM,SoKhach);
        }
        else if(QLNV[index].getChucVu() == "Quan Ly Nhan Vien"){
            Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        }
        else{
            SetColor(0,4);
            cout << "Ban Chua Duoc Phan Quyen" << endl;
            DangNhap_Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        }
    }
}

void Admin( QuanLyPhim& QLP, QuanLyNhanVien& QLNV,vector<Customer>& CTM, QLPhongChieu& QLPC, QuanLyLichChieu& QLLC, QuanLyVe& QLV, int& SoKhach){
    DocFile(QLNV, QLP, QLLC, QLPC, QLV, CTM, SoKhach);
    system("cls");
    CanLe(80,whereY()+1);
    cout << "UNG DUNG QUAN LY RAP PHIM\n\n\n";
     vector<string> m={
        "1.Quan Ly Phim" ,
        "2.Quan Ly Lich Chieu" ,
        "3.Quan Ly Ve" ,
        "4.Quan Ly Nhan Vien" ,
        "5.Quan Ly Nguoi Dung" ,
        "6.Quan Ly Phong Chieu" ,
        "7.Thoat"};
    int chon=menu(m);
    switch (chon)
    {
    case 1:
        QLP.Menu();
        UpdateFile_Phim(QLP);
        Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        break;
    case 2:
        QLLC.Menu();
        UpdateFile_LichChieu(QLLC);
        Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        break;
    case 3:
        QLV.Menu();
        UpdateFile_Ve(QLV);
        Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        break;
    case 4:
        QLNV.Menu();
        UpdateFile_NV(QLNV);
        Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        break;
    case 5:
        Menu_Khach(CTM, SoKhach);
        UpdateFile_Khach(CTM,SoKhach);
        Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        break;
    case 6:
        QLPC.Menu();
        UpdateFile_PC(QLPC);
        Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        break;
    default:
        break;
    }
    Update(QLNV, QLP, QLLC, QLPC, QLV, CTM, SoKhach);
}

void Admin_Phim(QuanLyPhim& QLP){
    QLP.Menu();
    UpdateFile_Phim(QLP);
}
void Admin_PhongChieu(QLPhongChieu& QLPC){
    QLPC.Menu();
    UpdateFile_PC(QLPC);
}
void Admin_LichChieu(QuanLyLichChieu& QLLC){
    QLLC.Menu();
    UpdateFile_LichChieu(QLLC);
}
void Admin_Ve(QuanLyVe& QLV){
    QLV.Menu();
    UpdateFile_Ve(QLV);
}
void Admin_Khach(vector<Customer>& CTM, int& SoKhach){
    Menu_Khach(CTM, SoKhach);
    UpdateFile_Khach(CTM,SoKhach);
}