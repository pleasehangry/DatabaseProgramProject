#include "QuanLyPhim.h"

QuanLyPhim::QuanLyPhim()
{
    this->p = nullptr;
    this->n = 0;
}

QuanLyPhim::~QuanLyPhim()
{
    delete[] this->p;
    this->n = 0;
}

void QuanLyPhim::Add_Film(const Film &f)
{
    if (this->n == 0)
    {
        this->p = new Film[this->n + 1];
        *(this->p + this->n) = f;
    }
    else
    {
        Film *temp = new Film[this->n];
        for (int i = 0; i < this->n; i++)
        {
            *(temp + i) = *(this->p + i);
        }
        delete[] this->p;
        this->p = new Film[this->n + 1];
        for (int i = 0; i < this->n; i++)
        {
            *(this->p + i) = *(temp + i);
        }
        delete[] temp;
        *(this->p + n) = f;
    }
    this->n++;
}
void QuanLyPhim::TieuDeCot(){
    int t_color=1;
    int b_color=0;
    int x=whereX();
    int y=whereY();
  	cout<<endl;
     cout << setw(10) << left << " Ma Phim"<<char(179);
     cout << setw(29) << left <<"Ten Phim" <<char(179);
     cout << setw(24) << left << "The loai"<< char(179);
     cout << setw(14) << left << "Thoi luong"<< char(179);
     cout << setw(24) << left <<"Dao dien"<< char(179);
     cout << setw(39) << left <<"Dien vien";
     int x1=whereX();
    box(x,y,x1,2,t_color,b_color);
    cout<<endl;   
}

void QuanLyPhim::Show()
{
    TieuDeCot();
    int x1=whereX();
    int y1=whereY();
    cout<<endl;
    for (int i = 0; i < this->n; i++)
    {
        (p + i)->Display();
    } 
    int y=whereY();
    box(x1,y1,145,y-2,1,0);  
}

int QuanLyPhim::checkMSFilm(string s)
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


void QuanLyPhim::Update_Film(string m)
{
    int i = checkMSFilm(m);
    if(i >= 0){
        if (m == (this->p + i)->getMaPhim())
        {
            string a,b,c,d,e,f;
            string g, h;
            system("cls");
            (this->p + i)->Display2();
            SetColor(0,3);
            cout << "Nhap Ma Phim Moi: ";
            fflush(stdin);
            SetColor(0,7);
            getline(cin, a);
             SetColor(0,3);
            cout << "\nNhap Ten Phim Moi: ";
            fflush(stdin);
            SetColor(0,7);
            getline(cin, b);
             SetColor(0,3);
            cout << "\nNhap The Loai: ";
            fflush(stdin);
            SetColor(0,7);
            getline(cin, c);
             SetColor(0,3);
            cout << "\nNhap Thoi Luong: ";
            fflush(stdin);
            SetColor(0,7);
            getline(cin, c);
             SetColor(0,3);
            cout << "\nNhap Dao Dien: ";
            fflush(stdin);
            SetColor(0,15);
            getline(cin, d);
             SetColor(0,3);
            cout << "\nNhap Dien Vien: ";
            fflush(stdin);
            SetColor(0,7);
            getline(cin, e);
             SetColor(0,3);
            cout << "\nNhap Nam Cong Chieu: ";
            fflush(stdin);
            SetColor(0,7);
            getline(cin, h);
             SetColor(0,3);
            cout << "Nhap Quoc Gia: ";
            fflush(stdin);
            SetColor(0,7);
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
    else 
    SetColor(0,4);
    cout << "Khong Tim Thay Ma Phim Can Sua!";
    cout << endl;
}
void QuanLyPhim::Delete_Film(string m)
{
    int f = checkMSFilm(m);
    if (f >= 0)
    {
        if (this->n == 1)
        {
            delete[] this->p;
            this->p = nullptr;
        }
        else
        {
            Film *temp = new Film[this->n];
            for (int k = 0; k < this->n; k++)
            {
                *(temp + k) = *(this->p + k);
            }
            delete[] this->p;
            this->p = new Film[this->n - 1];
            for (int j = 0; j < this->n - 1; j++)
            {
                if (j < f)
                {
                    *(this->p + j) = *(temp + j);
                }
                else
                {
                    *(this->p + j) = *(temp + j + 1);
                }
            }
            delete[] temp;
        }
    }
    this->n--;
}

void QuanLyPhim::XemTheloaiPhim(){
    cout << endl;
    SetColor(0,9);
    cout << (this->p)->getTheLoai() << endl;
    for (int i = 1; i < this->n; i++)
    {
        if((this->p+i)->getTheLoai()!=(this->p+i-1)->getTheLoai())
        
        cout << (this->p+i)->getTheLoai() << endl;
    }
    SetColor(0,15);
}

void QuanLyPhim::XemDSPhimCuaTheLoai(){
    system("cls");
    string m;
    SetColor(0,3);
    cout<<"Nhap the loai phim:"<<endl;
    fflush(stdin);
    getline(cin,m);
    int count = 0;
    cout << endl;
    GoTo(5,2);
    SetColor(0,9);
    cout << " Nhung Phim The Loai " << m;
    GoTo(0,5);
    for(int i = 0; i < this->n; i++){
        if((this->p+i)->getTheLoai() == m){
           count++;
        }
    }
    if(count == 0) {
        SetColor(0,4);
        cout << "Khong Co Phim Nao Thuoc The Loai Nay";
        int chon;
        SetColor(0,15);
        cout << "\n1.Nhap lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">>"; cin >> chon;
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
        for (int i = 0; i < this->n; i++)
        {
            if(i==0) TieuDeCot();    
            if((this->p+i)->getTheLoai() == m){
            (this->p + i)->Display();
            }
        }
    }
}

void QuanLyPhim::TimKiemPhim(){
    system("cls");
    GoTo(0,9);
    SetColor(0,3);
    cout << "   Nhap Ten Phim Ban Muon Tim: ";
    string s;
    fflush(stdin);
    SetColor(0,9);
    getline(cin,s);
    int k = 0;
    cout << endl;
    for (int i = 0; i < this->n; i++)
    {
        if(strstr((this->p)->getTenPhim().c_str(),s.c_str())){ // chuoi s la con cua chuoi ten phim
            k++;
        }
    }
    if(k==0){
        SetColor(0,4);
        cout << "Khong Tim Thay" << endl;
        getchar();
    }
    else{
        for (int i = 0; i < this->n; i++)
        {
            if(i == 0) TieuDeCot();
            if(strstr((this->p)->getTenPhim().c_str(),s.c_str())){ // chuoi s la con cua chuoi ten phim
                (this->p+i)->Display();
                k++;
            }
        }
    }
}

// Da Nang Hoa
Film& QuanLyPhim::operator[](const int& index){
    static Film temp;
    if(index >=0 && index < this->n){
        return *(this->p + index);
    }
    else return temp;
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
     SetColor(0,7);
    int chon=menu(m);
    switch (chon)
    {
    case 1:
        system("cls");
        this->Show();
        int chon2;
        SetColor(0,8);
        cout << "\n1.Xem Thong Tin Chi Tiet" << endl;
        cout << "2.Tro Ve" << endl;
        cout << (char)16<<(char)16; cin >> chon2;
            switch (chon2)
            {
            case 1:
            SetColor(0,1);
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
        system("cls");
        break;
    }
}

void QuanLyPhim::ThemPhim(){
    system("cls");
    this->Show();
    SetColor(0,3);
    cout << "Them Mot Phim: " << endl;
    Film temp;
    cin >> temp;
    this->Add_Film(temp); 
    SetColor(0,14);   
    cout << "Them Thanh Cong" << endl;
    int chon;
    SetColor(0,15);
    cout << "\n1.Them Phim" << endl;
    cout << "2.Tro Ve" << endl;
    SetColor(0,9);
    cout << "Nhap Lua Chon" << endl;
    cout<<(char)16<<(char)16;cin >> chon;
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
    SetColor(0,3);
    cout<<"--------------------------------"<<endl;
    cout << "Nhap Ma Phim Ban Muon Cap Nhat: ";
    cin >> ma;
    int index = checkMSFilm(ma);
    if(index == -1){
        SetColor(0,4);
        cout << "Khong Co Ma Phim Nao Trung Khop" << endl;
        int chon2;
        SetColor(0,15);
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << (char)16<<(char)16 << endl;
        cin >> chon2;
        if(chon2 == 1){
            this->CapNhatPhim();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Update_Film(ma);
        SetColor(0,14);
        cout << "Cap Nhat Phim Thanh Cong!!\n" << endl;
        int chon3;
        SetColor(0,15);
        cout << "\n1.Nhap Lai" << endl;
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
    SetColor(0,3);
    cout<<"----------------------------"<<endl;
    cout << "Nhap Ma Phim Ban Muon Xoa: ";
    cin >> ma;
    int index = checkMSFilm(ma);
    if(index == -1){
        SetColor(0,4);
        cout << "Khong Co Ma Phim Nao Trung Khop" << endl;
        int chon2;
        SetColor(0,15);
        cout << "\n1.Nhap Lai" << endl;
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
        this->Delete_Film(ma);
        SetColor(0,14);
        cout << "Xoa Phim Thanh Cong!!\n" << endl;
        int chon3;
        SetColor(0,15);
        cout << "\n1.Xoa Phim" << endl;
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
    SetColor(0,3);
    cout << "\nNhap Ma Phim Ban Muon Xem: ";
    cin >> ma;
    int index = checkMSFilm(ma);
    if(index == -1){
        SetColor(0,4);
        cout << "Khong Co Ma Phim Nao Trung Khop" << endl;
        int chon2;
        SetColor(0,15);
        cout << "\n1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon2;
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
        int chon3;
        SetColor(0,15);
        cout << "\n1.Xem Thong Tin Phim" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> ";
        cin >> chon3;
        if(chon3 == 1){
            this->XemThongTinPhim();
        }
        else if(chon3 == 2){
            this->Menu();
        }
    }
}



