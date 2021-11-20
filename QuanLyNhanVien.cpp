#include"QuanLyNhanVien.h"
#include<iomanip>
int QuanLyNhanVien::ind = 0;

QuanLyNhanVien::QuanLyNhanVien(){
    this->p = NULL;
    this->n = 0;
    this->ind++;
}

QuanLyNhanVien::~QuanLyNhanVien(){
    delete[] this->p;
    this->n = 0;
    this->ind--;
}

void QuanLyNhanVien::Add_NV(NhanVien v){
    if(this->n == 0){
        this->p = new NhanVien[this->n+1];
        *(this->p + this->n) = v;
    }
    else{
        NhanVien *temp = new NhanVien[this->n+1];
        for(int i = 0; i < this->n; i++){
            *(temp+i) = *(this->p+i);
        }
        delete[] this->p;
        this->p = new NhanVien[this->n+1];
        for(int i = 0; i < this->n; i++){
            *(this->p+i) = *(temp+i); 
        }
        delete[] temp;
        *(this->p + n) = v;
    }   
    this->n++;
}

void QuanLyNhanVien::Show(){
    cout << setw(15-1) << left << " ID:";
    cout << setw(30-1) << left << " Ho Ten:";
    cout << setw(10-1) << left << " STD:";
    cout << setw(9-1) << left << " CMND:";
    cout << setw(30-1) << left << " Chuc Vu:" << endl;
    for(int i= 0; i < this->n; i++){
        (p+i)->Display();
    }
}

int QuanLyNhanVien::checkMSNV(string s){
    int index = -1;
    for(int i = 0; i < this->n; i++){
        if(s == (this->p + i)->getMaNV()){
            index = i;
            break;
        }
    }
    return index;
}

void QuanLyNhanVien::Update_NV(string m)
{
    int i = checkMSNV(m);
    if(i >= 0){
        if (m == (this->p + i)->getMaNV())
        {
            string HoTen,NgaySinh,QueQuan,SoDienThoai,SoCMT,ChucVu,PhanQuyen,TaiKhoan,MatKhau;
            cout << "Nhap Ten Moi: ";
            fflush(stdin);
            getline(cin,HoTen);
            cout << "Nhap Ngay Sinh: ";
            fflush(stdin);
            getline(cin,NgaySinh);
            cout << "Nhap Que Quan: ";
            fflush(stdin);
            getline(cin,QueQuan);
            cout << "Nhap SDT: ";
            fflush(stdin);
            getline(cin,SoDienThoai);
            cout << "Nhap CMND :";
            fflush(stdin);
            getline(cin,SoCMT);
            cout << "Nhap Chuc Vu :";
            fflush(stdin);
            getline(cin,ChucVu);
            cout << "Nhap Phan Quyen: ";
            fflush(stdin);
            getline(cin,PhanQuyen);
            cout << "Nhap Tai Khoan :";
            fflush(stdin);
            getline(cin,TaiKhoan);
            cout << "Nhap Mat Khau ";
            fflush(stdin);
            getline(cin,MatKhau);
            (this->p + i)->setHoTen(HoTen);
            (this->p + i)->setNgaySinh(NgaySinh);
            (this->p + i)->setQueQuan(QueQuan);
            (this->p + i)->setSDT(SoDienThoai);
            (this->p + i)->setSoCMT(SoCMT);
            (this->p + i)->setChucVu(ChucVu);
            (this->p + i)->setPhanQuyen(PhanQuyen);
            (this->p + i)->setTaiKhoan(TaiKhoan);
            (this->p + i)->setMatKhau(MatKhau);
        }
    }
    else cout << "Khong Tim Thay Ma Phim Can Sua!";
    cout << endl;
}
void QuanLyNhanVien::Delete_NV(string m)
{
    int f = checkMSNV(m);
    if (f >= 0)
    {
        if (this->n == 1)
        {
            delete[] this->p;
            this->p = nullptr;
        }
        else
        {
            NhanVien *temp = new NhanVien[this->n];
            for (int k = 0; k < this->n; k++)
            {
                *(temp + k) = *(this->p + k);
            }
            delete[] this->p;
            this->p = new NhanVien[this->n - 1];
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

int QuanLyNhanVien::TimTaiKhoan(string tk, string mk){
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if(tk == (this->p + i)->getTaiKhoan() && mk == (this->p + i)->getMatKhau()){
            index = i;
            break;
        }
    }
    return index;
}


NhanVien& QuanLyNhanVien::operator[](const int& index){
    static NhanVien temp;
    if(index >=0 && index < this->n){
        return *(this->p + index);
    }
    else return temp;
}

// Menu

void QuanLyNhanVien::Menu(){
    system("cls");

    cout << endl;
    cout << "1.Xem Danh Sach Nhan Vien" << endl;
    cout << "2.Them Nhan Vien" << endl;
    cout << "3.Xoa Nhan Vien" << endl;
    cout << "4.Cap Nhat Nhan Vien" << endl;
    int chon;
    cout << "Nhap Lua Chon: ";
    cin >> chon;
    switch (chon)
    {
    case 1:
        system("cls");
        this->Show();
        XemThongTinNhanVien();
        cout << "3.Tro Ve Menu Chinh" << endl;
        break;
    case 2:
        this->ThemNhanVien();
        break;
    case 3:
        this->XoaNhanVien();
        break;
    case 4:
        this->CapNhatNhanVien();
        break;
    default:
        break;
    }
}

void QuanLyNhanVien::ThemNhanVien(){
    system("cls");
    this->Show();
    cout << "Them Mot Nhan Vien: " << endl;
    NhanVien temp;
    cin >> temp;
    this->Add_NV(temp);    
    cout << "Them Thanh Cong" << endl;
    int chon;
    cout << "1.Them Nhan Vien" << endl;
    cout << "2.Tro Ve" << endl;
    cout << "Nhap Lua Chon" << endl;
    cin >> chon;
    switch (chon)
    {
    case 1:
        ThemNhanVien();
        break;
    case 2:
        this->Menu();
        break;
    default:
        this->Menu();
        break;
    }
}

void QuanLyNhanVien::CapNhatNhanVien(){
    system("cls");
    this->Show();
    string ma;
    cout << "Nhap Ma Nhan Vien Ban Muon Cap Nhat: ";
    cin >> ma;
    int index = checkMSNV(ma);
    if(index == -1){
        cout << "Khong Co Ma Nhan Vien Nao Trung Khop" << endl;
        int chon2;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon2;
        if(chon2 == 1){
            this->CapNhatNhanVien();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Update_NV(ma);
        cout << "Cap Nhat Nhan Vien Thanh Cong!!\n" << endl;
        int chon3;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon3;
        if(chon3 == 1){
            this->CapNhatNhanVien();
        }
        else{
            this->Menu();
        }
    }
}


void QuanLyNhanVien::XoaNhanVien(){
    system("cls");
    this->Show();
    string ma;
    cout << "Nhap Ma Nhan Vien Ban Muon Xoa: ";
    cin >> ma;
    int index = checkMSNV(ma);
    if(index == -1){
        cout << "Khong Co Ma Nhan Vien Nao Trung Khop" << endl;
        int chon2;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon2;
        if(chon2 == 1){
            this->XoaNhanVien();
        }
        else{
            this->Menu();
        }
    }
    else {
        this->Delete_NV(ma);
        cout << "Xoa Nhan Vien Thanh Cong!!\n" << endl;
        int chon3;
        cout << "1.Xoa Nhan Vien" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon3;
        if(chon3 == 1){
            this->XoaNhanVien();
        }
        else{
            this->Menu();
        }
    }
}
void QuanLyNhanVien::XemThongTinNhanVien(){
    system("cls");
    this->Show();
    string ma;
    cout << "Nhap Ma Nhan Vien Ban Muon Xem: ";
    cin >> ma;
    int index = checkMSNV(ma);
    if(index == -1){
        cout << "Khong Co Ma Nhan Vien Nao Trung Khop" << endl;
        int chon2;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon2;
        if(chon2 == 1){
            this->XemThongTinNhanVien();
        }
        else if(chon2 == 2){
            this->Show();
        }
    }
    else {
        (this->p + index)->Display2();
        int chon3;
        cout << "1.Xem Thong Tin Nhan Vien" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> " << endl;
        cin >> chon3;
        if(chon3 == 1){
            this->XemThongTinNhanVien();
        }
        else if(chon3 == 2){
            this->Show();
        }
    }
}