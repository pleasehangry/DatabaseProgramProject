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

void QuanLyPhim::Show()
{
    cout << "|" << setw(15) << left << " Ma Phim" << "|";
    cout << setw(30) << left << " Ten Phim:" << "|";
    cout << setw(25) << left << " The loai:" << "|";
    cout << setw(25) << left << " Thoi Luong:" << "|";
    cout << setw(25) << left << " Dao Dien:" << "|";
    cout << setw(25) << left << " Dien Vien:" << endl;
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
            cout << "\nNhap Thời Lượng: ";
            fflush(stdin);
            getline(cin, c);
            cout << "\nNhap Dao Dien: ";
            fflush(stdin);
            getline(cin, d);
            cout << "\nNhap Dien Vien: ";
            fflush(stdin);
            getline(cin, e);
            cout << "\nNhap Năm Công Chiếu: ";
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