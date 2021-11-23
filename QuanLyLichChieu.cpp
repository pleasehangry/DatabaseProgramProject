#include "QuanLyLichChieu.h"
#include "DocFile.h"


void QuanLyLichChieu::TieuDeCot(){
    GoTo(5, 3);
    cout << setw(20-1) << left << "Ma Lich Chieu" << "| ";
    cout << setw(30-1) << left << "Ten LichChieu:" << "| ";
    cout << setw(20-1) << left << "Ngay:" << "| ";
    cout << setw(20-1) << left << "Gio:" << "| ";
    cout << setw(20-1) << left << "Phong Chieu:" << endl;
}

void QuanLyLichChieu::Show()
{
    TieuDeCot();
    for (int i = 0; i < this->n; i++)
    {
        CanLe();
        (this->p + i)->Display();
    }
    cout << endl;
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
            cout << "Nhap Ma Lich Chieu Moi: ";
            fflush(stdin);
            getline(cin, a);
            cout << "\nNhap Ten LichChieu Moi: ";
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


void QuanLyLichChieu::setLichChieu(){
    QuanLyPhim QLP;
    QLPhongChieu QLPC;
    DocFile_Phim(QLP);
    DocFile_PC(QLPC);
    LichChieu temp;
    string ngay, gio, phongchieu,MsPhim, maLichChieu;
    cout << "Nhap Ma Lich Chieu:";
    cin >> maLichChieu;
    temp.setMaLichChieu(maLichChieu);
    QLP.Show();
    cout << "Nhap Ma So Phim Ban Muon Len Lich: "; cin >> MsPhim;
    int k = QLP.CheckMS(MsPhim);
    temp.setTenPhim(QLP.getFimlName(k));
    cout << "Nhap Ngay: "; cin >> ngay;
    temp.setNgay(ngay);
    cout << "Nhap Gio: "; cin >> gio;
    temp.setGio(gio);
    QLPC.Show();
    cout << "Nhap Ma Phong Chieu De Chon Phong Chieu: ";
    cin >> phongchieu;
    int h = QLPC.CheckMS(phongchieu);
    if(h < 0){
        do{
            cout << "Da Nhap Sai Ma Phong, Vui Long Nhap Lai: ";
            cin >> phongchieu;
            h = QLPC.CheckMS(phongchieu);
        }
        while(h > 0);
    } else{
        temp.setPhongChieu(phongchieu);
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

    cout << endl;
    cout << "1.Xem Danh Sach Lich Chieu" << endl;
    cout << "2.Them Lich Chieu" << endl;
    cout << "3.Xoa Lich Chieu" << endl;
    cout << "4.Cap Nhat Lich Chieu" << endl;
    cout << "5.Tro Ve Man Hinh Chinh" << endl;
    int chon;
    cout << ">>"; cin >> chon;
    switch (chon)
    {
    case 1:
        system("cls");
        this->Show();
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
        break;
    }
}

void QuanLyLichChieu::CapNhatLichChieu(){
    system("cls");
    this->Show();
    string ma;
    cout << "Nhap Ma Lich Chieu Ban Muon Cap Nhat: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        cout << "Khong Co Ma Lich Chieu Nao Trung Khop" << endl;
        int chon2;
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
        cout << "Cap Nhat Lich Chieu Thanh Cong!!\n" << endl;
        int chon3;
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
    cout << "Nhap Ma Lich Chieu Ban Muon Xoa: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        cout << "Khong Co Ma Lich Chieu Nao Trung Khop" << endl;
        int chon2;
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
        cout << "Xoa Lich Chieu Thanh Cong!!\n" << endl;
        int chon3;
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