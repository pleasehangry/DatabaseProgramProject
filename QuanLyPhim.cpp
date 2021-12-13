#include "QuanLyPhim.h"
void QuanLyPhim::TieuDeCot(){
    int t_color=1;
    int b_color=0;
    int x=whereX();
    int y=whereY();
  	 cout<<endl;
     CanLe();
     cout << setw(10) << left << " Ma Phim"<<char(179);
     cout << setw(29) << left <<"Ten Phim" <<char(179);
     cout << setw(24) << left << "The loai"<< char(179);
     cout << setw(14) << left << "Thoi luong"<< char(179);
     cout << setw(24) << left <<"Dao dien"<< char(179);
     cout << setw(39) << left <<"Dien vien";
     int x1=whereX();
    box(x,y,x1-5,2,t_color,b_color);
    cout<<endl;   
}

void QuanLyPhim::Show()
{  
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
    box(x1,y1,145,y-5,1,0);
    GoTo(x1,y+1); 
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
            SetColor(0,7);
            CanLe();
            cout << "Nhap Ma Phim Moi: ";
            fflush(stdin);
            SetColor(0,2);
            getline(cin, a);
            CanLe();
            SetColor(0,7);
            cout << "Nhap Ten Phim Moi: ";
            fflush(stdin);
            SetColor(0,2);
            getline(cin, b);
            CanLe();
            SetColor(0,7);
            cout << "Nhap The Loai: ";
            fflush(stdin);
            SetColor(0,2);
            getline(cin, c);
            CanLe();
            SetColor(0,7);
            cout << "Nhap Thoi Luong: ";
            fflush(stdin);
            SetColor(0,2);
            getline(cin, c);
            CanLe();
            SetColor(0,7);
            cout << "Nhap Dao Dien: ";
            fflush(stdin);
            SetColor(0,2);
            getline(cin, d);
            CanLe();
            SetColor(0,7);
            cout << "Nhap Dien Vien: ";
            fflush(stdin);
            SetColor(0,2);
            getline(cin, e);
            CanLe();
            SetColor(0,7);
            cout << "Nhap Nam Cong Chieu: ";
            fflush(stdin);
            SetColor(0,2);
            getline(cin, h);
            CanLe();
            SetColor(0,7);
            cout << "Nhap Quoc Gia: ";
            fflush(stdin);
            SetColor(0,2);
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
    else {
        SetColor(0,4);
        CanLe();
        cout << "Khong Tim Thay Ma Phim Can Sua!";
        SetColor(0,7);
    }
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
    SetColor(0,3);
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
        CanLe();
        int x1=whereX();
        int y1=whereY();
        cout << endl;
        for (int i = 0; i < this->n; i++)
        {
            if((this->p+i)->getTheLoai() == m){
                CanLe();
                (this->p + i)->Display();
            }
        }
        int y=whereY();
        box(x1,y1,145,y-5,1,0);
        GoTo(x1,y+1); 
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
        SetColor(0,4);
        GoTo(5,5);
        cout << "Khong Tim Thay" << endl;
        getchar();
    }
    else{
        system("cls");
        GoTo(5,3);
        TieuDeCot();
        CanLe();
        int x1=whereX();
        int y1=whereY();
        cout << endl;
        for (int i = 0; i < this->n; i++)
        {
            if(strstr((this->p+i)->getTenPhim().c_str(),m.c_str())){
                CanLe();
                (this->p + i)->Display();
            }
        }
        int y=whereY();
        box(x1,y1,145,y-5,1,0);
        GoTo(x1,y+1); 
    }
}



// Menu

void QuanLyPhim::Menu(){
    system("cls");
    vector<string>  m={ 
     "1.Xem Danh Sach Phim",
     "2.Them Phim",
     "3.Xoa Phim",
     "4.Cap Nhat Phim",
     "5.Tro Ve Menu chinh"};
     vector<string>  m2={
     "1.Xem Thong Tin Chi Tiet",
      "2.Tro Ve"
     };
     SetColor(0,7);
    int chon=menu(m);
    switch (chon)
    {
    case 1:
        system("cls");
        this->Show();
        int chon2;
            chon2=menu2(m2);   
            switch (chon2)
            {
            case 1:
                SetColor(0,1);
                XemThongTinPhim();
                break;
            case 2:
                this->Menu();
                break;
            default:
                system("cls");
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
        system("cls");
        break;
    }
}

void QuanLyPhim::ThemPhim(){
    system("cls");
    vector<string> m={
        "1.Them Phim",
        "2.Tro Ve" 
    };
    this->Show();
    SetColor(0,3);
    CanLe();
    cout << "Them Mot Phim: \n" << endl;
    Film temp;
    cin >> temp;
    this->Add(temp); 
    SetColor(0,14);  
    CanLe(); 
    cout << "Them Thanh Cong" << endl;
    UpdateFile_Phim(*this);
    int chon=menu2(m);
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
    vector<string> m={
        "1.Nhap Lai",
        "2.Tro ve"
    };
    this->Show();
    string ma;
    SetColor(0,3);
    cout<<"--------------------------------"<<endl;
    CanLe();
    cout << "Nhap Ma Phim Ban Muon Cap Nhat: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        SetColor(0,4);
        CanLe();
        cout << "Khong Co Ma Phim Nao Trung Khop" << endl;
        int chon2=menu2(m);
        if(chon2 == 1){
            this->CapNhatPhim();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Update(ma);
        SetColor(0,14);
        CanLe();
        cout << "Cap Nhat Phim Thanh Cong!!\n" << endl;
        int chon3=menu2(m);
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
      vector<string> m={
        "1.Nhap Lai",
        "2.Tro ve"
    };
    this->Show();
    string ma;
    SetColor(0,3);
    CanLe();
    cout << "Nhap Ma Phim Ban Muon Xoa: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        SetColor(0,4);
        cout << "Khong Co Ma Phim Nao Trung Khop" << endl;
        int chon2=menu2(m);
        if(chon2 == 1){
            this->XoaPhim();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Delete(ma);
        SetColor(0,14);
        CanLe();
        cout << "Xoa Phim Thanh Cong!!\n" << endl;
        int chon3=menu2(m);
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
    vector<string> m={
        "1.Nhap Lai",
        "2.Tro ve"
    };
    vector<string> m2={
        "1.Xem Thong Tin Phim",
        "2.Tro ve"
    };

    this->Show();
    string ma;
    SetColor(0,3);
    CanLe();
    cout << "Nhap Ma Phim Ban Muon Xem: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        SetColor(0,4);
        CanLe();
        cout << "Khong Co Ma Phim Nao Trung Khop" << endl;
        int chon2=menu2(m);
        if(chon2 == 1){
            SetColor(0,3);
            this->XemThongTinPhim();
        }
        else if(chon2 == 2){
            this->Menu();
        }
    }
    else {
        (this->p + index)->Display2();
        int chon3=menu2(m2);
        if(chon3 == 1){
            this->XemThongTinPhim();
        }
        else if(chon3 == 2){
            this->Menu();
        }
    }
}


