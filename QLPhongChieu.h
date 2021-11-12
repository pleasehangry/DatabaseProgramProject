#include "PhongChieu.h"
#include<iostream>
#pragma once
using namespace std;
class QLPhongChieu
{
private:
    PhongChieu *p;
    int n;
public:
    QLPhongChieu(/* args */);
    ~QLPhongChieu();
    void Add_PC(PhongChieu);
    void Show();
    int checkMSPC(string s);
    void Update_PC(string m);
    void Delete_PC(string m);
    friend void UpdateFile_PC(QLPhongChieu&);
    friend void DatVe();
};
