#include "QLPhongChieu.h"
#include<string>



void QLPhongChieu::Show(){
    GoTo(5, 3);
    cout << setw(25) << left << "Ma Phong Chieu" << "|";
    cout << setw(20) << left << " So Ghe:" << "|";
    cout << setw(20) << left << " May Chieu:" << "|";
    cout << setw(20) << left << " Am Thanh:" << "|";
    cout << setw(20) << left << " Dien Tich:" << "|";
    cout << setw(20) << left << " Tinh Trang:" << "|";
    cout << setw(20) << left << " Ma Bao Ve:" << endl;
    for(int i= 0; i < this->n; i++){
        CanLe();
        (p+i)->Display();
    }
    cout << endl;
}

int QLPhongChieu::CheckMS(string s)
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

void QLPhongChieu::Update(string m)
{
    int i = CheckMS(m);
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

// Menu


void QLPhongChieu::Menu(){
    system("cls");

    cout << endl;
    cout << "1.Xem Danh Sach Phong Chieu" << endl;
    cout << "2.Them Phong Chieu" << endl;
    cout << "3.Xoa Phong Chieu" << endl;
    cout << "4.Cap Nhat Phong Chieu" << endl;
    cout << "5.Thoat" << endl;
    int chon;
    cout << ">>"; cin >> chon;

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
                XemThongTinPhongChieu();
                break;
            case 2:
                this->Menu();
            default:
                break;
            }
        break;
    case 2:
        this->ThemPhongChieu();
        break;
    case 3:
        this->XoaPhongChieu();
        break;
    case 4:
        this->CapNhatPhongChieu();
        break;
    default:
        break;
    }
}

void QLPhongChieu::ThemPhongChieu(){
    system("cls");
    this->Show();
    cout << "Them Mot PhongChieu: " << endl;
    PhongChieu temp;
    cin >> temp;
    this->Add(temp);    
    cout << "Them Thanh Cong" << endl;
    int chon;
    cout << "1.Them PhongChieu" << endl;
    cout << "2.Tro Ve" << endl;
    cout << "Nhap Lua Chon";cin >> chon;
    
    switch (chon)
    {
    case 1:
        ThemPhongChieu();
        break;
    case 2:
        this->Menu();
        break;
    default:
        this->Menu();
        break;
    }
}

void QLPhongChieu::CapNhatPhongChieu(){
    system("cls");
    this->Show();
    string ma;
    cout << "Nhap Ma PhongChieu Ban Muon Cap Nhat: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        cout << "Khong Co Ma PhongChieu Nao Trung Khop" << endl;
        int chon2;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon2;
        if(chon2 == 1){
            this->CapNhatPhongChieu();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Update(ma);
        cout << "Cap Nhat PhongChieu Thanh Cong!!\n" << endl;
        int chon3;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> ";cin >> chon3;
        
        if(chon3 == 1){
            this->CapNhatPhongChieu();
        }
        else{
            this->Menu();
        }
    }
}


void QLPhongChieu::XoaPhongChieu(){
    system("cls");
    this->Show();
    string ma;
    cout << "Nhap Ma Phong Chieu Ban Muon Xoa: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        cout << "Khong Co Ma Phong Chieu Nao Trung Khop" << endl;
        int chon2;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> ";cin >> chon2;
        
        if(chon2 == 1){
            this->XoaPhongChieu();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Delete(ma);
        cout << "Xoa PhongChieu Thanh Cong!!\n" << endl;
        int chon3;
        cout << "1.Xoa PhongChieu" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon3;
        if(chon3 == 1){
            this->XoaPhongChieu();
        }
        else{
            this->Menu();
        }
    }
}
void QLPhongChieu::XemThongTinPhongChieu(){
    system("cls");
    this->Show();
    string ma;
    cout << "Nhap Ma Phong Chieu Ban Muon Xem: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        cout << "Khong Co Ma Phong Chieu Nao Trung Khop" << endl;
        int chon2;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon2;
        if(chon2 == 1){
            this->XemThongTinPhongChieu();
        }
        else if(chon2 == 2){
            this->Menu();
        }
    }
    else {
        (this->p + index)->Display2();
        int chon3;
        cout << "1.Xem Thong Tin PhongChieu" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> "; cin >> chon3;
        
        if(chon3 == 1){
            this->XemThongTinPhongChieu();
        }
        else if(chon3 == 2){
            this->Menu();
        }
    }
}