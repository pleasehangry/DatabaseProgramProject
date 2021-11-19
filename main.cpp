
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

   int chon;
   cout << "Ban La: " << endl;
   cout << "Khach" << endl;
   cout << "Admin" << endl;
   
   cout << ">>"; cin >> chon;
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
   Update(QLNV, QLP, QLLC, QLPC, QLV, CTM, SoKhach);
   return 0;
}