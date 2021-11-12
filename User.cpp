class QuanLyPhim;
#include "User.h"
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
            V.Datve();
             cout<<"----------------------";
            SetColor(0,14);
            cout<<"1.Tro ve man hinh chon"<<endl;
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
            V.Datve();
             cout<<"----------------------";
            SetColor(0,14);
            cout<<"1.Tro ve man hinh chon"<<endl;
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
        //chua lam truong hop neu k tim thay phim
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
            V.Datve();
             cout<<"----------------------"<<endl;
            SetColor(0,14);
            cout<<"1.Tro ve man hinh chon"<<endl;
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

