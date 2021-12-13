#include "QuanLyVe.h"
#include "DocFile.h"

void QuanLyVe::TieuDeCot()
{
    int t_color=1;
    int b_color=0;
    int x=whereX();
    int y=whereY();
  	cout<<endl;
    CanLe();
    cout << setw(15) << left <<  " Ma Ve: "  <<char(179);
    cout << setw(15-1) << left <<  "Ma Phim: "  <<char(179);
    cout << setw(20-1) << left <<  "Loai Khach Hang: "<<char(179);
    cout << setw(15-1) << left <<  "Gia Ve: " <<char(179);
    cout << setw(15-1) << left <<  "So Luong: " <<char(179);
    cout << setw(15-1) << left <<  "So Ve Da Ban: " <<char(179);
    cout << setw(15-1) << left <<  "Thanh Tien: ";
    int x1=whereX();
    box(x,y,x1-5,2,t_color,b_color);
    cout<<endl; 
}
void QuanLyVe::Show(){
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
    box(x1,y1,110,y-5,1,0);
    GoTo(x1,y+1); 
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
    int i = CheckMS(m);
    if(i >= 0){
        if (m == (this->p + i)->getMaVe())
        {
            string a,b,c;
            int d,e,f;
            system("cls");
            GoTo(5,3);
            (this->p + i)->Display();
            SetColor(0,3);
            CanLe();
            cout << "Nhap Ma Ve Moi: ";
            fflush(stdin);
            getline(cin, a);
            CanLe();
            cout << "Nhap Ma Phim: ";
            fflush(stdin);
            getline(cin, b);
            CanLe();
            cout << "Nhap Loai Khach Hang: ";
            fflush(stdin);
            getline(cin, c);
            CanLe();
            cout << "Nhap Gia Ve: ";
            cin >> d;
            CanLe();
            cout << "Nhap So Luong: ";
            cin >> e;
            CanLe();
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
    else {
        return;
    }
    cout << endl;
}



void QuanLyVe::setLoaiVe(){
    system("cls");
    QuanLyPhim QLP;
    DocFile_Phim(QLP);
    string maVe, maPhim, loaiKhachHang;
    int soLuongVe;
    Ve temp;
    this->Show();
    SetColor(0,3);
    CanLe();
    cout << "Nhap Ma Ve: ";
    cin >> maVe;
    temp.setMaVe(maVe);
    system("cls");
    QLP.Show();
    CanLe();
    cout << "Chon Ma Phim Ban Muon Tao Ve: ";
    cin >> maPhim;
    while(QLP.CheckMS(maPhim)<0){
        SetColor(0,4);
        CanLe();
        cout << "Ban Da Nhap Sai Ma Phim, Vui Long Nhap Lai: ";
        cin >> maPhim;
    }
    temp.setMaPhim(maPhim);
    SetColor(0,3);
    CanLe();
    cout << "Nhap Loai Khach Hang: ";
    cin >> loaiKhachHang;
    temp.setLoaiKhachHang(loaiKhachHang);
    CanLe();
    cout << "Nhap So Luong Ve: ";
    cin >> soLuongVe;
    temp.setSoLuong(soLuongVe);
    this->Add(temp);
    SetColor(0,14);
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
    vector<string> m={
     "1.Xem Danh Sach Ve",
     "2.Them Ve",
     "3.Xoa Ve",
     "4.Cap Nhat Ve",
     "5.Tro Ve Menu chinh"};
     vector<string> m2={
         "1.Xem Thong Tin Chi Tiet",
         "2.Tro Ve"
     };
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
                XemThongTinVe();
                break;
            case 2:
                system("cls");
                this->Menu();
            default:
                system("cls");
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
    system("cls");
        break;
    }
}

void QuanLyVe::ThemVe(){
    system("cls");
    this->Show();
    vector<string> m = {"Them Ve", "Tro Ve"};
    SetColor(0,3);
    CanLe();
    cout << "Them Mot Ve: " << endl;
    setLoaiVe();
    SetColor(0,14);
    CanLe();
    cout << "Them Thanh Cong" << endl;
    SetColor(0,15);
    int chon = menu2(m);
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
    vector<string> m={"Nhap Lai","Tro Ve"};
    this->Show();
    vector<string> m2 = {"Nhap Lai","Tro Ve"};
    string ma;
    SetColor(0,3);
    cout << "Nhap Ma Ve Ban Muon Cap Nhat: ";
    SetColor(0,15);
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        SetColor(0,4);
        cout << "Khong Co Ma Ve Nao Trung Khop" << endl;
        int chon2;
        SetColor(0,15);
        chon2 = menu2(m2);
        if(chon2 == 1){
            this->CapNhatVe();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Update(ma);
        SetColor(0,14);
        cout << "Cap Nhat Ve Thanh Cong!!\n" << endl;
        int chon3;
        SetColor(0,15);
        CanLe();
        chon3 = menu2(m2);
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
    vector<string> m={
        "Xoa Ve",
        "Tro Ve"
    };
    vector<string> m2={
        "Nhap Lai",
        "Tro Ve"
    };
    this->Show();
    string ma;
    SetColor(0,3);
    cout << "Nhap Ma Ve Ban Muon Xoa: ";
    SetColor(0,15);
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        SetColor(0,4);
        cout << "Khong Co Ma Ve Nao Trung Khop" << endl;
        int chon2;
        chon2=menu2(m2);
        if(chon2 == 1){
            this->XoaVe();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Delete(ma);
        SetColor(0,14);
        CanLe();
        cout << "Xoa Ve Thanh Cong!!\n" << endl;
        int chon3;
        chon3=menu2(m);
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
    vector<string> m={"Xem Thong Tin Ve","Tro Ve"};
    vector<string> m2={ "Nhap Lai","Tro Ve"};
    CanLe();
    this->Show();
    string ma;
    SetColor(0,3);
    cout << "Nhap Ma Ve Ban Muon Xem: ";
    SetColor(0,15);
    cin >> ma;
    int index = CheckMS(ma);
    if(index == -1){
        SetColor(0,4);
        CanLe();
        cout << "Khong Co Ma Ve Nao Trung Khop" << endl;
        int chon2;
        chon2=menu2(m2);
        if(chon2 == 1){
            this->XemThongTinVe();
        }
        else if(chon2 == 2){
            this->Menu();
        }
    }
    else {
        SetColor(0,3);
        CanLe();
        TieuDeCot();
        CanLe();
        (this->p + index)->Display();
        int chon3;
        chon3=menu2(m);
        if(chon3 == 1){
            this->XemThongTinVe();
        }
        else if(chon3 == 2){
            this->Menu();
        }
    }
}


