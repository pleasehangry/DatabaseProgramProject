
#include "User.h"
QuanLyPhim QLP;
QuanLyNhanVien QLNV;
vector<Customer> CTM;
QLPhongChieu QLPC;
QuanLyLichChieu QLLC;
QuanLyVe QLV;
int SoKhach;


// void Menu_DangNhap();
// void User(int index);
// void ThanhToan(int index, int indexmave, int SoVe);
// void DoiMatKhau(int index);


void thanhcong()
{
    CanLe();
	cout << "------------------" << endl;
	SetColor(0, 9);
    CanLe();
	cout << " Yeu cau cua ban da duoc thuc hien" << endl;
	intime();
	SetColor(0, 7);
    CanLe();
	cout << "------------------" << endl;
}


void InVe(vector<int>A, int indexPhim, int indexPC, int indexLichChieu, int indexMave){
    ofstream inve;
    inve.open("Titket.txt", ios::trunc);
    inve << get_day() << "    " << get_time() << endl;
    inve << QLP[indexPhim].getTenPhim() << endl;
    inve << "Ngay:" << QLLC[indexLichChieu].getNgay() << "   Gio Chieu:" << QLLC[indexLichChieu].getGio()<< "   ";
    inve << QLPC[indexPC].getMaPhongChieu() << endl;
    inve << "Ghe Da Dat: ";
    for (int i = 0; i < A.size(); i++)
    {
        inve << A[i] << " ";
    }
    inve << "     So Tien: " << QLV[indexMave].getGiaLoaiVe()*A.size();
    inve << endl;
    inve << "Cam On Ban Da Su Dung Dich Vu Cua Chung Toi!";
    inve.close();
}


void DatVe(int index){
    string maPhim,maXuatChieu;
    // DocFile(QLNV, QLP, QLLC, QLPC, QLV, CTM, SoKhach);
    int SoVe;
    CanLe();
    cout << "Nhap Ma Phim Ban Muon Dat Ve: ";
    cin >> maPhim;
    int indexMaphim = QLP.CheckMS(maPhim);
    while(indexMaphim<0){
        CanLe();
        cout << "Khong Co Ma Phim Nao Trung Khop, Xin Nhap Lai: ";
        cin >> maPhim;
    }
    system("cls");
    QLLC.XemLichChieuCuaPhim(QLP[indexMaphim].getTenPhim());
    CanLe();
    cout << "Nhap Ma Xuat Chieu: ";
    cin >> maXuatChieu;
    while(QLLC.CheckMS(maXuatChieu) < 0){
        CanLe();
        cout << "Khong Co Ma Xuat Chieu Nao Trung Khop, Xin Nhap Lai: ";
        cin >> maXuatChieu;
    }
    int k = QLLC.CheckMS(maXuatChieu);
    string a = QLLC[k].getPhongChieu();
    int h = QLPC.CheckMS(a);
    system("cls");
    GoTo(5,3);
    cout << "Ban Muon Dat Bao Nhieu Ve? ";
    cin >> SoVe;
    string loaikhachhang = CTM[index].LoaiKhachHang;
    int indexmave = QLV.GetMaVe(maPhim, loaikhachhang);
    QLV[indexmave].ThemSoVeDaBan(SoVe);
    UpdateFile_Ve(QLV);
    QLPC[h].DisplayTable();
    vector<int> A;
    int ghe;
    for(int i = 0; i < SoVe; i++){
        CanLe();
        cout << "Nhap Ghe Ma Ban Muon Dat: ";
        cin >> ghe;
        A.push_back(ghe);
        QLPC[h].GhiFileDatGhe(ghe);
    }
    // QLPC[h].DatGhe(SoVe);
    
    ThanhToan(index, indexmave, SoVe);
    system("cls");
    GoTo(5,3);
    cout << "Ban Co Muon In Ve Khong?" << endl;
    vector<string> m1 = {"Co","Khong"};
    int In = menu2(m1);
    switch (In)
    {
    case 1:
        InVe(A,indexMaphim,h,k,indexmave);
        thanhcong();
        CanLe();
        cout << "Hay Kiem Tra Ve Cua Ban O File Titket.txt" << endl;
        break;
    case 2:
        CanLe();
        cout << "Cam On Ban Da Gop Phan Bao Ve Moi Truong <3" << endl;
    default:
        break;
    }
    CanLe();
    cout << "Dat Ve Hoan Tat!!" << endl;
    vector<string> m2 = {"Dat Them Ve","Tro Ve Man Hinh Chon"};
    int chon2 = menu2(m2);
    switch (chon2)
    {
    case 1:
        QLP.Show();
        DatVe(index);
        break;
    case 2:
        User(index);
    default:
        break;
    }
}

void ThanhToan(int index, int indexmave, int SoVe){
    DocFile_Khach(CTM,SoKhach);
    CanLe();
    cout << "Ban Muon Thanh Toang Bang Gi: " << endl;
    vector<string> m1 = {"Thanh Toan Bang The","Thanh Toan Bang Tien Mat"};

    int thanhtoan = menu2(m1);
    switch (thanhtoan)
    {
    case 1:
        if(CTM[index].CheckSoDu(QLV[indexmave].getGiaLoaiVe()*SoVe)){
            CanLe();
            cout << "Thanh Toan Thanh Cong!" << endl;
            UpdateFile_Khach(CTM,SoKhach);
        }
        else{
            CanLe();
            cout << "So Du Cua Ban Khong Du!" << endl;
            vector<string> m2 = {"Nap Tien","Thanh Toan Bang Tien Mat"};
            int thanhtoan2 = menu2(m2);
            switch (thanhtoan2)
            {
            case 1:
                CTM[index].NapTien();
                if(CTM[index].CheckSoDu(QLV[indexmave].getGiaLoaiVe()*SoVe)){
                    CanLe();
                    cout << "Thanh Toan Thanh Cong!" << endl;
                    UpdateFile_Khach(CTM,SoKhach);
                }
                break;
            case 2:
                CanLe();
                cout << "Da Thanh Toan Bang Tien Mat!" << endl;
                break;
            default:
                break;
            }
        }
        break;
    case 2:
        CanLe();
        cout << "Da Thanh Toan Bang Tien Mat!" << endl;
        break;
    default:
        break;
    }
    CanLe();
    cout << "Nhan Phim Ban Ki De Tiep Tuc" << endl;
    getch();
}


int TimTaiKhoan(string tk, string mk){
    DocFile_Khach(CTM,SoKhach);
    int index = -1;
    for (int i = 0; i < CTM.size(); i++)
    {
        if(CTM[i].checkTaiKhoan(tk,mk)){
            index = i;
            break;
        }
    }
    return index;
}



void User(int index)
{
    DocFile(QLNV, QLP, QLLC, QLPC, QLV, CTM, SoKhach);
    vector<string> me = {"Dat Ve","Tro Ve"};
    vector<string> mm4 = {"Nap Tien","Tro Ve"};
    system("cls");
    SetColor(0,2);
    GoTo(70,2);
    cout<<"Dang Nhap Thanh Cong!"<<endl;
    SetColor(0,7);
    GoTo(70,3);
    cout<<"Xin Chao ";
    SetColor(0,9);
    cout << CTM[index].HoTen;
    SetColor(0,14);
    vector<string> m = {"Xem Hom Nay Co Phim Gi", "Tim Kiem Phim", "Tim Kiem Phim Theo The Loai", "Doi Mat Khau", "Xem Thong Tin Ca Nhan", "Dang Xuat"};
    SetColor(0,7);

    int ma = menu(m);
    switch(ma)
    {
        case 1:
        int lenh;
        system("cls");
        QLP.Show();
        lenh = menu2(me);
            switch (lenh)
            {
            case 1:
                DatVe(index);
                break;
            case 2:
                system("cls");
                User(index);
                break;
            default:
                break;
            }
        break;
        case 2:
            QLP.TimKiemPhim();
            CanLe();
             cout<<"----------------------" << endl;
            SetColor(0,14);
            int lenh2;
            lenh2 = menu2(me);
            SetColor(0,7);
            switch (lenh2)
            {
            case 2:
                User(index);
                break;
            case 1:
                DatVe(index);
                break;
            default:
                break;
            }
            break;
        case 3:
            int Lenh4;
            QLP.XemTheloaiPhim();
            QLP.XemDSPhimCuaTheLoai();
            Lenh4 = menu2(me);
            SetColor(0,7);
            switch (Lenh4)
            {
            case 2:
                User(index);
                break;
            case 1:
                DatVe(index);
                break;
            default:
                break;
            }
            break;
        case 4:
            DoiMatKhau(index);
            break;
        case 5:
            CTM[index].Show2();
            int naptien;
            naptien = menu2(mm4);
                switch (naptien)
                {
                case 1: 
                    CTM[index].NapTien();
                    break;
                case 2:
                    User(index);
                    break;
                default:
                    break;
                }
            break;
        default:
            DangNhap_Khach();
            break;
    } 
} 


void DangNhap(){
    string gmail,mk;
    system("cls");
    GoTo(80,5);
    cout << "Nhap Gmail: ";cin >> gmail;
    
    GoTo(80,7);
    cout << "Nhap Mat Khau: ";cin >> mk;
    
    int index = TimTaiKhoan(gmail,mk);
    if(gmail == "0"){
        DangNhap_Khach();
    }
    if(index == -1){
        system("cls");
        GoTo(80,9);
        cout << "Tai Khoan Hoac Mat Khau Khong Dung!";
        DangNhap();
    }
    else{
        User(index);
    }
}

void DangKy(){
    system("cls");
    DocFile_Khach(CTM,SoKhach);
    string gmail, mk, mk2, ten;
    GoTo(80,5);
    cout << "Nhap Gmail Cua Ban: ";cin >> gmail;
    
    GoTo(80,7);
    cout << "Nhap Mat Khau: ";cin >> mk;
    
    GoTo(80,9);
    cout << "Nhap Lai Mat khau: ";cin >> mk2;
    
    for (int i = 0; i < CTM.size(); i++)
    {
        if(gmail == CTM[i].getGmail()){
            system("cls");
            GoTo(80,7);
            cout << "Tai Khoan Da Ton Tai" << endl;
            getch();
            DangKy();
            break;
        }
    }
    
    while(mk!=mk2){
        system("cls");
        GoTo(80,5);
        cout << "(Nhan 0 De Thoat)" << endl;
        GoTo(80,7);
        cout << "Mat Khau Khong Trung Khop" << endl;
        GoTo(80,9);
        cout << "Nhap Gmail Cua Ban: " << gmail << endl;
        GoTo(80,11);
        cout << "Nhap Mat Khau:"; cin >> mk;
        if(mk == "0"){
            DangNhap_Khach();
        }
        GoTo(80,13);
        cout << "Nhap Lai Mat Khau: ";cin >> mk2;
        
    }
    system("cls");
    GoTo(80,7);
    cout << "Nhap Ho Ten Cua Ban: ";cin >> ten;
    
    Customer temp(gmail,mk,ten);
    CTM.push_back(temp);
    SoKhach++;
    UpdateFile_Khach(CTM, SoKhach);
    GoTo(80,9);
    cout << "Dang Ky Thanh Cong"<< endl;
    GoTo(80,11);
    cout << "Nhan Phim Bat Ky De Tro Ve";
    getch();
    DangNhap_Khach();
}

void DoiMatKhau(int index){
    system("cls");
    DocFile_Khach(CTM, SoKhach);
    string mkc,mkm,mkm2;
    GoTo(5,3);
    cout << "Nhap Mat Khau Cu:";cin >> mkc;
    
    CanLe();
    cout << "Nhap Mat Khau Moi:";cin >> mkm;
    
    CanLe();
    cout << "Nhap Lai Mat Khau Moi:";cin >> mkm2;
    if(mkc != CTM[index].getMatKhau()){
        CanLe();
        cout << "Mat Khau Cu Khong Chinh Xac!" << endl;
        getch();
        DoiMatKhau(index);
    } else{
        while(mkm!=mkm2){
            CanLe();
            cout << "Mat Khau Moi Khong Trung Khop!" << endl;
            getch();
            system("cls");
            CanLe();
            cout << "Nhap Mat Khau Cu: " << mkc << endl;
            CanLe();
            cout << "Nhap Mat Khau Moi:";cin >> mkm;
            CanLe();
            cout << "Nhap Lai Mat Khau Moi:";cin >> mkm2;
        }
    }
    CTM[index].setMatKhau(mkm);
    UpdateFile_Khach(CTM, SoKhach);
    CanLe();
    cout << "Doi Mat Khau Thanh Cong!" << endl;
    CanLe();
    cout << "Nhap Phim Bat Ky De Tro Ve" << endl;
    getch();
    User(index);
}


void DangNhap_Khach(){
    int chon;
    system("cls");
    vector<string> m = {"Dang Nhap","Dang Ky","Thoat"};
    chon = menu(m);
    switch (chon)
    {
    case 1:
        DangNhap();
        break;
    case 2:
        DangKy();
        break;
    case 3:
        exit(1);
    default:
        break;
    }
}