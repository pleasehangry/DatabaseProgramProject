#include "Admin.h"


void DangNhap_Admin( QuanLyPhim& QLP, QuanLyNhanVien& QLNV,vector<Customer>& CTM, QLPhongChieu& QLPC, QuanLyLichChieu& QLLC, QuanLyVe& QLV, int& SoKhach){
    system("cls");
    string taikhoan,mk;
    system("cls");
    CanLe();
    cout << "Nhap Tai Khoan: " << endl;
    CanLe();
    cin >> taikhoan;
    CanLe();
    cout << "Nhap Mat Khau: " << endl;
    CanLe();
    cin >> mk;
    int index = QLNV.TimTaiKhoan(taikhoan,mk);
    if(taikhoan == "0"){
        DangNhap_Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
    }
    if(index == -1){
        system("cls");
        DangNhap_Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        SetColor(0,4);
        cout << "\nTai Khoan Hoac Mat Khau Khong Dung!";
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
        Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        break;
    case 2:
        QLLC.Menu();
        Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        break;
    case 3:
        QLV.Menu();
        Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        break;
    case 4:
        QLNV.Menu();
        Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        break;
    case 5:
        Menu_Khach(CTM, SoKhach);
        Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        break;
    case 6:
        QLPC.Menu();
        Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
        break;
    default:
        break;
    }
}

void Admin_Phim(QuanLyPhim& QLP){
    QLP.Menu();
}
void Admin_PhongChieu(QLPhongChieu& QLPC){
    QLPC.Menu();
}
void Admin_LichChieu(QuanLyLichChieu& QLLC){
    QLLC.Menu();
}
void Admin_Ve(QuanLyVe& QLV){
    QLV.Menu();
}
void Admin_Khach(vector<Customer>& CTM, int& SoKhach){
    Menu_Khach(CTM, SoKhach);
}