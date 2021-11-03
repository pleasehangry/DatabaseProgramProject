#include"PhongChieu.h"
PhongChieu::PhongChieu(string MaPhongChieu, int SoCho, string MayChieu, string AmThanh, float DienTich, string TinhTrang, string MaBaoVe){
    this->MaPhongChieu = MaPhongChieu;
    this->SoCho = SoCho;
    this->MayChieu = MayChieu;
    this->AmThanh = AmThanh;
    this->DienTich = DienTich;
    this->TinhTrang = TinhTrang;
    this->MaBaoVe = MaBaoVe;
}

PhongChieu::~PhongChieu(){}

void PhongChieu::setMaPhongChieu(string MaPhongChieu){
    this->MaPhongChieu = MaPhongChieu;    
}
void PhongChieu::setSoCho(int SoCho){
    this->SoCho = SoCho;    
}
void PhongChieu::setMayChieu(string MayChieu){
    this->MayChieu = MayChieu;    
}
void PhongChieu::setAmThanh(string AmThanh){
    this->AmThanh = AmThanh;    
}
void PhongChieu::setDienTich(float DienTich){
    this->DienTich = DienTich;    
}
void PhongChieu::setTinhTrang(string TinhTrang){
    this->TinhTrang = TinhTrang;    
}
void PhongChieu::setMaBaoVe(string MaBaoVe){
    this->MaBaoVe = MaBaoVe;    
}

string PhongChieu::getMaPhongChieu(){
    return this->MaPhongChieu;
}
int PhongChieu::getSoCho(){
    return this->SoCho;
}
string PhongChieu::getMayChieu(){
    return this->MayChieu;
}
string PhongChieu::getAmThanh(){
    return this->AmThanh;
}
float PhongChieu::getDienTich(){
    return this->DienTich;
}
string PhongChieu::getTinhTrang(){
    return this->TinhTrang;
}
string PhongChieu::getMaBaoVe(){
    return this->MaBaoVe;
}


PhongChieu::PhongChieu(const PhongChieu& p){
    this->MaPhongChieu = p.MaPhongChieu;
    this->SoCho = p.SoCho;
    this->MayChieu = p.MayChieu;
    this->AmThanh = p.AmThanh;
    this->DienTich = p.DienTich;
    this->TinhTrang = p.TinhTrang;
    this->MaBaoVe = p.MaBaoVe;
}

void PhongChieu::Display2(){
    cout << "Ma Phong Chieu: " << this->MaPhongChieu << endl;
    cout << "So Ghe: " << this->SoCho << endl;
    cout << "Loai May Chieu: " << this->MayChieu << endl;
    cout << "Loai Am Thanh: " << this->AmThanh << endl;
    cout << "Dien Tich: " << this->DienTich << "met vuong" << endl;
    cout << "Tinh Trang: "  << this->TinhTrang << endl;
    cout << "Ma Bao Ve: " << this->MaBaoVe << endl;
}

void PhongChieu::Display(){
    cout << setw(25) << left << this->MaPhongChieu << "|";
    cout << setw(20) << left << this->SoCho << "|";
    cout << setw(20) << left << this->MayChieu << "|";
    cout << setw(20) << left << this->AmThanh << "|";
    cout << setw(20) << left << this->DienTich << "|";
    cout << setw(20) << left << this->TinhTrang << "|";
    cout << setw(20) << left << this->MaBaoVe << endl;
}

void PhongChieu::DisplayTable(){
    char Chu[100];
    int So[100];
    for (int i = 0; i < sqrt(this->SoCho); i++)
    {
        Chu[i] = 'A'+i;
        So[i] = i+1;
    }

    cout <<"\t\t  Man Hinh Chieu";
    for(int i = 0; i < 5; i++) cout << "________";
    cout << endl;
    for(int i = 0; i < sqrt(this->SoCho); i++){
        for(int j = 0; j < sqrt(this->SoCho); j++){
            cout << Chu[i] << So[j] << "    ";
        }
        cout << endl;
        cout << endl;
    }
}
