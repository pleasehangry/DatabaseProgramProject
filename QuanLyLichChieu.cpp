#include "QuanLyLichChieu.h"
#include "DocFile.h"

QuanLyLichChieu::QuanLyLichChieu(/* args */)
{
    this->p = NULL;
    this->n = 0;
}

QuanLyLichChieu::~QuanLyLichChieu()
{
    delete[] this->p;
}


void QuanLyLichChieu::Add_LichChieu(const LichChieu &f)
{
    if (this->n == 0)
    {
        this->p = new LichChieu[this->n + 1];
        *(this->p + this->n) = f;
    }
    else
    {
        LichChieu *temp = new LichChieu[this->n + 1];
        for (int i = 0; i < this->n; i++)
        {
            *(temp + i) = *(this->p + i);
        }
        delete[] this->p;
        this->p = new LichChieu[this->n + 1];
        for (int i = 0; i < this->n; i++)
        {
            *(this->p + i) = *(temp + i);
        }
        delete[] temp;
        *(this->p + n) = f;
    }
    this->n++;
}

void QuanLyLichChieu::TieuDeCot(){
    cout << setw(10) << left << " Ma Lich Chieu" << "|";
    cout << setw(30) << left << " Ten Phim:" << "|";
    cout << setw(25) << left << " The loai:" << "|";
    cout << setw(25) << left << " Thoi Luong:" << "|";
    cout << setw(25) << left << " Dao Dien:" << "|";
    cout << setw(25) << left << " Dien Vien:" << endl;
}

void QuanLyLichChieu::Show()
{
    TieuDeCot();
    for (int i = 0; i < this->n; i++)
    {
        (p + i)->Display();
    }
}

int QuanLyLichChieu::checkMaLichChieu(string s)
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

void QuanLyLichChieu::Update_LichChieu(string m)
{
    int i = checkMaLichChieu("m");
    if(i >= 0){
        if (m == (this->p + i)->getMaLichChieu())
        {
            string a,b,c,d,e;
            system("cls");
            (this->p + i)->Display();
            cout << "Nhap Ma Lich Chieu Moi: ";
            fflush(stdin);
            getline(cin, a);
            cout << "\nNhap Ten Phim Moi: ";
            fflush(stdin);
            getline(cin, b);
            cout << "\nNhap Ngay: ";
            fflush(stdin);
            getline(cin, c);
            cout << "\nNhap Gio: ";
            fflush(stdin);
            getline(cin, d);
            cout << "\nNhap Phong Chieu: ";
            fflush(stdin);
            getline(cin, e);
            (this->p + i)->setMaLichChieu(a);
            (this->p + i)->setTenPhim(b);
            (this->p + i)->setNgay(c);
            (this->p + i)->setGio(d);
            (this->p + i)->setPhongChieu(e);
        }
    }
    else cout << "Khong Tim Thay Ma Lich Chieu Can Sua!";
    cout << endl;
}

void QuanLyLichChieu::Delete_LichChieu(string m)
{
    int f = checkMaLichChieu(m);
    if (f >= 0)
    {
        if (this->n == 1)
        {
            delete[] this->p;
            this->p = nullptr;
        }
        else
        {
            LichChieu *temp = new LichChieu[this->n];
            for (int k = 0; k < this->n; k++)
            {
                *(temp + k) = *(this->p + k);
            }
            delete[] this->p;
            this->p = new LichChieu[this->n - 1];
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

void QuanLyLichChieu::setLichChieu(){
    QuanLyPhim QLP;
    QLPhongChieu QLPC;
    DocFile_Phim(QLP);
    DocFile_PC(QLPC);
    LichChieu temp;
    string ngay, gio, phongchieu,MsPhim, maLichChieu;
    cin >> maLichChieu;
    temp.setMaLichChieu(maLichChieu);
    QLP.Show();
    cout << "Nhap Ma So Phim Ban Muon Len Lich: "; cin >> MsPhim;
    int k = QLP.checkMSFilm(MsPhim);
    temp.setTenPhim((QLP.getFimlName(k)));
    cout << "Nhap Ngay: "; cin >> ngay;
    temp.setNgay(ngay);
    cout << "Nhap Gio: "; cin >> gio;
    temp.setGio(gio);
    QLPC.Show();
    cout << "Nhap Ma Phong Chieu De Chon Phong Chieu: ";
    cin >> phongchieu;
    int h = QLPC.checkMSPC(phongchieu);
    if(h < 0){
        do{
            cout << "Da Nhap Sai Ma Phong, Vui Long Nhap Lai: ";
            cin >> phongchieu;
            h = QLPC.checkMSPC(phongchieu);
        }
        while(h > 0);
    } else{
        temp.setPhongChieu(phongchieu);
        cout << "Len Lich Thanh Cong";
    }
    this->Add_LichChieu(temp);
}