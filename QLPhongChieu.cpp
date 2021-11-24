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
    this->n = 0;
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
    int t_color=1;
    int b_color=0;
    int x=whereX();
    int y=whereY();
  	cout<<endl;
    cout << setw(26) << left << " Ma Phong Chieu" <<char(179);
    cout << setw(20) << left << " So Ghe:" <<char(179);
    cout << setw(20) << left << " May Chieu:" <<char(179);
    cout << setw(20) << left << " Am Thanh:" <<char(179);
    cout << setw(20) << left << " Dien Tich:" <<char(179);
    cout << setw(20) << left << " Tinh Trang:" <<char(179);
    cout << setw(20) << left << " Ma Bao Ve:";
    int x1=whereX();
    box(x,y,x1,2,t_color,b_color);
    cout<<endl<<endl;
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


PhongChieu& QLPhongChieu::operator[](const int& index){
    static PhongChieu temp;
    if(index >=0 && index < this->n){
        return *(this->p + index);
    }
    else return temp;
}

// Menu


void QLPhongChieu::Menu(){
    system("cls");

    vector<string> m={
     "1.Xem Danh Sach Phong Chieu",
     "2.Them Phong Chieu",
     "3.Xoa Phong Chieu",
     "4.Cap Nhat Phong Chieu",
     "5.Tro Ve Menu Chinh"};
    int chon=menu(m);
    switch (chon)
    {
    case 1:
        system("cls");
        this->Show();
        int chon2;
        SetColor(0,3);
        cout << "\n\n1.Xem Thong Tin Chi Tiet" << endl;
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
            system("cls");
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
    SetColor(0,3);
    cout << "Them Mot PhongChieu: " << endl;
    PhongChieu temp;
    SetColor(0,5);
    cin >> temp;
    this->Add_PC(temp); 
    SetColor(0,14);   
    cout << "Them Thanh Cong" << endl;
    int chon;
    SetColor(0,15);
    cout << "1.Them PhongChieu" << endl;
    cout << "2.Tro Ve" << endl;
    SetColor(0,9);
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
    SetColor(0,3);
    cout << "Nhap Ma PhongChieu Ban Muon Cap Nhat: ";
    SetColor(0,5);
    cin >> ma;
    int index = checkMSPC(ma);
    if(index == -1){
        SetColor(0,4);
        cout << "Khong Co Ma PhongChieu Nao Trung Khop" << endl;
        int chon2;
        SetColor(0,15);
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
        this->Update_PC(ma);
        SetColor(0,14);
        cout << "Cap Nhat PhongChieu Thanh Cong!!\n" << endl;
        int chon3;
        SetColor(0,15);
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
    SetColor(0,3);
    cout << "Nhap Ma Phong Chieu Ban Muon Xoa: ";
    SetColor(0,8);
    cin >> ma;
    int index = checkMSPC(ma);
    if(index == -1){
        SetColor(0,14);
        cout << "Khong Co Ma Phong Chieu Nao Trung Khop" << endl;
        int chon2;
        SetColor(0,15);
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
        this->Delete_PC(ma);
        SetColor(0,14);
        cout << "Xoa PhongChieu Thanh Cong!!\n" << endl;
        int chon3;
        SetColor(0,15);
        cout << "\n1.Xoa PhongChieu" << endl;
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
    SetColor(0,3);
    cout << "Nhap Ma Phong Chieu Ban Muon Xem: ";
    SetColor(0,8);
    cin >> ma;
    int index = checkMSPC(ma);
    if(index == -1){
        SetColor(0,4);
        cout << "Khong Co Ma Phong Chieu Nao Trung Khop" << endl;
        int chon2;
        SetColor(0,15);
        cout << "1.Nhap Lai" << endl;
        cout << "2.Tro Ve" << endl;
        cout << ">> ";
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
        SetColor(0,15);
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