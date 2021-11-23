#include "QuanLyPhim.h"


void QuanLyPhim::TieuDeCot(){
    GoTo(5, 3);
    cout << setw(10) << left << " Ma Phim" << "|";
    cout << setw(30) << left << " Ten Phim:" << "|";
    cout << setw(25) << left << " The loai:" << "|";
    cout << setw(15) << left << " Thoi Luong:" << "|";
    cout << setw(25) << left << " Dao Dien:" << "|";
    cout << setw(25) << left << " Dien Vien:" << endl;
    
    // box(0,3,10,2,7,8,"Ma Phim");
    // box(10,3,30,2,7,8,"Ten Phim");
    // box(40,3,25,2,7,8,"The loai");
    // box(65,3,15,2,7,8,"Thoi Luong");
    // box(80,3,25,2,7,8,"Dao Dien");
    // box(105,3,25,2,7,8,"Dien Vien");
   
    // GoTo(10,3);cout<<char(194);
    // GoTo(10,5);cout<<char(193);
    // GoTo(40,3);cout<<char(194);
    // GoTo(40,5);cout<<char(193);
    // GoTo(65,3);cout<<char(194);
    // GoTo(65,5);cout<<char(193);
    // GoTo(80,3);cout<<char(194);
    // GoTo(80,5);cout<<char(193);
    // GoTo(105,3);cout<<char(194);
    // GoTo(105,5);cout<<char(193);
    cout<<endl;
}

void QuanLyPhim::Show()
{
    TieuDeCot();
    for (int i = 0; i < this->n; i++)
    {
        CanLe();
        (p + i)->Display();
    }
    cout << endl;
}

int QuanLyPhim::CheckMS(string s)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if (s == (this->p + i)->getMaPhim())
        {
            index = i;
            break;
        }
    }
    return index;
}

string QuanLyPhim::getFimlName(int i){
    return (this->p + i)->getTenPhim();
}


void QuanLyPhim::Update(string m)
{
    int i = CheckMS(m);
    if(i >= 0){
        if (m == (this->p + i)->getMaPhim())
        {
            string a,b,c,d,e,f;
            string g, h;
            system("cls");
            (this->p + i)->Display2();
            cout << "Nhap Ma Phim Moi: ";
            fflush(stdin);
            getline(cin, a);
            cout << "\nNhap Ten Phim Moi: ";
            fflush(stdin);
            getline(cin, b);
            cout << "\nNhap The Loai: ";
            fflush(stdin);
            getline(cin, c);
            cout << "\nNhap Thoi Luong: ";
            fflush(stdin);
            getline(cin, c);
            cout << "\nNhap Dao Dien: ";
            fflush(stdin);
            getline(cin, d);
            cout << "\nNhap Dien Vien: ";
            fflush(stdin);
            getline(cin, e);
            cout << "\nNhap Nam Cong Chieu: ";
            fflush(stdin);
            getline(cin, h);
            cout << "Nhap Quoc Gia: ";
            fflush(stdin);
            getline(cin, f);
            (this->p + i)->setMaPhim(a);
            (this->p + i)->setTenPhim(b);
            (this->p + i)->setTheLoai(c);
            (this->p + i)->setDaoDien(d);
            (this->p + i)->setDienVien(e);
            (this->p + i)->setQuocGia(f);
            (this->p + i)->setThoiLuong(g);
            (this->p + i)->setNamCongChieu(h);
        }
    }
    else cout << "Khong Tim Thay Ma Phim Can Sua!";
    cout << endl;
}

void QuanLyPhim::XemTheloaiPhim(){
    system("cls");
    cout << endl;
    SetColor(0,9);
    CanLe();
    cout << (this->p)->getTheLoai() << endl;
    for (int i = 1; i < this->n; i++)
    {
        if((this->p+i)->getTheLoai()!=(this->p+i-1)->getTheLoai()){
            CanLe();
            cout << (this->p+i)->getTheLoai() << endl;
        }
    }
    SetColor(0,15);
}

void QuanLyPhim::XemDSPhimCuaTheLoai(){
    string m;
    CanLe();
    cout<<"Nhap the loai phim: ";
    fflush(stdin);
    getline(cin,m);
    int count = 0;
    cout << endl;
    for(int i = 0; i < this->n; i++){
        if((this->p+i)->getTheLoai() == m){
           count++;
        }
    }
    if(count == 0) {
        CanLe();
        cout << "Khong Co Phim Nao Thuoc The Loai Nay";
        vector<string> a = {"Nhap Lai", "Tro Ve"};
        int chon = menu2(a);
        switch (chon)
        {
        case 1:
            this->XemDSPhimCuaTheLoai();
            break;
        default:
            break;
        }
    }
    else{
        system("cls");
        GoTo(5,3);
        cout << " Nhung Phim The Loai " << m;
        GoTo(5,5);
        TieuDeCot();   
        for (int i = 0; i < this->n; i++)
        {
            if((this->p+i)->getTheLoai() == m){
                CanLe();
                (this->p + i)->Display();
            }
        }
    }
}

void QuanLyPhim::TimKiemPhim(){
    system("cls");
    GoTo(5,3);
    cout << "Nhap Ten Phim Ban Muon Tim: ";
    string m;
    fflush(stdin);
    getline(cin,m);
    int k = 0;
    cout << endl;
    for (int i = 0; i < this->n; i++)
    {
        if(strstr((this->p+i)->getTenPhim().c_str(),m.c_str())){ // chuoi m la con cua chuoi ten phim
            k++;
        }
    }
    if(k==0){
        GoTo(5,5);
        cout << "Khong Tim Thay" << endl;
        getchar();
    }
    else{
        system("cls");
        GoTo(5,3);
        TieuDeCot();
        for (int i = 0; i < this->n; i++)
        {
            if(strstr((this->p+i)->getTenPhim().c_str(),m.c_str())){
                CanLe();
                (this->p + i)->Display();
            }
        }
    }
}



// Menu

void QuanLyPhim::Menu(){
    system("cls");

    cout << endl;
    cout << "1.Xem Danh Sach Phim" << endl;
    cout << "2.Them Phim" << endl;
    cout << "3.Xoa Phim" << endl;
    cout << "4.Cap Nhat Phim" << endl;
    int chon;
    cout << "Nhap Lua Chon: ";
    cin >> chon;
    switch (chon)
    {
    case 1:
        system("cls");
        this->Show();
        int chon2;
        cout << "Xem Thong Tin Chi Tiet" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">>"; cin >> chon2;
            switch (chon2)
            {
            case 1:
                XemThongTinPhim();
                break;
            case 2:
                this->Menu();
            default:
                break;
            }
        break;
    case 2:
        this->ThemPhim();
        break;
    case 3:
        this->XoaPhim();
        break;
    case 4:
        this->CapNhatPhim();
        break;
    default:
        break;
    }
}

void QuanLyPhim::ThemPhim(){
    system("cls");
    this->Show();
    cout << "Them Mot Phim: " << endl;
    Film temp;
    cin >> temp;
    this->Add(temp);    
    cout << "Them Thanh Cong" << endl;
    int chon;
    cout << "1.Them Phim" << endl;
    cout << "2.Tro Ve" << endl;
    cout << "Nhap Lua Chon" << endl;
    cin >> chon;
    switch (chon)
    {
    case 1:
        ThemPhim();
        break;
    case 2:
        this->Menu();
        break;
    default:
        this->Menu();
        break;
    }
}

void QuanLyPhim::CapNhatPhim(){
    system("cls");
    this->Show();
    string ma;
    cout << "Nhap Ma Phim Ban Muon Cap Nhat: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        cout << "Khong Co Ma Phim Nao Trung Khop" << endl;
        int chon2;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon2;
        if(chon2 == 1){
            this->CapNhatPhim();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Update(ma);
        cout << "Cap Nhat Phim Thanh Cong!!\n" << endl;
        int chon3;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon3;
        if(chon3 == 1){
            this->CapNhatPhim();
        }
        else{
            this->Menu();
        }
    }
}


void QuanLyPhim::XoaPhim(){
    system("cls");
    this->Show();
    string ma;
    cout << "Nhap Ma Phim Ban Muon Xoa: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        cout << "Khong Co Ma Phim Nao Trung Khop" << endl;
        int chon2;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon2;
        if(chon2 == 1){
            this->XoaPhim();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Delete(ma);
        cout << "Xoa Phim Thanh Cong!!\n" << endl;
        int chon3;
        cout << "1.Xoa Phim" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon3;
        if(chon3 == 1){
            this->XoaPhim();
        }
        else{
            this->Menu();
        }
    }
}
void QuanLyPhim::XemThongTinPhim(){
    system("cls");
    this->Show();
    string ma;
    cout << "Nhap Ma Phim Ban Muon Xem: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        cout << "Khong Co Ma Phim Nao Trung Khop" << endl;
        int chon2;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon2;
        if(chon2 == 1){
            this->XemThongTinPhim();
        }
        else if(chon2 == 2){
            this->Menu();
        }
    }
    else {
        (this->p + index)->Display2();
        int chon3;
        cout << "1.Xem Thong Tin Phim" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon3;
        if(chon3 == 1){
            this->XemThongTinPhim();
        }
        else if(chon3 == 2){
            this->Menu();
        }
    }
}


