// #include "DocFile.h"
// #include "DoHoa.h"
// #include "Time.h"
#include"User.h"
#include "Admin.h"

using namespace std;
int main()
{
  
   QuanLyPhim QLP;
   QuanLyNhanVien QLNV;
   vector<Customer> CTM;
   QLPhongChieu QLPC;
   
   QuanLyLichChieu QLLC;
   QuanLyVe QLV;
   int SoKhach;

   DocFile(QLNV, QLP, QLLC, QLPC, QLV, CTM, SoKhach);
   system("cls");
   box(75,2,30,7,7,8);
   GoTo(80,5);
   cout<<"WELCOME TO RIO CINEMA"<<endl;
   GoTo(77,6);
   SetColor(0,8);
   cout<<"Hay xem theo cach cua ban!";
   GoTo(85,10);
   SetColor(0,8);
   for(int i=1;i<=10;i++)
       cout<<(char)178;
   SetColor(0,5);
   int chon;
   GoTo(70,12); cout << "Ban La: " << endl;
   vector<string> m = {"Khach","Admin"};
   CanLe();
   chon = menu(m);
   switch (chon)
   {
   case 1:
      DangNhap_Khach();
      break;
   case 2:
      DangNhap_Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
      break;
   default:
      break;
   }
   return 0;
}

