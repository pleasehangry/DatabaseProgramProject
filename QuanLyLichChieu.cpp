#include "QuanLyLichChieu.h"
#include "DocFile.h"


void QuanLyLichChieu::TieuDeCot(){
    int t_color=1;
    int b_color=0;
    int x=whereX();
    int y=whereY();
  	cout<<endl;
    CanLe();
    cout << setw(20) << left << " Ma Lich Chieu" <<char(179);
    cout << setw(30-1) << left << " Ten LichChieu:" <<char(179);
    cout << setw(20-1) << left << " Ngay:" <<char(179);
    cout << setw(20-1) << left << " Gio:" <<char(179);
    cout << setw(20-1) << left << " Phong Chieu:" ;
    int x1=whereX();
    box(x,y,x1-5,2,t_color,b_color);
    cout<<endl; 
}

void QuanLyLichChieu::Show()
{   system("cls");
    GoTo(5,3);
    TieuDeCot();
    CanLe();
    int x1=whereX();
    int y1=whereY();
    cout<<endl;
    for (int i = 0; i < this->n; i++)
    {
        CanLe();
        (p + i)->Display();
    } 
    int y=whereY();
    box(x1,y1,110,y-5,1,0);
    GoTo(x1,y+1); 
}

int QuanLyLichChieu::CheckMS(string s)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if (s == (this->p + i)->getMaLichChieu())
        {
            index = i;
            break;
        }
    }
    return index;
}

void QuanLyLichChieu::Update(string m)
{
    int i = CheckMS("m");
    if(i >= 0){
        if (m == (this->p + i)->getMaLichChieu())
        {
            string a,b,c,d,e;
            system("cls");
            (this->p + i)->Display();
            SetColor(0,3);
            cout << "Nhap Ma Lich Chieu Moi: ";
            fflush(stdin);
            SetColor(0,15);
            getline(cin, a);
            SetColor(0,3);
            cout << "\nNhap Ten LichChieu Moi: ";
            fflush(stdin);
            SetColor(0,15);
            getline(cin, b);
            SetColor(0,3);
            cout << "\nNhap Ngay: ";
            fflush(stdin);
            SetColor(0,15);
            getline(cin, c);
            SetColor(0,3);
            cout << "\nNhap Gio: ";
            fflush(stdin);
            SetColor(0,15);
            getline(cin, d);
            SetColor(0,3);
            cout << "\nNhap Phong Chieu: ";
            fflush(stdin);
            SetColor(0,15);
            getline(cin, e);
            (this->p + i)->setMaLichChieu(a);
            (this->p + i)->setTenPhim(b);
            (this->p + i)->setNgay(c);
            (this->p + i)->setGio(d);
            (this->p + i)->setPhongChieu(e);
        }
    }
    else 
    SetColor(0,4);
    cout << "Khong Tim Thay Ma Lich Chieu Can Sua!";
    cout << endl;
}


void QuanLyLichChieu::setLichChieu(){
    QuanLyPhim QLP;
    QLPhongChieu QLPC;
    DocFile_Phim(QLP);
    DocFile_PC(QLPC);
    LichChieu temp;
    string ngay, gio, phongchieu,MsPhim, maLichChieu;
    SetColor(0,3);
    cout << "Nhap Ma Lich Chieu:";
    cin >> maLichChieu;
    temp.setMaLichChieu(maLichChieu);
    system("cls");
    QLP.Show();
    cout << "Nhap Ma So Phim Ban Muon Len Lich: "; cin >> MsPhim;
    int k = QLP.CheckMS(MsPhim);
    temp.setTenPhim(QLP.getFimlName(k));
    CanLe();
    cout << "Nhap Ngay: "; cin >> ngay;
    temp.setNgay(ngay);
    CanLe();
    cout << "Nhap Gio: "; cin >> gio;
    temp.setGio(gio);
    system("cls");
    QLPC.Show();
    SetColor(0,3);
    cout << "Nhap Ma Phong Chieu De Chon Phong Chieu: ";
    SetColor(0,15);
    cin >> phongchieu;
    int h = QLPC.CheckMS(phongchieu);
    if(h < 0){
        do{
            SetColor(0,4);
            cout << "Da Nhap Sai Ma Phong, Vui Long Nhap Lai: ";
            cin >> phongchieu;
            h = QLPC.CheckMS(phongchieu);
        }
        while(h > 0);
    } else{
        temp.setPhongChieu(phongchieu);
        SetColor(0,14);
        CanLe();
        cout << "Len Lich Thanh Cong";
        cout << endl;
    }
    this->Add(temp);
}

void QuanLyLichChieu::XemLichChieuCuaPhim(string m){
    TieuDeCot();
    for (int i = 0; i < this->n; i++)
    {
        if((this->p + i)->getTenPhim() == m){
            CanLe();
            (this->p + i)->Display();
        }
    }
    
}


// Menu

void QuanLyLichChieu::Menu(){
    system("cls");
    vector<string> m={
     "1.Xem Danh Sach Lich Chieu",
     "2.Them Lich Chieu",
     "3.Xoa Lich Chieu",
     "4.Cap Nhat Lich Chieu",
     "5.Tro Ve Man Hinh Chinh"};
     vector<string> m2={"Tro Ve"};
   int chon =menu(m);
    switch (chon)
    {
    case 1:
        system("cls");
        this->Show();
        int lenh;
        lenh=menu2(m2);
        switch (lenh)
        {
        case 1:
            system("cls");
            this->Menu();
        default:
            system("cls");
            break;
        }
        break;
    case 2:
        this->setLichChieu();
        break;
    case 3:
        this->XoaLichChieu();
        break;
    case 4:
        this->CapNhatLichChieu();
        break;
    default:
    system("cls");
        break;
    }
}

void QuanLyLichChieu::CapNhatLichChieu(){
    system("cls");
    this->Show();
    string ma;
    SetColor(0,3);
    cout << "Nhap Ma Lich Chieu Ban Muon Cap Nhat: ";
    SetColor(0,15);
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        SetColor(0,4);
        cout << "Khong Co Ma Lich Chieu Nao Trung Khop" << endl;
        int chon2;
        SetColor(0,15);
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> ";cin >> chon2;
        
        if(chon2 == 1){
            this->CapNhatLichChieu();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Update(ma);
        SetColor(0,14);
        cout << "Cap Nhat Lich Chieu Thanh Cong!!\n" << endl;
        int chon3;
        SetColor(0,15);
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon3;
        if(chon3 == 1){
            this->CapNhatLichChieu();
        }
        else{
            this->Menu();
        }
    }
}


void QuanLyLichChieu::XoaLichChieu(){
    system("cls");
    this->Show();
    string ma;
    SetColor(0,3);
    cout << "Nhap Ma Lich Chieu Ban Muon Xoa: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        SetColor(0,4);
        cout << "Khong Co Ma Lich Chieu Nao Trung Khop" << endl;
        int chon2;
        SetColor(0,15);
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> ";cin >> chon2;
        
        if(chon2 == 1){
            this->XoaLichChieu();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Delete(ma);
        SetColor(0,14);
        cout << "Xoa Lich Chieu Thanh Cong!!\n" << endl;
        int chon3;
        SetColor(0,15);
        cout << "1.Xoa Lich Chieu" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl; cin >> chon3;
        if(chon3 == 1){
            this->XoaLichChieu();
        }
        else{
            this->Menu();
        }
    }
}