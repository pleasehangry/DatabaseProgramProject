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
    (QLPC.p + h)->DatGhe(SoVe);
    cout << "Xong. Ban Hay Kiem Tra Gmail De Co Them Thong Tin Chi Tiet" << endl;


}
// ủa 
// a viêt them nhieu lam
void thanhcong()
{
	cout << "------------------" << endl;
	SetColor(0, 9);
	cout << " Yeu cau cua ban da duoc thuc hien" << endl;
	intime();
	SetColor(0, 7);
	cout << "------------------" << endl;
}

 void Person()
{
   QuanLyPhim F;
   QuanLyVe V;
   DocFile_Phim(F);
    system("cls");
    SetColor(0,2);
    cout<<"Dang nhap thanh cong!"<<endl;
    SetColor(0,7);
    cout<<"Xin chao"; 
    SetColor(0,9);
    //in tên
    SetColor(0,14);
    cout<<"\n1.Xem Hom nay co phim gi:"<<endl;
    cout<<"\n2.Tim kiem Phim theo the loai:"<<endl;
    cout<<"\n3.Search Phim"<<endl;
    cout<<"\n4.Doi mat khau"<<endl;
    SetColor(0,7);
    int ma;
    cout<<"Nhap lua chon:"<<endl;
    cout<<" "<<(char)16<<(char)16;
    cin>>ma;
    switch(ma)
    {  int lenh;
        case 1:
        F.Show(); 
         SetColor(0,14);        
         cout<<"\n1.Dat ve"<<endl;
         cout<<"2.Tro ve man hinh chon."<<endl;
         SetColor(0,7);
         cout<<(char)16<<(char)16;
         cout<<"Nhap lua chon:";
         cin>>lenh;
         if(lenh==2)
         {
             system("cls");
             Person();
         }
         if(lenh==1)
         {
            DatVe();
             cout<<"----------------------";
            SetColor(0,14);
            cout<<"\n1.Tro ve man hinh chon"<<endl;
            cout<<"2.Ket thuc"<<endl;
            SetColor(0,7);
            cout<<" "<<(char)16<<(char)16;
            cout<<"Nhap lua chon:";
            cin>>lenh;
            if(lenh==1)
            {
                system("cls");
                Person();
            }
         } 
            break;
        case 2:
        F.XemTheloaiPhim();
        F.XemDSPhimCuaTheLoai();
         SetColor(0,14);
         cout<<"\n1.Dat ve"<<endl;
         cout<<"2.Tro ve man hinh chon."<<endl;
         SetColor(0,7);
         cout<<(char)16<<(char)16;
         cout<<"Nhap lua chon:";
         cin>>lenh;
         if(lenh==2)
         {
             system("cls");
             Person();
         }
         if(lenh==1)
         {
            DatVe();
            cout<<"----------------------";
            SetColor(0,14);
            cout<<"\n1.Tro ve man hinh chon"<<endl;
            cout<<"2.Ket thuc"<<endl;
            SetColor(0,7);
            cout<<" "<<(char)16<<(char)16;
            cout<<"Nhap lua chon:";
            cin>>lenh;
            if(lenh==1)
            {
                system("cls");
                Person();
            }
         } 
            break;
        case 3:
        F.TimKiemPhim();
         SetColor(0,14);
         cout<<"\n1.Dat ve"<<endl;
         cout<<"2.Tro ve man hinh chon."<<endl;
         SetColor(0,7);
         cout<<(char)16<<(char)16;
         cout<<"Nhap lua chon:";
         cin>>lenh;
         if(lenh==2)
         {
             system("cls");
             Person();
         }
         if(lenh==1)
         {
            DatVe();
            cout<<"----------------------"<<endl;
            SetColor(0,14);
            cout<<"\n1.Tro ve man hinh chon"<<endl;
            cout<<"2.Ket thuc"<<endl;
            SetColor(0,7);
            cout<<" "<<(char)16<<(char)16;
            cout<<"Nhap lua chon:";
            cin>>lenh;
            if(lenh==1)
            {
                system("cls");
                Person();
            }
         } 
            break;
        case 4:

            break;

    } 
}

