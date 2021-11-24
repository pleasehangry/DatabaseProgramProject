#include<iostream>
#include<string>
#include<assert.h>
#pragma once
using namespace std;


template<class T>
class QuanLy
{
protected:
    T *p;
    int n;  
public:
    QuanLy();
    QuanLy(int);
    ~QuanLy();
    void Erase();
    T& operator[](int);
    int Size() const;
    void Reallocate(int);
    void Resize(int);
    void Delete(string);
    virtual int CheckMS(string) = 0;
    void Insert(T,int);
    void InsertFirst(T);
    void Add(T);
    virtual void Update(string) = 0;
    virtual void Show() = 0;
};





template<class T>
QuanLy<T>::QuanLy()
{
    this->n = 0;
    this->p = nullptr;
}

template<class T>
QuanLy<T>::QuanLy(int length)
{
    this->n = length;
    assert(this->n >= 0);
    if(length > 0){
        this->p = new T[this->n];
    }
    else{
        this->p = nullptr;
    }
}

template<class T>
QuanLy<T>::~QuanLy()
{
    delete[] this->p;
}

template<class T>
void QuanLy<T>::Erase(){
    delete[] this->p;
    this->p = nullptr;
    this->n = 0;
}

template<class T>
T& QuanLy<T>::operator[](int index){
    assert(index >= 0 && index < this->n);
    return *(this->p + index);
}

template<class T>
int QuanLy<T>::Size() const{
    return this->n;
}

template<class T>
void QuanLy<T>::Reallocate(int newlength){
    Erase();
    if(newlength <= 0) return;
    this->p = new T[newlength];
    this->n = newlength;
}

template<class T>
void QuanLy<T>::Resize(int newlength){
    if(newlength == this->n) return;
    if(newlength <= 0){
        Erase();    return;
    }
    T *data = new T[newlength];
    if(this->n >0){
        int maxlength = (newlength > this->n) ? n : newlength;
        for (int i = 0; i < maxlength; i++)
        {
            data[i] = (*this)[i]; 
        }
    }
    delete[] this->p;
    this->p = data;
    this->n = newlength;
}
template<class T>
void QuanLy<T>::Delete(string m){
    int index = CheckMS(m);
    assert(index >= 0 && index < this->n);
    if(this->n == 1){
        Erase();
        return; 
    }
    T *data = new T[this->n - 1];
    for (int i = 0; i < index; i++)
    {
        data[i] = (*this)[i];
    }
    for (int j = index; j < this->n; j++)
    {
        data[j-1] = (*this)[j];
    }
    delete[] this->p;
    this->p = data;
    --this->n;
}

template<class T>
void QuanLy<T>::Insert(T t,int index){
    assert(index >= 0 && index <= this->n);
    T *data = new T[this->n + 1];
    for (int i = 0; i < index; i++)
    {
        data[i] = (*this)[i];
    }
    data[index] = t;
    for (int i = index; i < this->n; i++)
    {
        data[i+1] = (*this)[i];
    }
    delete[] this->p;
    this->p = data;
    ++this->n;
}

template<class T>
void QuanLy<T>::InsertFirst(T t){
    Insert(t,0);
}

template<class T>
void QuanLy<T>::Add(T t){
    Insert(t,this->n);
}
