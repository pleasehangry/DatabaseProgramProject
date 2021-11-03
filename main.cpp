#include <iostream>
#include "DocFile.h"
#include <math.h>
#include "QuanLyPhim.h"
#include"QuanLyNhanVien.h"
#include "DoHoa.h"
#include <windows.h>
#include "Time.h"
#include "LoginData.h"
QuanLyNhanVien QLNV;
QuanLyPhim QLP;
vector<Customer> CTM;
using namespace std;
int SoKhach;
// void them(QuanLyPhim& m){
//     Film f1("1", "Ve Binh Giai Ngan Ha", "Sieu Anh Hung", 120, "Quang Hoang", "Quang Hoang", 2017, "Viet Nam");
//     m.Add_Film(f1);
// }

// void ShowMenuKhachHang()
// {
//     Film F;
//     int choose;
//     do
//     {
//      F.ShowMenu();
//      cin>>choose;
//      switch (choose)
//      {
//      case 1:
//          break;
//      case 2:     
//          break;
//      case 3:
//          break;    
//      case 4:
//          break;
//      case 5:
//          break;
//      default:
//          break;
//      }
//     } while (choose!=5);
// }
// int main(){
//     //Đưa ra bảng Đăng Nhập Đăng Kí và lựa chọn khách hay nhân viên quản lí
//     //code
    
//     NhanVien n1( "Nv1", "Quang Hoang", "3-5-2002", "Hue", "0918636253", "192033798", "NhanVienBanVe", "Ban ve");
//     NhanVien n2( "Nv2", "Quang Hoang", "3-5-2002", "Hue", "0918636253", "192033798", "NhanVienBanVe", "Ban ve");
//     NhanVien n3( "Nv3", "Hoang Quang", "3-5-2002", "Hue", "0918636253", "192033798", "NhanVienBanVe", "Ban ve");
//     QuanLyNhanVien M1;
//     M1.Add_NV(n1);
//     M1.Add_NV(n2);
//     M1.Add_NV(n3);
//     M1.Show();
//     // M1.Update_NV("Nv3");
//     // M1.Show();
//     M1.Delete_NV("Nv2");
//     system("pause");


int main(){
    DocFile(QLNV, QLP, CTM, SoKhach);
    QLP.Show();
    // SetConsoleOutputCP(65001);
    // system("cls");
    // Film f1("1", "Ve Binh Giai Ngan Ha", "Sieu Anh Hung", 120, "Quang Hoang", "Quang Hoang", 2017, "Viet Nam");
    // Film f2("2", "Ve Binh Giai Ngan Ha", "Sieu Anh Hung", 120, "Quang Hoang", "Quang Hoang", 2017, "Viet Nam");
    // Film f3("3", "Ve Binh Giai Ngan Ha", "Sieu Anh Hung", 120, "Quang Hoang", "Quang Hoang", 2017, "Viet Nam");
    // QuanLyPhim p;
    // p.Add_Film(f1);
    // p.Add_Film(f2);
    // p.Add_Film(f3);
    // p.Show();
    // p.Update_Film("6");
    // p.Delete_Film("1");
    // p.Show();
    return 0;
}