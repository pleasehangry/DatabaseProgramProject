// #include "QuanLyVe.h"
// QuanLyVe::QuanLyVe(/* args */)
// {
//     this->p = NULL;
//     this->n = 0;
// }

// QuanLyVe::~QuanLyVe()
// {
//     delete[] this->p;
// }



// void QuanLyVe::Add_Ve(Ve v){
//     if(this->n == 0){
//         this->p = new Ve[this->n+1];
//         *(this->p + this->n) = v;
//     }
//     else{
//         Ve *temp = new Ve[this->n+1];
//         for(int i = 0; i < this->n; i++){
//             *(temp+i) = *(this->p+i);
//         }
//         delete[] this->p;
//         this->p = new Ve[this->n+1];
//         for(int i = 0; i < this->n; i++){
//             *(this->p+i) = *(temp+i); 
//         }
//         delete[] temp;
//         *(this->p + n) = v;
//     }   
//     this->n++;
// }

// void QuanLyVe::Show(){
//     cout << setw(25) << left << "Mã Phòng Chiếu:" << "|";
//     cout << setw(20) << left << " Số Chỗ:" << "|";
//     cout << setw(20) << left << " Máy Chiếu:" << "|";
//     cout << setw(20) << left << " Âm Thanh:" << "|";
//     cout << setw(20) << left << " Diện Tích:" << "|";
//     cout << setw(20) << left << " Tình trạng:" << "|";
//     cout << setw(20) << left << " Mã Bảo Vệ:" << endl;
//     for(int i= 0; i < this->n; i++){
//         (p+i)->Display();
//     }
// }

// int QuanLyVe::checkMaVe(string s)
// {
//     int index = -1;
//     for (int i = 0; i < this->n; i++)
//     {
//         if (s == (this->p + i)->getMaVe())
//         {
//             index = i;
//             break;
//         }
//     }
//     return index;
// }

// void QuanLyVe::Update_Ve(string m)
// {
//     int i = checkMAdd_Ve("m");
//     if(i >= 0){
//         if (m == (this->p + i)->getMaVe())
//         {
//             string a,c,d,f,g;
//             int b;
//             float e;
//             system("cls");
//             (this->p + i)->Display();
//             cout << "Nhập Mã Phòng Chiếu: ";
//             fflush(stdin);
//             getline(cin, a);
//             cout << "Nhập Số Chỗ: ";
//             cin >> b;
//             cout << "Nhập Máy Chiếu: ";
//             fflush(stdin);
//             getline(cin, c);
//             cout << "Nhập Âm Thanh: ";
//             fflush(stdin);
//             getline(cin, c);
//             cout << "Nhập Diện Tích: ";
//             cin >> e;
//             cout << "Nhập Tình Trạng: ";
//             fflush(stdin);
//             getline(cin, f);
//             cout << "Nhập Mã Bảo Vệ: ";
//             fflush(stdin);
//             getline(cin, g);
//             (this->p + i)->setMaVe(a);
//             (this->p + i)->setSoCho(b);
//             (this->p + i)->setMayChieu(c);
//             (this->p + i)->setAmThanh(d);
//             (this->p + i)->setDienTich(e);
//             (this->p + i)->setTinhTrang(f);
//             (this->p + i)->setMaBaoVe(g);
//         }
//     }
//     else cout << "Khong Tim Thay Ma Phim Can Sua!";
//     cout << endl;
// }

// void QuanLyVe::Delete_Ve(string m)
// {
//     int f = checkMAdd_Ve(m);
//     if (f >= 0)
//     {
//         if (this->n == 1)
//         {
//             delete[] this->p;
//             this->p = nullptr;
//         }
//         else
//         {
//             Ve *temp = new Ve[this->n];
//             for (int k = 0; k < this->n; k++)
//             {
//                 *(temp + k) = *(this->p + k);
//             }
//             delete[] this->p;
//             this->p = new Ve[this->n - 1];
//             for (int j = 0; j < this->n - 1; j++)
//             {
//                 if (j < f)
//                 {
//                     *(this->p + j) = *(temp + j);
//                 }
//                 else
//                 {
//                     *(this->p + j) = *(temp + j + 1);
//                 }
//             }
//             delete[] temp;
//         }
//     }
//     this->n--;
// }