#pragma once
#include <iostream>
#include "Complex.h"
using namespace std;

//задание шаблога класса
template <class T> class mas { 
    T* a;
    int n;
    void Create() {
        a = new T[n];
    }

public:
    mas(int size) : n(size) { Create(); }; //конструктор
    ~mas() { /*delete[] a;  */} //деструктор

    void input() { //ввод элементов
        cout << "\nВведите " << n << " элемента(-ов): ";
        for (int i = 0; i < n; i++)
            cin >> a[i];
    }

    void print() { //вывод массива на экран
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }

    //Перегрузка оператора *.
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

    /* В строках следующих строках перегружаем оператор индексирования[].
    На место вызова[] вернется по ссылке сам объект и в ячейку его массива mas под номером i
    мы сможем записать целое число.*/
    T& operator[](int i) //перегрузка []     
    {
        return a[i];
    }

    //перегруженный оператор присваивания =
    mas<T> operator=(mas b)
    { 
        a = b.a;
        return *this;
    }

};
