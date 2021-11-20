#include "DocFile.h"

void DocFile(QuanLyNhanVien& QLNV,QuanLyPhim& QLP,QuanLyLichChieu& QLLC, QLPhongChieu& QLPC , QuanLyVe& QLV ,vector<Customer>& CTM, int& SoKhach){
    
    DocFile_Khach(CTM,SoKhach);
    DocFile_Phim(QLP);
    DocFile_PC(QLPC);
    DocFile_NV(QLNV);
    DocFile_LichChieu(QLLC);
    DocFile_Ve(QLV);
}

void DocFile_Khach(vector<Customer>& CTM, int& SoKhach){
    int i = -1;
    CTM.clear();
    ifstream ip;
    ip.open("GuestData.csv");
    string Gmail;
    string MatKhau;
    string HoTen;
    string LoaiKhachHang;
    string SoDus;
    // EOF = end of file
    while(ip.peek()!=EOF){
        i++;
        getline(ip,Gmail,',');
        getline(ip,MatKhau,',');
        getline(ip,HoTen,',');
        getline(ip,LoaiKhachHang,',');
        getline(ip,SoDus,'\n');
        int SoDu = stoi(SoDus);
        Customer temp; temp.setGmail(Gmail); temp.setMatKhau(MatKhau); temp.HoTen = HoTen;
        temp.LoaiKhachHang = LoaiKhachHang; temp.setSoDu(SoDu);
        CTM.push_back(temp);
    }
    ip.close();
    SoKhach = i;
}

void DocFile_Phim(QuanLyPhim& QLP){
    ifstream ip2;
    ip2.open("Phim.csv");
    QLP.~QuanLyPhim();
    while(ip2.peek()!= EOF){
        string ti,ye;
        string mp,tp,tl,dd,dds,qg;
        getline(ip2,mp,',');
        getline(ip2,tp,',');
        getline(ip2,tl,',');
        getline(ip2,ti,',');
        getline(ip2,dd,',');
        getline(ip2,dds,',');   
        getline(ip2,ye,',');
        getline(ip2,qg,'\n');
        Film temp(mp,tp,tl,ti,dd,dds,ye,qg);
        QLP.Add_Film(temp);
    }
    ip2.close();
}

void DocFile_PC(QLPhongChieu& QLPC){
    ifstream ip3;
    ip3.open("PhongChieu.csv");
    QLPC.~QLPhongChieu();
    while(ip3.peek()!= EOF){
        string maPC,socho,maychieu,amthanh,dientich,tinhtrang,maBV;
        getline(ip3,maPC,',');
        getline(ip3,socho,',');
        getline(ip3,maychieu,',');
        getline(ip3,amthanh,',');
        getline(ip3,dientich,',');
        getline(ip3,tinhtrang,',');
        getline(ip3,maBV,'\n');
        // chuyen string thanh int
        int nsocho = stoi(socho);
        float ndientich = stoi(dientich);
        PhongChieu temp(maPC,nsocho,maychieu,amthanh,ndientich,tinhtrang,maBV);
        QLPC.Add_PC(temp);
    }
    ip3.close();
}

void DocFile_NV(QuanLyNhanVien& QLNV){
    ifstream ip4;
    ip4.open("NhanVien.csv");
    QLNV.~QuanLyNhanVien();
    while(ip4.peek()!= EOF){
        string MaNV,HoTen,NgaySinh,QueQuan,SDT,SoCMT,ChucVu,PhanQuyen,TaiKhoan,MatKhau;
        getline(ip4,MaNV,',');
        getline(ip4,HoTen,',');
        getline(ip4,NgaySinh,',');
        getline(ip4,QueQuan,',');
        getline(ip4,SDT,',');
        getline(ip4,SoCMT,',');
        getline(ip4,ChucVu,',');
        getline(ip4,PhanQuyen,',');
        getline(ip4,TaiKhoan,',');
        getline(ip4,MatKhau,'\n');
        NhanVien temp(MaNV,HoTen,NgaySinh,QueQuan,SDT,SoCMT,ChucVu,PhanQuyen,TaiKhoan,MatKhau);
        QLNV.Add_NV(temp);
    }
    ip4.close();
}

void DocFile_LichChieu(QuanLyLichChieu& QLLC){
    ifstream ip5;
    ip5.open("LichChieu.csv");
    QLLC.~QuanLyLichChieu();
    while(ip5.peek()!= EOF){
        string MaLichChieu,TenPhim,Ngay,Gio,PhongChieu;
        getline(ip5,MaLichChieu,',');
        getline(ip5,TenPhim,',');
        getline(ip5,Ngay,',');
        getline(ip5,Gio,',');
        getline(ip5,PhongChieu,'\n');
        LichChieu temp(MaLichChieu,TenPhim,Ngay,Gio,PhongChieu);
        QLLC.Add_LichChieu(temp);
    }
    ip5.close();
}

void DocFile_Ve(QuanLyVe& QLV){
    ifstream ip5;
    ip5.open("Ve.csv");
    QLV.~QuanLyVe();
    while(ip5.peek()!= EOF){
        string MaVe,MaPhim,LoaiKhachHang;
        string GiaLoaiVe1, SoLuong1, SoVeDaBan1;
        string thanhtien;
        getline(ip5,MaVe,',');
        getline(ip5,MaPhim,',');
        getline(ip5,LoaiKhachHang,',');
        getline(ip5,GiaLoaiVe1,',');
        getline(ip5,SoLuong1,',');
        getline(ip5,SoVeDaBan1,',');
        getline(ip5,thanhtien,'\n');
        // int ThanhTien = stoi(thanhtien);
        int GiaLoaiVe = stoi(GiaLoaiVe1);
        int SoLuong = stoi(SoLuong1);
        int SoVeDaBan = stoi(SoVeDaBan1);
        Ve temp(MaVe,MaPhim,LoaiKhachHang,GiaLoaiVe,SoLuong,SoVeDaBan);
        QLV.Add_Ve(temp);
    }
    ip5.close();
}


void UpdateFile_Ve(QuanLyVe& QLV){
    fstream ip1;
    ip1.open("Ve.csv", ios::out);
    int n = QLV.n;
    if(ip1.is_open()){
        for (int i = 0; i < n; i++)
        {
            ip1 << (QLV.p + i)->getMaVe() << ",";
            ip1 << (QLV.p + i)->getMaPhim() << ",";
            ip1 << (QLV.p + i)->getLoaiKhachHang() << ",";
            ip1 << (QLV.p + i)->getGiaLoaiVe() << ",";
            ip1 << (QLV.p + i)->getSoLuong() << ",";
            ip1 << (QLV.p + i)->getSoVeDaBan() << ",";
            ip1 << (QLV.p + i)->ThanhTien() << endl;
        }
        ip1.close();
    }
}
void UpdateFile_LichChieu(QuanLyLichChieu& QLLC){
    fstream ip1;
    ip1.open("LichChieu.csv", ios::out);
    int n = QLLC.n;
    if(ip1.is_open()){
        for (int i = 0; i < n; i++)
        {
            ip1 << (QLLC.p + i)->getMaLichChieu() << ",";
            ip1 << (QLLC.p + i)->getTenPhim() << ",";
            ip1 << (QLLC.p + i)->getNgay() << ",";
            ip1 << (QLLC.p + i)->getGio() << ",";
            ip1 << (QLLC.p + i)->getPhongChieu() << endl;
        }
        ip1.close();
    }
}

void UpdateFile_Phim(QuanLyPhim& QLP){
    fstream ip2;
    ip2.open("Phim.csv", ios::out);
    int n = QLP.n;
    if(ip2.is_open()){
        for (int i = 0; i < n; i++)
        {
            ip2 << (QLP.p + i)->getMaPhim() << ",";
            ip2 << (QLP.p + i)->getTenPhim() << ",";
            ip2 << (QLP.p + i)->getTheLoai() << ",";
            ip2 << (QLP.p + i)->getThoiLuong() << ",";
            ip2 << (QLP.p + i)->getDaoDien() << ",";
            ip2 << (QLP.p + i)->getDienVien() << ",";
            ip2 << (QLP.p + i)->getNamCongChieu() << ",";
            ip2 << (QLP.p + i)->getQuocGia() << endl;
        }
        ip2.close();
    }
}

void UpdateFile_NV(QuanLyNhanVien& QLNV){
    fstream ip1;
    ip1.open("NhanVien.csv", ios::out);
    int n = QLNV.n;
    if(ip1.is_open()){
        for (int i = 0; i < n; i++)
        {
            ip1 << (QLNV.p + i)->getMaNV() << ",";
            ip1 << (QLNV.p + i)->getHoTen() << ",";
            ip1 << (QLNV.p + i)->getNgaySinh() << ",";
            ip1 << (QLNV.p + i)->getQueQuan() << ",";
            ip1 << (QLNV.p + i)->getSDT() << ",";
            ip1 << (QLNV.p + i)->getSoCMT() << ",";
            ip1 << (QLNV.p + i)->getChucVu() << ",";
            ip1 << (QLNV.p + i)->getPhanQuyen() << ",";
            ip1 << (QLNV.p + i)->getTaiKhoan() << ",";
            ip1 << (QLNV.p + i)->getMatKhau() << endl;
        }
        ip1.close();
    }
}

void UpdateFile_PC(QLPhongChieu& QLPC){
    fstream ip1;
    ip1.open("PhongChieu.csv", ios::out);
    int n = QLPC.n;
    if(ip1.is_open()){
        for (int i = 0; i < n; i++)
        {
            ip1 << (QLPC.p + i)->getMaPhongChieu() << ",";
            ip1 << (QLPC.p + i)->getSoCho() << ",";
            ip1 << (QLPC.p + i)->getMayChieu() << ",";
            ip1 << (QLPC.p + i)->getAmThanh() << ",";
            ip1 << (QLPC.p + i)->getDienTich() << ",";
            ip1 << (QLPC.p + i)->getTinhTrang() << ",";
            ip1 << (QLPC.p + i)->getMaBaoVe() << endl;

        }
        ip1.close();
    }
}

void UpdateFile_Khach(vector<Customer>& CTM, int& SoKhach){
    fstream ip1;
    ip1.open("GuestData.csv", ios::out);
    int n = CTM.size();
    if(ip1.is_open()){
        for (int i = 0; i < n; i++)
        {
            ip1 << CTM[i].getGmail() << ",";
            ip1 << CTM[i].getMatKhau() << ",";
            ip1 << CTM[i].HoTen << ",";
            ip1 << CTM[i].LoaiKhachHang << ",";
            ip1 << CTM[i].getSoDu() << endl;
        }
        ip1.close();
    }
}


void Update(QuanLyNhanVien& QLNV,QuanLyPhim& QLP,QuanLyLichChieu& QLLC, QLPhongChieu& QLPC , QuanLyVe& QLV ,vector<Customer>& CTM, int& SoKhach){
    UpdateFile_LichChieu(QLLC);
    UpdateFile_Phim( QLP);
    UpdateFile_Ve(QLV);
    UpdateFile_NV( QLNV);
    UpdateFile_PC( QLPC);
    UpdateFile_Khach(CTM, SoKhach);
}