#include "Ve.h"
#include<string>
#include<iomanip>
class QuanLyVe
{
private:
    Ve *p;
    int n;
public:
    QuanLyVe(/* args */);
    ~QuanLyVe();
    void Show();
    void Add_Ve(Ve);
    int checkMaVe(string);
    int IndexOf(string);
    void Update_Ve(string);
    void Delete_Ve(string);
};