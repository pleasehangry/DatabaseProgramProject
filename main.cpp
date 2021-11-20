
#include "DocFile.h"
#include <math.h>
#include "DoHoa.h"
#include "Time.h"
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
   int chon;
   cout << "Ban La: " << endl;
   cout << "1.Khach" << endl;
   cout << "2.Admin" << endl;
   
   cout << ">>"; cin >> chon;
   switch (chon)
   {
   case 1:
      DangNhap_Khach();
      break;
   case 2:
      DangNhap_Admin(QLP, QLNV,CTM, QLPC, QLLC, QLV, SoKhach);
      Update(QLNV, QLP, QLLC, QLPC, QLV, CTM, SoKhach);
      break;
   default:
      break;
   }
   return 0;
}