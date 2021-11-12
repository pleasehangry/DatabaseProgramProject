#include "QuanLyPhim.h"
QuanLyPhim::QuanLyPhim()
{
    this->p = nullptr;
    this->n = 0;
}

QuanLyPhim::~QuanLyPhim()
{
    delete[] this->p;
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
    cout << setw(10) << left << " Ma Phim" << "|";
    cout << setw(30) << left << " Ten Phim:" << "|";
    cout << setw(25) << left << " The loai:" << "|";
    cout << setw(15) << left << " Thoi Luong:" << "|";
    cout << setw(25) << left << " Dao Dien:" << "|";
    cout << setw(25) << left << " Dien Vien:" << endl;
}

void QuanLyPhim::Show()
{
    TieuDeCot();
    for (int i = 0; i < this->n; i++)
    {
        (p + i)->Display();
    }
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
    string m;
    cout<<"Nhap the loai phim:"<<endl;
    cin>>m;
    system("cls");
    int count = 0;
    cout << endl;
    GoTo(5,2);
    cout << " Nhung Phim The Loai " << m;
    GoTo(0,5);
    TieuDeCot();
    for(int i = 0; i < this->n; i++){
        if((this->p+i)->getTheLoai() == m){
           (this->p + i)->Display();
           count++;
        }
    }
    if(count == 0) cout << "Khong Co The Loai Phim Nay";
}

void QuanLyPhim::TimKiemPhim(){
    system("cls");
    string s;
    GoTo(0,3);
    cout << "   Nhap Ten Phim Ban Muon Tim: ";  cin >> s;
    int k = 0;
    cout << endl;
    TieuDeCot();
    for (int i = 0; i < this->n; i++)
    {
        if(strstr((this->p)->getTenPhim().c_str(),s.c_str())){ // chuoi s la con cua chuoi ten phim
            (this->p+i)->Display();
            k++;
        }
    }
    if(k==0){
        system("cls");
        cout << "Khong Tim Thay" << endl;
        getchar();
    }
}

// void QuanLyPhim::MenuChoKhach()
// {
//     cout<<"\n1.Xem Hom nay co phim gi:"<<endl;
//     cout<<"\n2.Tim kiem Phim theo the loai:"<<endl;
//     cout<<"\n3.Tim kiem theo ten Phim"<<endl;
//     cout << endl;
//     int chon;
//     cout << "Nhap Lua Chon: ";
//     cin >> chon;
//     switch (chon)
//     {
//     case 1:
//         /* code */
//         break;
//     case 2:
//         XemTheloaiPhim();
//         break;
//     case 3:
//         TimKiemPhim();
//         break;
//     default:
//         break;
//     }
    
// }

