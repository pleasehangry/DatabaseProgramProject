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



void User(int index);
void ThanhToan(int index, int indexmave, int SoVe);



void thanhcong()
{
	cout << "------------------" << endl;
	SetColor(0, 9);
	cout << " Yeu cau cua ban da duoc thuc hien" << endl;
	intime();
	SetColor(0, 7);
	cout << "------------------" << endl;
}


void InVe(vector<int>A, int indexPhim, int indexPC, int indexLichChieu, int indexMave){
    ofstream inve;
    inve.open("Titket.txt", ios::trunc);
    inve << get_day() << "    " << get_time() << endl;
    inve << QLP[indexPhim].getTenPhim() << endl;
    inve << "Ngay:" << QLLC[indexLichChieu].getNgay() << "   Gio Chieu:" << QLLC[indexLichChieu].getGio()<< "   ";
    inve << QLPC[indexPC].getMaPhongChieu() << endl;
    inve << "Ghe Da Dat: ";
    for (int i = 0; i < A.size(); i++)
    {
        inve << A[i] << " ";
    }
    inve << "     So Tien: " << QLV[indexMave].getGiaLoaiVe()*A.size();
    inve << endl;
    inve << "Cam On Ban Da Su Dung Dich Vu Cua Chung Toi!";
    inve.close();
}


void DatVe(int index){
    string maPhim,maXuatChieu;
    // DocFile(QLNV, QLP, QLLC, QLPC, QLV, CTM, SoKhach);
    int SoVe;
    cout << "Nhap Ma Phim Ban Muon Dat Ve: ";
    cin >> maPhim;
    int indexMaphim = QLP.checkMSFilm(maPhim);
    while(indexMaphim<0){
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
    string a = QLLC[k].getPhongChieu();
    int h = QLPC.checkMSPC(a);
    system("cls");
    cout << "Ban Muon Dat Bao Nhieu Ve? ";
    cin >> SoVe;
    int indexmave = QLV.GetMaVe(maPhim);
    QLV[indexmave].ThemSoVeDaBan(SoVe);
    UpdateFile_Ve(QLV);
    QLPC[h].DisplayTable();
    vector<int> A;
    int ghe;
    for(int i = 0; i < SoVe; i++){
        cout << "Nhap Ghe Ma Ban Muon Dat: ";
        cin >> ghe;
        A.push_back(ghe);
        QLPC[h].GhiFileDatGhe(ghe);
    }
    // QLPC[h].DatGhe(SoVe);
    
    ThanhToan(index, indexmave, SoVe);
    system("cls");
    cout << "Ban Co Muon In Ve Khong?" << endl;
    cout << "1.Co" << endl;
    cout << "2.Khong" << endl;
    int In;
    cin >> In;
    switch (In)
    {
    case 1:
        InVe(A,indexMaphim,h,k,indexmave);
        thanhcong();
        cout << "Hay Kiem Tra Ve Cua Ban O File Titket.txt" << endl;
        break;
    case 2:
        cout << "Cam On Ban Da Gop Phan Bao Ve Moi Truong <3" << endl;
    default:
        break;
    }
    cout << "\nDat Ve Hoan Tat!!" << endl;
    int chon2;
    cout << "1.Dat Them Ve" << endl;
    cout << "2.Tro Ve Man Hinh Chon" << endl;
    cout<<"Ket thuc."<<endl;
    cin >> chon2;
    switch (chon2)
    {
    case 1:
        QLP.Show();
        DatVe(index);
        break;
    case 2:
        User(index);
    default:
        break;
    }
}

void ThanhToan(int index, int indexmave, int SoVe){
    DocFile_Khach(CTM,SoKhach);
    cout << "Ban Muon Thanh Toang Bang Gi: " << endl;
    cout << "1. Thanh Toan Bang The" << endl;
    cout << "2. Thanh Toan Bang Tien Mat" << endl;
    int thanhtoan;
    cin >> thanhtoan;
    switch (thanhtoan)
    {
    case 1:
        if(CTM[index].CheckSoDu(QLV[indexmave].getGiaLoaiVe()*SoVe)){
            cout << "Thanh Toan Thanh Cong!" << endl;
            UpdateFile_Khach(CTM,SoKhach);
        }
        else{
            cout << "So Du Cua Ban Khong Du!" << endl;
            int thanhtoan2;
            cout << "1. Nap Tien" << endl;
            cout << "2. Thanh Toan Bang Tien Mat" << endl;
            cout << "Nhap Lua Chon Cua Ban: "; cin >> thanhtoan2;
            switch (thanhtoan2)
            {
            case 1:
                CTM[index].NapTien();
                if(CTM[index].CheckSoDu(QLV[indexmave].getGiaLoaiVe()*SoVe)){
                    cout << "Thanh Toan Thanh Cong!" << endl;
                    UpdateFile_Khach(CTM,SoKhach);
                }
                break;
            case 2:
                cout << "Da Thanh Toan Bang Tien Mat!" << endl;
                break;
            default:
                break;
            }
        }
        break;
    case 2:
        Sleep(3000);    
        cout << "Da Thanh Toan Bang Tien Mat!" << endl;
        break;
    default:
        break;
    }
    cout << "Nhan Phim Ban Ki De Tiep Tuc" << endl;
    getch();
}


int TimTaiKhoan(string tk, string mk){
    DocFile_Khach(CTM,SoKhach);
    int index = -1;
    for (int i = 0; i < CTM.size(); i++)
    {
        if(CTM[i].checkTaiKhoan(tk,mk)){
            index = i;
            break;
        }
    }
    return index;
}




void us1()
{
    
}


void User(int index)
{
    DocFile(QLNV, QLP, QLLC, QLPC, QLV, CTM, SoKhach);
    system("cls");
    SetColor(0,2);
    cout<<"Dang Nhap Thanh Cong!"<<endl;
    SetColor(0,7);
    cout<<"Xin Chao ";
    SetColor(0,9);
    cout << CTM[index].HoTen;
    SetColor(0,7);
    menu();
    int ma;
    cout<<"Nhap Lua Chon Cua Ban:"<<endl;
    cout<<" "<<(char)16<<(char)16;
    cin>>ma;
    switch(ma)
    {   int lenh;
        case 1:
         QLP.Show();
         cout<<"\n1.Dat Ve"<<endl;
         cout<<"2.Tro Ve"<<endl;
         SetColor(0,7);
         cout<<(char)16<<(char)16;
         cin>>lenh;
         if(lenh==2)
         {
             system("cls");
             User(index);
         }
         if(lenh==1)
         {
             DatVe(index);
         } 
            break;
        case 2:
            QLP.TimKiemPhim();
             cout<<"----------------------";
            SetColor(0,14);
            cout<<"\n1.Tro Ve"<<endl;
            cout<<"2.Dat Ve"<<endl;
            SetColor(0,7);
            cout<<" "<<(char)16<<(char)16;
            cin>>lenh;
            if(lenh==1)
            {
                system("cls");
                User(index);
            }
            else if(lenh == 2){
                DatVe(index);
            }
            break;
        case 3:
            QLP.XemTheloaiPhim();
            QLP.XemDSPhimCuaTheLoai();
            SetColor(0,14);
            cout<<"\n1.Tro Ve"<<endl;
            cout<<"2.Dat Ve"<<endl;
            SetColor(0,7);
            cout<<" "<<(char)16<<(char)16;
            cin>>lenh;
            if(lenh==1)
            {
                system("cls");
                User(index);
            }
            else if(lenh == 2){
                DatVe(index);
            }
            break;
        case 4:
            break;
    
    } 
} 


void DangNhap(){
    string gmail,mk;
    system("cls");
    cout << "Nhap Gmail: " << endl;
    cin >> gmail;
    cout << "Nhap Mat Khau: " << endl;
    cin >> mk;
    int index = TimTaiKhoan(gmail,mk);
    if(index == -1){
        system("cls");
        DangNhap();
        cout << "\nTai Khoan Hoac Mat Khau Khong Dung!";
    }
    else{
        User(index);
    }
}
