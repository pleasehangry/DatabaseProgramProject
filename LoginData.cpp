#include "LoginData.h"
#include<conio.h>
#include "DoHoa.h"


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
    CanLe();
    cout << "Nhap So Tai Khoan Ngan Hang: ";
    cin >> SoTaiKhoan;
    CanLe();
    cout << "Nhap So Tien Ban Muon Nap: ";
    cin >> SoTien;
    if(SoTien <0) cout << "So Tien Khong Hop Le\n" << endl;
    else {
        this->SoDu += SoTien;
        CanLe();
        cout << "Nap Tien Thanh Cong!" << endl;
    }
    CanLe();
    cout << "Nhan Phim Bat Ky De Tro Ve";
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
    cout <<(char)197<< setw(30-1) << left << this->HoTen <<(char)197;
    cout << setw(30-1) << left << this->Gmail <<(char)197;
    cout << setw(20-1) << left << this->MatKhau <<(char)197;
    cout << setw(10-1) << left << this->SoDu <<(char)197;
    cout << setw(20-1) << left << this->LoaiKhachHang<<(char)197<< endl;
}
void Customer::Show2(){
    system("cls");
    GoTo(5,3);
    CanLe();
    cout<< "Ho Ten: " << this->HoTen << endl;
    CanLe();
    cout<< "Gmail " << this->Gmail << endl;
    CanLe();
    cout<< "Mat Khau: " << this->MatKhau << endl;
    CanLe();
    cout<< "SoDu: " << this->SoDu << endl;
    CanLe();
    cout<< "Loai Khach Hang: " << this->LoaiKhachHang<< endl;
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
void TieuDeCot()
{
    int t_color=1;
    int b_color=0;
    int x=whereX();
    int y=whereY();
  	cout<<endl;
    CanLe();
    cout << setw(30) << left << " Ho ten" << (char)197; 
    cout << setw(30-1) << left << "Tai Khoan" << (char)197; 
    cout << setw(20-1) << left << "Mat Khau" << (char)197;
    cout << setw(10-1) << left << "So Du" << (char)197;
    cout << setw(20-1) << left << "Loai Khach Hang"; 
    int x1=whereX();
    box(x,y,x1-5,2,t_color,b_color);
    cout<<endl; 

}
void Display(vector<Customer>& CTM,int& SoKhach){
    GoTo(5,3);
    TieuDeCot();
    CanLe();
    int x1=whereX();
    int y1=whereY();
    cout<<endl;
    for (int i = 0; i < CTM.size(); i++)
    {
        CanLe();
        CTM[i].Show();
    }
    int y=whereY();
    box(x1,y1,110,y-5,1,0);
    GoTo(x1,y+1); 
}

void ThemNguoiDung(vector<Customer>& CTM,int& SoKhach){
    system("cls");
    string gmail, mk, mk2, ten;
    GoTo(5,3);
    cout << " Nhap Gmail Cua Ban: ";
    cin >> gmail;
    CanLe();
    cout << " Nhap Mat Khau: ";
    cin >> mk;
    CanLe();
    cout << " Nhap Lai Mat khau: ";
    cin >> mk2;
    for (int i = 0; i < CTM.size(); i++)
    {
        if(gmail == CTM[i].getGmail()){
            CanLe();
            cout << "Tai Khoan Da Ton Tai" << endl;
            break;
            getch();
            ThemNguoiDung(CTM, SoKhach);
        }
    }
    
    while(mk!=mk2){
        system("cls");
        GoTo(5,3);
        cout << "(Nhan 0 De Thoat)" << endl;
        CanLe();
        cout << "Mat Khau Khong Trung Khop" << endl;
        CanLe();
        cout << "\nNhap Gmail Cua Ban: " << gmail << endl;
        CanLe();
        cout << "Nhap Mat Khau:(Nhan 0 De Thoat)";
        if(mk == "0"){
            Menu_Khach(CTM, SoKhach);
        }
        cin >> mk;
        SetColor(0,7);
        CanLe();
        cout << "Nhap Lai Mat Khau: ";
        cin >> mk2;
    }
    SetColor(0,15);
    CanLe();
    cout << "Nhap Ho Ten Cua Ban: ";
    SetColor(0,8);
    cin >> ten;
    Customer temp(gmail,mk,ten);
    CTM.push_back(temp);
    SoKhach++;
    SetColor(0,14);
    SetColor(0,14);
    CanLe();
    cout << "Them Thanh Cong! " << endl;
    vector<string> m2 = {"Them Nguoi Dung", "Tro Ve"};
    SetColor(0,15);
    CanLe();
    int chon2 = menu2(m2);
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
    system("cls");
    Display(CTM,SoKhach);
    string ma;
    vector<string> m2 = {"Nhap lai", "Tro Ve"};
    SetColor(0,3);
    CanLe();
    cout << "Nhap Tai Khoan Gmail Ban Muon Xoa: "; cin >> ma;
    int k = CheckGmail(CTM,ma);
    if(k == -1){
        SetColor(0,4);
        CanLe();
        cout << "Khong Co Tai Khoan Nao Trung Khop" << endl;
        int chon;
        SetColor(0,15);
        chon = menu2(m2);
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
        SetColor(0,14);
        CanLe();
        cout << "Xoa Thanh Cong" << endl;
        SetColor(0,15);
        chon2 = menu2(m2);
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
    system("cls");
    Display(CTM,SoKhach);
    vector<string> m2 = {"Nhap lai", "Tro Ve"};
    string ma;
    SetColor(0,3);
    CanLe();
    cout << "Nhap Tai Khoan Gmail Ban Muon Sua Doi"; 
    SetColor(0,15);
    cin >> ma;
    int k = CheckGmail(CTM,ma);
    if(k == -1){
        SetColor(0,4);
        CanLe();
        cout << "Khong Co Tai Khoan Nao Trung Khop" << endl;
        int chon;
        SetColor(0,15);
        chon = menu2(m2);
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
        CanLe();
        cout << "Nhap Gmail Moi: "; cin >> gmail;
        CanLe();
        cout << "Nhap Mat Khau Moi: "; cin >> mk;
        CanLe();
        cout << "Nhap Loai Khach Hang: "; cin >> loaikhachhang;
        CanLe();
        cout << "Nhap Ho Ten: "; cin >> hoten;
        CanLe();
        cout << "Nhap So Du Moi: "; cin >> sodu;
        CTM[k].setGmail(gmail);
        CTM[k].setMatKhau(mk);
        CTM[k].setSoDu(sodu);
        CTM[k].LoaiKhachHang = loaikhachhang;
        CTM[k].HoTen = hoten;

        SoKhach--;
        int chon2;
        SetColor(0,14);
        CanLe();
        cout << "Sua Doi Thong Tin Nguoi Dung Thanh Cong" << endl;
        SetColor(0,15);
        chon2 = menu2(m2);
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
    system("cls");
    Display(CTM,SoKhach);
    string ma;
    vector<string> m2 = {"Nhap lai", "Tro Ve"};
    SetColor(0,3);
    CanLe();
    cout << "Nhap Tai Khoan Gmail Ban Muon Nap Tien"; 
    SetColor(0,15);
    cin >> ma;
    int k = CheckGmail(CTM,ma);
    if(k == -1){
        SetColor(0,4);
        CanLe();
        cout << "Khong Co Tai Khoan Nao Trung Khop" << endl;
        int chon;
        SetColor(0,15);
        chon = menu2(m2);
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
        SetColor(0,15);
        chon2 = menu2(m2);
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
    vector<string> m2 = {"Tim Kiem Nguoi Dung", "Tro Ve"};
    SetColor(0,3);
    CanLe();
    cout << "Nhap Ten Nguoi Dung Ban Muon Tim: "; 
    SetColor(0,15);
    fflush(stdin);
    getline(cin,s);
    cout << endl;
    int k = 0;
    CanLe();
    TieuDeCot();
    int x1=whereX();
    int y1=whereY();
    cout << endl;
    for (int i = 0; i < CTM.size(); i++)
    {
        if(strstr(CTM[i].HoTen.c_str(),s.c_str())){
            CanLe();
            SetColor(0,3);
            CTM[i].Show();
            k++;
        }
    } 
    if(k==0){
        system("cls");
        SetColor(0,4);
        CanLe();
        int chon1;
        cout << "Khong Tim Thay" << endl;
        chon1 = menu2(m2);
        switch (chon1)
        {
        case 1:
            TimKiemNguoiDung(CTM, SoKhach);
            break;
        default:
            Menu_Khach(CTM, SoKhach);
            break;
        }
    }
        int chon2;
        SetColor(0,15);
        CanLe();
        chon2 = menu2(m2);
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
    vector<string> m2 = {"Tim Kiem Nguoi Dung", "Tro Ve"};
    cout << endl;
    vector<string> m =
     {"1.Xem Danh Sach Nguoi Dung",
     "2.Them Nguoi Dung",
     "3.Xoa Nguoi Dung" ,
     "4.Cap Nhat Thong Tin Nguoi Dung" ,
     "5.Nap Tien Cho Nguoi Dung" ,
     "6.Tim Kiem Nguoi Dung" ,
     "7.Thoat" };
    SetColor(0,7);
    int chon = menu(m);
    
    switch (chon)
    {
    case 1:
        system("cls");
        Display(CTM,SoKhach);
        int chon3;
        SetColor(0,15);
        chon3 = menu2(m2);
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