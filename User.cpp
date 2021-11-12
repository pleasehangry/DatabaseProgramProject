#include"DoHoa.h"
#include"Film.h"
#include "Time.h"
#include "DocFile.h"


QuanLyPhim QLP;
QuanLyNhanVien QLNV;
vector<Customer> CTM;
QLPhongChieu QLPC;
QuanLyLichChieu QLLC;
QuanLyVe QLV;

int SoKhach;


void DatVe(){
    string maPhim,maXuatChieu;
    int SoVe;
    DocFile(QLNV, QLP, QLLC, QLPC, QLV, CTM, SoKhach);
    cout << "Nhap Ma Phim Ban Muon Dat Ve: ";
    cin >> maPhim;

    while(QLP.checkMSFilm(maPhim)<0){
        cout << "Khong Co Ma Phim Nao Trung Khop, Xin Nhap Lai: ";
        cin >> maPhim;
    }
    system("cls");
    QLLC.Show();
    cout << "Nhap Ma Xuat Chieu: ";
    cin >> maXuatChieu;
    while(QLLC.checkMaLichChieu(maXuatChieu) < 0){
        cout << "Khong Co Ma Xuat Chieu Nao Trung Khop, Xin Nhap Lai: ";
        cin >> maXuatChieu;
    }
    int k = QLLC.checkMaLichChieu(maXuatChieu);
    string a = (QLLC.p + k)->getPhongChieu();
    int h = QLPC.checkMSPC(a);
    system("cls");
    cout << "Ban Muon Dat Bao Nhieu Ve? ";
    cin >> SoVe;
    (QLV.p + QLV.GetMaVe(maPhim))->ThemSoVeDaBan(SoVe);
    (QLPC.p + h)->DisplayTable();
    cout << "Nhap Ghe Ma Ban Muon Dat: ";
    for(int i = 0; i < SoVe; i++)
    {
        string maGhe;
        cin >> maGhe;
    }
    cout << "Xong. Ban Hay Kiem Tra Gmail De Co Them Thong Tin Chi Tiet" << endl;

}


void us1()
{
    
}

void thanhcong()
{
	cout << "------------------" << endl;
	SetColor(0, 9);
	cout << " Yeu cau cua ban da duoc thuc hien" << endl;
	intime();
	SetColor(0, 7);
	cout << "------------------" << endl;
}

// void Person()
// {
//     system("cls");
//     SetColor(0,2);
//     cout<<"Đăng Nhập thành công!"<<endl;
//     SetColor(0,7);
//     cout<<"Xin chào";
//     SetColor(0,9);
//     //in họ tên
//     SetColor(0,14);
//     cout<<"\n1.Xem Hom nay co phim gi:"<<endl;
//     cout<<"\n2.Tim kiem Phim theo the loai:"<<endl;
//     cout<<"\n3.Search Phim"<<endl;
//     cout<<"\n4.Doi mat khau"<<endl;
//     SetColor(0,7);
//     int ma;
//     cout<<"Nhập lựa chọn của bạn:"<<endl;
//     cout<<" "<<(char)16<<(char)16;
//     cin>>ma;
//     switch(ma)
//     {
//         case 1:
//          int lenh;
//         //  Film F;
//         // F.Phim();
//          cout<<"\n1.Đặt vé"<<endl;
//          cout<<"2.Trở vể màn hình chọn"<<endl;
//          SetColor(0,7);
//          cout<<(char)16<<(char)16;
//          cin>>lenh;
//          if(lenh==2)
//          {
//              system("cls");
//              //chua co tham so
//              Person();
//          }
//          if(lenh==1)
//          {
//              DatVe();
//              int lenh2;
//              cout<<"----------------------";
//             SetColor(0,14);
//             cout<<"1.Trở về màn hình chọn"<<endl;
//             cout<<"2.kết thúc"<<endl;
//             SetColor(0,7);
//             cout<<" "<<(char)16<<(char)16;
//             cin>>lenh;
//             if(lenh==1)
//             {
//                 system("cls");
//                 Person();
//             }
//          } 
//             break;
//         case 2:
//         // Film F1;
//         // F1.TimkiemPhim();
//         int lenh;
//              cout<<"----------------------";
//             SetColor(0,14);
//             cout<<"1.Trở về màn hình chọn"<<endl;
//             cout<<"2.kết thúc"<<endl;
//             SetColor(0,7);
//             cout<<" "<<(char)16<<(char)16;
//             cin>>lenh;
//             if(lenh==1)
//             {
//                 system("cls");
//                 Person();
//             }
//             break;
//         case 3:
//             break;
//         case 4:
//             break;
    
//     } 
// } 

