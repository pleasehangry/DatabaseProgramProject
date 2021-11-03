#include"DoHoa.h"
#include"Film.h"
#include "Time.h"
class Person
{
private:
    string name;
    int age;
    string tel;
public:
    Person(){};
    void setPerson(){
        cout << "Name: "; cin >> name;
        cout << endl << "Age: "; cin >> age;
        cout << endl << "Telephone: "; cin >> tel;
    }
    Person(string name, int age, string tel){
        this->name = name;
        this->age = age;
        this->tel = tel;
    }
    void setName(string name){
        this->name = name;
    }
    void setAge(int age){
        this->age = age;
    }
    void setTel(string tel){
        this->tel = tel;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    string getTel(){
        return tel;
    }
    void display(){
        cout << "Name: " << name << "      Age: " << age << "      Tel: " << tel << endl;
    }
};
void us1()
{
    
}
void thanhcong()
{
	cout << "------------------" << endl;
	SetColor(0, 9);
	cout << " Yeu cau cua ban da duoc thuc hien" << endl;
	intime();
	SetColor(0, 7);
	cout << "------------------" << endl;
}
void DatVe() // viet trong phan quan ly ve
{
    cout<<"Nhập số vé quý khách cần mua:"<<endl;
    int n;
    cin>>n;
    cout<<"Nhập mã vé mà quý khách muốn mua:"<<endl;
    SetColor(0, 7);
		while (n > 0)
		{
			n--;
			int ms;

			cout << " " << (char)16 << (char)16;
			cin >> ms;
            SetColor(0,2);
            cout<<"Quý khách đặt vé xem Phim tên :";
            //
		} 
        int lc2;
    cout<<"Quý khách thanh toán bằng:"<<endl;
    cout<<"1.tiền mặt."<<endl;
    cout<<"2.chuyển ngân hàng."<<endl;
    cin>>lc2;
    if(lc2==1)
    {

    }
    if(lc2==2)
    {

    }
    else
    {
        cout<<"mời quý khách nhập lại."<<endl;
    }
    thanhcong();
}
//chua co tham so
// void Person()
// {
//     system("cls");
//     SetColor(0,2);
//     cout<<"Đăng Nhập thành công!"<<endl;
//     SetColor(0,7);
//     cout<<"Xin chào";
//     SetColor(0,9);
//     //in họ tên
//     SetColor(0,14);
//     cout<<"\n1.Xem Hom nay co phim gi:"<<endl;
//     cout<<"\n2.Tim kiem Phim theo the loai:"<<endl;
//     cout<<"\n3.Search Phim"<<endl;
//     cout<<"\n4.Doi mat khau"<<endl;
//     SetColor(0,7);
//     int ma;
//     cout<<"Nhập lựa chọn của bạn:"<<endl;
//     cout<<" "<<(char)16<<(char)16;
//     cin>>ma;
//     switch(ma)
//     {
//         case 1:
//          int lenh;
//         //  Film F;
//         // F.Phim();
//          cout<<"\n1.Đặt vé"<<endl;
//          cout<<"2.Trở vể màn hình chọn"<<endl;
//          SetColor(0,7);
//          cout<<(char)16<<(char)16;
//          cin>>lenh;
//          if(lenh==2)
//          {
//              system("cls");
//              //chua co tham so
//              Person();
//          }
//          if(lenh==1)
//          {
//              DatVe();
//              int lenh;
//              cout<<"----------------------";
//              cout<<"bạn có muốn làm gì nữa không?"<<endl;
//             SetColor(0,14);
//             cout<<"1.Trở về màn hình chọn"<<endl;
//             cout<<"2.kết thúc"<<endl;
//             SetColor(0,7);
//             cout<<" "<<(char)16<<(char)16;
//             cin>>lenh;
//             if(lenh==1)
//             {
//                 system("cls");
//                 Person();
//             }
//          } 
//             break;
//         case 2:
//         // Film F1;
//         // F1.TimkiemPhim();
//         int lenh;
//              cout<<"----------------------";
//              cout<<"bạn có muốn làm gì nữa không?"<<endl;
//             SetColor(0,14);
//             cout<<"1.Trở về màn hình chọn"<<endl;
//             cout<<"2.kết thúc"<<endl;
//             SetColor(0,7);
//             cout<<" "<<(char)16<<(char)16;
//             cin>>lenh;
//             if(lenh==1)
//             {
//                 system("cls");
//                 Person();
//             }
//             break;
//         case 3:
//             break;
//         case 4:
//             break;
    
//     } 
// } 

