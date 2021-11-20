#include "LoginData.h"
#include<conio.h>


Customer::Customer(string Gmail, string MatKhau,string HoTen, int SoDu)
{
    this->SoDu = SoDu;
    this->Gmail = Gmail;
    this->MatKhau = MatKhau;
    this->HoTen = HoTen;
    if(SoDu > 1000000){
        this->LoaiKhachHang = "Vip";
    }
    else{
        this->LoaiKhachHang = "Member";
    }
}

Customer::~Customer()
{
}


void Customer::setGmail(string Gmail){
    this->Gmail = Gmail;
}

void Customer::setMatKhau(string MatKhau){
    this->MatKhau = MatKhau;
}

string Customer::getGmail(){
    return this->Gmail;
}

string Customer::getMatKhau(){
    return this->MatKhau;
}

void Customer::setSoDu(int SoDu){
    this->SoDu = SoDu;
}
int Customer::getSoDu(){
    return this->SoDu;
}

bool Customer::CheckSoDu(int giave){
    if(this->SoDu > giave){
        this->SoDu -= giave;
        return true;
    }
    return false;
}

void Customer::NapTien(){
    int SoTaiKhoan;
    int SoTien;
    cout << "Nhap So Tai Khoan Ngan Hang: ";
    cin >> SoTaiKhoan;
    cout << "Nhap So Tien Ban Muon Nap: ";
    cin >> SoTien;
    if(SoTien <0) cout << "So Tien Khong Hop Le" << endl;
    else {
        this->SoDu += SoTien;
        cout << "Nap Tien Thanh Cong!" << endl;
    }
    cout << "\nNhan Phim Bat Ky De Tro Ve";
    getch();
}

bool Customer::checkTaiKhoan(string gmail, string mk){
    if(this->Gmail == gmail && this->MatKhau == mk){
        return true;
    }
    return false;
}

Customer& Customer::operator=(const Customer& c){
    this->Gmail = c.Gmail;
    this->MatKhau = c.MatKhau;
    this->HoTen = c.HoTen;
    this->LoaiKhachHang = c.LoaiKhachHang;
    this->SoDu = c.SoDu;
    return *this;
}





void Customer::Show(){
    cout << setw(30-1) << left << this->HoTen << "| ";
    cout << setw(30-1) << left << this->Gmail << "| ";
    cout << setw(20-1) << left << this->MatKhau << "| ";
    cout << setw(10-1) << left << this->SoDu << "| ";
    cout << setw(20-1) << left << this->LoaiKhachHang<< endl;
}




//================================== Quan Ly Nguoi Dung 


int CheckGmail(vector<Customer>& CTM, string m ){
    int index = -1;
    for (int i = 0; i < CTM.size(); i++)
    {
        if(CTM[i].getGmail() == m){
            index = i;
            break;
        }
    }
    return index;
}


// void Display(vector<Customer>& CTM,int& SoKhach);
// void ThemNguoiDung(vector<Customer>& CTM,int& SoKhach);
// void XoaNguoiDung(vector<Customer>& CTM,int& SoKhach);
// void CapNhatNguoiDung(vector<Customer>& CTM,int& SoKhach);
// void NapTienNguoiDung(vector<Customer>& CTM,int& SoKhach);
// void TimKiemNguoiDung(vector<Customer>& CTM,int& SoKhach);

void Menu_Khach(vector<Customer>& CTM,int& SoKhach);

void Display(vector<Customer>& CTM,int& SoKhach){
    cout << setw(30-1) << left << "Ho ten" << "| "; 
    cout << setw(30-1) << left << "Tai Khoan" << "| "; 
    cout << setw(20-1) << left << "Mat Khau" << "| "; 
    cout << setw(10-1) << left << "So Du" << "| ";
    cout << setw(20-1) << left << "Loai Khach Hang" << endl; 
    for (int i = 0; i < CTM.size(); i++)
    {
        CTM[i].Show();
    }
}

void ThemNguoiDung(vector<Customer>& CTM,int& SoKhach){
    system("cls");
    string gmail, mk, mk2, ten;
    cout << "Nhap Gmail Cua Ban: ";
    cin >> gmail;
    cout << "Nhap Mat Khau: ";
    cin >> mk;
    cout << "Nhap Lai Mat khau: ";
    cin >> mk2;
    for (int i = 0; i < CTM.size(); i++)
    {
        if(gmail == CTM[i].getGmail()){
            cout << "Tai Khoan Da Ton Tai" << endl;
            break;
            getch();
            ThemNguoiDung(CTM, SoKhach);
        }
    }
    
    while(mk!=mk2){
        system("cls");
        cout << "(Nhan 0 De Thoat)" << endl;
        cout << "Mat Khau Khong Trung Khop" << endl;
        cout << "\nNhap Gmail Cua Ban: " << gmail << endl;
        cout << "Nhap Mat Khau:(Nhan 0 De Thoat)";
        if(mk == "0"){
            Menu_Khach(CTM, SoKhach);
        }
        cin >> mk;
        cout << "Nhap Lai Mat Khau: ";
        cin >> mk2;
    }
    cout << "Nhap Ho Ten Cua Ban: ";
    cin >> ten;
    Customer temp(gmail,mk,ten);
    CTM.push_back(temp);
    SoKhach++;
    cout << "Them Thanh Cong! " << endl;
    cout << "1.Them Nguoi Dung" << endl;
    cout << "2.Tro ve" << endl;
    int chon2;
    cout << ">>"; cin >> chon2;
    switch (chon2)
    {
    case 1:
        ThemNguoiDung(CTM, SoKhach);
        break;
    case 2:
        Menu_Khach(CTM, SoKhach);
        break;
    default:
        break;
    }
}


void XoaNguoiDung(vector<Customer>& CTM,int& SoKhach){
    Display(CTM,SoKhach);
    string ma;
    cout << "Nhap Tai Khoan Gmail Ban Muon Xoa"; cin >> ma;
    int k = CheckGmail(CTM,ma);
    if(k == -1){
        cout << "Khong Co Tai Khoan Nao Trung Khop" << endl;
        int chon;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro ve" << endl;
        cout << ">>"; cin >> chon;
        switch (chon)
        {
        case 1:
            XoaNguoiDung(CTM, SoKhach);
            break;
        default:
            Menu_Khach(CTM, SoKhach);
            break;
        }
    }
    else{
        swap(CTM[k],CTM[CTM.size()-1]);
        CTM.pop_back();
        SoKhach--;
        int chon2;
        cout << "Xoa Thanh Cong" << endl;
        cout << "1.Xoa Nguoi Dung" << endl;
        cout << "2.Tro ve" << endl;
        cout << ">>"; cin >> chon2;
        switch (chon2)
        {
        case 1:
            XoaNguoiDung(CTM, SoKhach);
            break;
        default:
            Menu_Khach(CTM, SoKhach);
            break;
        }
    }
}
void CapNhatNguoiDung(vector<Customer>& CTM,int& SoKhach){
    Display(CTM,SoKhach);
    string ma;
    cout << "Nhap Tai Khoan Gmail Ban Muon Sua Doi"; cin >> ma;
    int k = CheckGmail(CTM,ma);
    if(k == -1){
        cout << "Khong Co Tai Khoan Nao Trung Khop" << endl;
        int chon;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro ve" << endl;
        cout << ">>"; cin >> chon;
        switch (chon)
        {
        case 1:
            CapNhatNguoiDung(CTM, SoKhach);
            break;
        case 2:
            Menu_Khach(CTM, SoKhach);
            break;
        default:
            break;
        }
    }
    else{
        string gmail, mk, hoten, loaikhachhang;
        int sodu;
        CTM[k].setGmail(gmail);
        CTM[k].setMatKhau(mk);
        CTM[k].setSoDu(sodu);
        CTM[k].LoaiKhachHang = loaikhachhang;
        CTM[k].HoTen = hoten;

        SoKhach--;
        int chon2;
        cout << "Sua Doi Thong Tin Nguoi Dung Thanh Cong" << endl;
        cout << "1.Xoa Nguoi Dung" << endl;
        cout << "2.Tro ve" << endl;
        cout << ">>"; cin >> chon2;
        switch (chon2)
        {
        case 1:
            CapNhatNguoiDung(CTM, SoKhach);
            break;
        default:
            Menu_Khach(CTM, SoKhach);
            break;
        }
    }
}
void NapTienNguoiDung(vector<Customer>& CTM,int& SoKhach){
    Display(CTM,SoKhach);
    string ma;
    cout << "Nhap Tai Khoan Gmail Ban Muon Nap Tien"; cin >> ma;
    int k = CheckGmail(CTM,ma);
    if(k == -1){
        cout << "Khong Co Tai Khoan Nao Trung Khop" << endl;
        int chon;
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro ve" << endl;
        cout << ">>"; cin >> chon;
        switch (chon)
        {
        case 1:
            NapTienNguoiDung(CTM, SoKhach);
            break;
        case 2:
            Menu_Khach(CTM, SoKhach);
            break;
        default:
            break;
        }
    }
    else{
        CTM[k].NapTien();
        int chon2;
        cout << "1.Nap Tien Nguoi Dung" << endl;
        cout << "2.Tro ve" << endl;
        cout << ">>"; cin >> chon2;
        switch (chon2)
        {
        case 1:
            NapTienNguoiDung(CTM, SoKhach);
            break;
        default:
            Menu_Khach(CTM, SoKhach);
            break;
        }
    }
}
void TimKiemNguoiDung(vector<Customer>& CTM,int& SoKhach){
    system("cls");
    Display(CTM,SoKhach);
    string s;
    cout << "   Nhap Ten Nguoi Dung Ban Muon Tim: ";  cin >> s;
    cout << endl;
    int k = 0;
    for (int i = 0; i < CTM.size(); i++)
    {
        if(strstr(CTM[i].HoTen.c_str(),s.c_str())){
            CTM[i].Show();
            k++;
        }
    }
    if(k==0){
        system("cls");
        cout << "Khong Tim Thay" << endl;
    }
        int chon2;
        cout << "1.Tiem Kiem Nguoi Dung" << endl;
        cout << "2.Tro ve" << endl;
        cout << ">>"; cin >> chon2;
        switch (chon2)
        {
        case 1:
            TimKiemNguoiDung(CTM, SoKhach);
            break;
        default:
            Menu_Khach(CTM, SoKhach);
            break;
        }

}

void Menu_Khach(vector<Customer>& CTM,int& SoKhach){
    system("cls");

    cout << endl;
    cout << "1.Xem Danh Sach Nguoi Dung" << endl;
    cout << "2.Them Nguoi Dung" << endl;
    cout << "3.Xoa Nguoi Dung" << endl;
    cout << "4.Cap Nhat Thong Tin Nguoi Dung" << endl;
    cout << "5.Nap Tien Cho Nguoi Dung" << endl;
    cout << "6.Tim Kiem Nguoi Dung" << endl;
    cout << "7.Thoat" << endl;
    int chon;
    cout << "Nhap Lua Chon: ";
    cin >> chon;
    switch (chon)
    {
    case 1:
        system("cls");
        Display(CTM,SoKhach);
        int chon3;
        cout << "1.Tiem Kiem Nguoi Dung" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">>"; cin >> chon3;
        switch (chon3)
        {
        case 1:
            TimKiemNguoiDung(CTM,SoKhach);
            break;
        default:
            break;
        }
        Menu_Khach(CTM,SoKhach);
        break;
    case 2:
        ThemNguoiDung(CTM, SoKhach);
        break;
    case 3:
        XoaNguoiDung(CTM, SoKhach);
        break;
    case 4:
        CapNhatNguoiDung(CTM, SoKhach);
        break;
    case 5:
        NapTienNguoiDung(CTM,SoKhach);
        break;
    case 6:
        TimKiemNguoiDung(CTM,SoKhach);
        break;
    default:
        break;
    }
}