#include "QuanLyVe.h"
#include"DoHoa.h"
#include"QuanLyPhim.h"
#include"Time.h"
#include"DocFile.h"
QuanLyVe::QuanLyVe(/* args */)
{
    this->p = NULL;
    this->n = 0;
}

QuanLyVe::~QuanLyVe()
{
    delete[] this->p;
}



void QuanLyVe::Add_Ve(Ve v){
    if(this->n == 0){
        this->p = new Ve[this->n+1];
        *(this->p + this->n) = v;
    }
    else{
        Ve *temp = new Ve[this->n];
        for(int i = 0; i < this->n; i++){
            *(temp+i) = *(this->p+i);
        }
        delete[] this->p;
        this->p = new Ve[this->n+1];
        for(int i = 0; i < this->n; i++){
            *(this->p+i) = *(temp+i); 
        }
        delete[] temp;
        *(this->p + n) = v;
    }   
    this->n++;
}

void QuanLyVe::Show(){
    cout << setw(25) << left << "Mã Phòng Chiếu:" << "|";
    cout << setw(20) << left << " Số Chỗ:" << "|";
    cout << setw(20) << left << " Máy Chiếu:" << "|";
    cout << setw(20) << left << " Âm Thanh:" << "|";
    cout << setw(20) << left << " Diện Tích:" << "|";
    cout << setw(20) << left << " Tình trạng:" << "|";
    cout << setw(20) << left << " Mã Bảo Vệ:" << endl;
    for(int i= 0; i < this->n; i++){
        (p+i)->Display();
    }
}

int QuanLyVe::checkMaVe(string s)
{
    int index = -1;
    for (int i = 0; i < this->n; i++)
    {
        if (s == (this->p + i)->GetMaVe())
        {
            index = i;
            break;
        }
    }
    return index;
}

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

void QuanLyVe::Delete_Ve(string m)
{ 
    int f = checkMaVe(m);
    if (f >= 0)
    {
        if (this->n == 1)
        {
            delete[] this->p;
            this->p = nullptr;
        }
        else
        {
            Ve *temp = new Ve[this->n];
            for (int k = 0; k < this->n; k++)
            {
                *(temp + k) = *(this->p + k);
            }
            delete[] this->p;
            this->p = new Ve[this->n - 1];
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
void Thanhcong()
{
	cout << "------------------" << endl;
	SetColor(0, 9);
	cout << " Yeu cau cua ban da duoc thuc hien" << endl;
	intime();
	SetColor(0, 7);
	cout << "------------------" << endl;
}

void QuanLyVe::Datve() 
{

    cout<<"Nhap so ve quy khach muon mua:"<<endl;
    int n;
    cin>>n;
    cout<<"Nhap ma:"<<endl;
    SetColor(0, 7);
		while (n > 0)
		{
			n--;
			int ms;

			cout << " " << (char)16 << (char)16;
			cin >> ms;
            SetColor(0,2);
            QuanLyPhim F;
            DocFile_Phim(F);
            cout<<"Quy khach dat ve xem phim ten:"<<F.getFimlName(ms)<<endl;  
		} 
        int lc2;
    cout<<"Quy khach thanh toan bang:"<<endl;
    cout<<"1.Tien Mat."<<endl;
    cout<<"2.Chuyen Ngan Hang"<<endl;
    cin>>lc2;
    if(lc2==1)
    {
        Thanhcong();   
    }
    if(lc2==2)
    {
        cout<<"chuyen vao stk:56010001595291 < TRAN THI HUONG TRINH> <BIDV> "<<endl;
    }
    else
    {
        cout<<"Moi quy khach nhap lai."<<endl;
        //
    }
}