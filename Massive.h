#pragma once
#include <iostream>
#include "Complex.h"
using namespace std;

//������� ������� ������
template <class T> class mas { 
    T* a;
    int n;
    void Create() {
        a = new T[n];
    }

public:
    mas(int size) : n(size) { Create(); }; //�����������
    ~mas() { /*delete[] a;  */} //����������

    void input() { //���� ���������
        cout << "\n������� " << n << " ��������(-��): ";
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }

    void print() { //����� ������� �� �����
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }

    //���������� ��������� *.
    mas<T> operator * (mas  b)
    {
        mas result(n);
        for (int i = 0; i < n; i++)
        {
            result.a[i] = a[i] * b.a[i];
        }
        return result;
    }

    mas<T> operator * (int k)
    {
        mas result(n);
        for (int i = 0; i < n; i++)
        {
            result.a[i] =a[i] *k;
        }
        return result;
    }

    /* � ������� ��������� ������� ����������� �������� ��������������[].
    �� ����� ������[] �������� �� ������ ��� ������ � � ������ ��� ������� mas ��� ������� i
    �� ������ �������� ����� �����.*/
    T& operator[](int i) //���������� []     
    {
        return a[i];
    }

    //������������� �������� ������������ =
    mas<T> operator=(mas b)
    { 
        a = b.a;
        return *this;
    }

};
