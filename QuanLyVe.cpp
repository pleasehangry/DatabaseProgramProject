#include "QuanLyVe.h"
#include "DocFile.h"





void QuanLyVe::Show(){
    GoTo(5,3);
    cout << setw(15-1) << left <<  "Ma Ve: " <<   "| ";
    cout << setw(15-1) << left <<  "Ma Phim: " <<  "| ";
    cout << setw(20-1) << left <<  "Loai Khach Hang: "  <<  "| ";
    cout << setw(15-1) << left <<  "Gia Ve: " << "| ";
    cout << setw(15-1) << left <<  "So Luong: "  <<  "| ";
    cout << setw(15-1) << left <<  "So Ve Da Ban: "  <<  "| ";
    cout << setw(15-1) << left <<  "Thanh Tien: " << endl;
    for(int i= 0; i < this->n; i++){
        CanLe();
        (p+i)->Display();
    }
}

int QuanLyVe::CheckMS(string s)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if (s == (this->p + i)->getMaVe())
        {
            index = i;
            break;
        }
    }
    return index;
}

void QuanLyVe::Update(string m)
{
    int i = CheckMS("m");
    if(i >= 0){
        if (m == (this->p + i)->getMaVe())
        {
            string a,b,c;
            int d,e,f;
            system("cls");
            (this->p + i)->Display();
            cout << "Nhap Ma Ve Moi: ";
            fflush(stdin);
            getline(cin, a);
            cout << "Nhap Ma Phim: ";
            fflush(stdin);
            getline(cin, b);
            cout << "Nhap Loai Khach Hang: ";
            fflush(stdin);
            getline(cin, c);
            cout << "Nhap Gia Ve: ";
            cin >> d;
            cout << "Nhap So Luong: ";
            cin >> e;
            cout << "Nhap So Ve Da Ban: ";
            cin >> f;
            (this->p + i)->setMaVe(a);
            (this->p + i)->setMaPhim(b);
            (this->p + i)->setLoaiKhachHang(c);
            (this->p + i)->setGiaLoaiVe(d);
            (this->p + i)->setSoLuong(e);
            (this->p + i)->setSoVeDaBan(f);
            (this->p + i)->ThanhTien();
        }
    }
    else cout << "Khong Tim Thay Ma Phim Can Sua!";
    cout << endl;
}



void QuanLyVe::setLoaiVe(){
    QuanLyPhim QLP;
    DocFile_Phim(QLP);
    string maVe, maPhim, loaiKhachHang, soLuongVe;
    Ve temp;
    this->Show();
    cout << "Nhap Ma Ve: ";
    cin >> maVe;
    temp.setMaVe(maVe);
    QLP.Show();
    cout << "Chon Ma Phim Ban Muon Tao Ve: ";
    cin >> maPhim;
    while(QLP.CheckMS(maPhim)<0){
        cout << "Ban Da Nhap Sai Ma Phim, Vui Long Nhap Lai: ";
        cin >> maPhim;
    }
    temp.setMaPhim(maPhim);
    cout << "Nhap Loai Khach Hang: ";
    cin >> loaiKhachHang;
    cout << "Nhap So Luong Ve: ";
    cin >> soLuongVe;
    this->Add(temp);
    cout << "Tao Ve Thanh Cong!" << endl;
}

int QuanLyVe::GetMaVe(string maPhim, string loaiKhachHang){
    int idex = -1;
    for(int i = 0; i < this->n; i++){
        if(((this->p + i)->getMaPhim() == maPhim) && ((this->p + i)->getLoaiKhachHang()== loaiKhachHang)){
            idex = i;
            break;
        }
    }
    return idex;
}



void QuanLyVe::Menu(){
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
                XemThongTinVe();
                break;
            case 2:
                this->Menu();
            default:
                break;
            }
        break;
    case 2:
        this->ThemVe();
        break;
    case 3:
        this->XoaVe();
        break;
    case 4:
        this->CapNhatVe();
        break;
    default:
        break;
    }
}

void QuanLyVe::ThemVe(){
    system("cls");
    this->Show();
    cout << "Them Mot Ve: " << endl;
    Ve temp;
    setLoaiVe();
    cout << "Them Thanh Cong" << endl;
    int chon;
    cout << "1.Them Ve" << endl;
    cout << "2.Tro Ve" << endl;
    cout << "Nhap Lua Chon" << endl;
    cin >> chon;
    switch (chon)
    {
    case 1:
        ThemVe();
        break;
    case 2:
        this->Menu();
        break;
    default:
        this->Menu();
        break;
    }
}

void QuanLyVe::CapNhatVe(){
    system("cls");
    this->Show();
    string ma;
    cout << "Nhap Ma Ve Ban Muon Cap Nhat: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        cout << "Khong Co Ma Ve Nao Trung Khop" << endl;
        int chon2;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon2;
        if(chon2 == 1){
            this->CapNhatVe();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Update(ma);
        cout << "Cap Nhat Ve Thanh Cong!!\n" << endl;
        int chon3;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon3;
        if(chon3 == 1){
            this->CapNhatVe();
        }
        else{
            this->Menu();
        }
    }
}


void QuanLyVe::XoaVe(){
    system("cls");
    this->Show();
    string ma;
    cout << "Nhap Ma Ve Ban Muon Xoa: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        cout << "Khong Co Ma Ve Nao Trung Khop" << endl;
        int chon2;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon2;
        if(chon2 == 1){
            this->XoaVe();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Delete(ma);
        cout << "Xoa Ve Thanh Cong!!\n" << endl;
        int chon3;
        cout << "1.Xoa Ve" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon3;
        if(chon3 == 1){
            this->XoaVe();
        }
        else{
            this->Menu();
        }
    }
}
void QuanLyVe::XemThongTinVe(){
    system("cls");
    this->Show();
    string ma;
    cout << "Nhap Ma Ve Ban Muon Xem: ";
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        cout << "Khong Co Ma Ve Nao Trung Khop" << endl;
        int chon2;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon2;
        if(chon2 == 1){
            this->XemThongTinVe();
        }
        else if(chon2 == 2){
            this->Menu();
        }
    }
    else {
        (this->p + index)->Display();
        int chon3;
        cout << "1.Xem Thong Tin Ve" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon3;
        if(chon3 == 1){
            this->XemThongTinVe();
        }
        else if(chon3 == 2){
            this->Menu();
        }
    }
}


