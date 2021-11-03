#include "QLPhongChieu.h"
#include<string>
QLPhongChieu::QLPhongChieu(/* args */)
{
    this->p = NULL;
    this->n = 0;
}

QLPhongChieu::~QLPhongChieu()
{
    delete[] this->p;
}



void QLPhongChieu::Add_PC(PhongChieu v){
    if(this->n == 0){
        this->p = new PhongChieu[this->n+1];
        *(this->p + this->n) = v;
    }
    else{
        PhongChieu *temp = new PhongChieu[this->n+1];
        for(int i = 0; i < this->n; i++){
            *(temp+i) = *(this->p+i);
        }
        delete[] this->p;
        this->p = new PhongChieu[this->n+1];
        for(int i = 0; i < this->n; i++){
            *(this->p+i) = *(temp+i); 
        }
        delete[] temp;
        *(this->p + n) = v;
    }   
    this->n++;
}

void QLPhongChieu::Show(){
    cout << setw(25) << left << "Mã Phòng Chiếu:" << "|";
    cout << setw(20) << left << " Số Chỗ:" << "|";
    cout << setw(20) << left << " Máy Chiếu:" << "|";
    cout << setw(20) << left << " Âm Thanh:" << "|";
    cout << setw(20) << left << " Diện Tích:" << "|";
    cout << setw(20) << left << " Tình trạng:" << "|";
    cout << setw(20) << left << " Mã Bảo Vệ:" << endl;
    for(int i= 0; i < this->n; i++){
        (p+i)->Display();
    }
}

int QLPhongChieu::checkMSPC(string s)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if (s == (this->p + i)->getMaPhongChieu())
        {
            index = i;
            break;
        }
    }
    return index;
}

void QLPhongChieu::Update_PC(string m)
{
    int i = checkMSPC("m");
    if(i >= 0){
        if (m == (this->p + i)->getMaPhongChieu())
        {
            string a,c,d,f,g;
            int b;
            float e;
            system("cls");
            (this->p + i)->Display();
            cout << "Nhap Ma Phong Chieu: ";
            fflush(stdin);
            getline(cin, a);
            cout << "Nhap So Ghe: ";
            cin >> b;
            cout << "Nhap Loai May Chieu: ";
            fflush(stdin);
            getline(cin, c);
            cout << "Nhap Loai Am Thanh: ";
            fflush(stdin);
            getline(cin, c);
            cout << "Nhap Dien Tich Phong Chieu: ";
            cin >> e;
            cout << "Nhap Tinh Trang: ";
            fflush(stdin);
            getline(cin, f);
            cout << "Nhap Ma Bao Ve: ";
            fflush(stdin);
            getline(cin, g);
            (this->p + i)->setMaPhongChieu(a);
            (this->p + i)->setSoCho(b);
            (this->p + i)->setMayChieu(c);
            (this->p + i)->setAmThanh(d);
            (this->p + i)->setDienTich(e);
            (this->p + i)->setTinhTrang(f);
            (this->p + i)->setMaBaoVe(g);
        }
    }
    else cout << "Khong Tim Thay Ma Phim Can Sua!";
    cout << endl;
}

void QLPhongChieu::Delete_PC(string m)
{
    int f = checkMSPC(m);
    if (f >= 0)
    {
        if (this->n == 1)
        {
            delete[] this->p;
            this->p = nullptr;
        }
        else
        {
            PhongChieu *temp = new PhongChieu[this->n];
            for (int k = 0; k < this->n; k++)
            {
                *(temp + k) = *(this->p + k);
            }
            delete[] this->p;
            this->p = new PhongChieu[this->n - 1];
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