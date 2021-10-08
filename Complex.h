#pragma once
#include <iostream>

using namespace std;
class Complex 
{
public:
	int re; // �������������� �����
	int im; // ������ �����
	// ����������� ������� � ������������� ��������
	Complex(); //�����������
	//������������ � �����������
	Complex(int a, int b); 
	Complex(const Complex& ob);
	~Complex(); //����������

	//���������� ��������� * ��� ����������� �����
	Complex operator * (Complex& com)
	{
		Complex rez;
		rez.re = re * com.re - im * com.im;
		rez.im = re * com.im + com.re * im;
		return rez;
	}

	Complex operator * (int k)
	{
		Complex rez;
		rez.re = re * k;
		rez.im = im * k;
		return rez;
	}

	//���������� ��������� = ��� ����������� �����
	Complex operator =(Complex com)
	{
		this->re = com.re;
		this->im = com.im;
		return *this;
	}

};
//���� ������������
Complex::Complex() 
{
	re = 0;
	im = 0;
}

//���� ������������ � �����������
Complex::Complex(int a, int b)
{
	re = a;
	im = b;
}

//���� ������������ � �����������
Complex::Complex(const Complex& ob) 
{ 
	re = ob.re; im = ob.im; 
}

Complex::~Complex() {}

//���������� ��������� ������ ��� ����������� �����
ostream& operator << (ostream& out, const Complex& com)
{
	if (com.im < 0)
		out << com.re << "-" << com.im << "*i\t";
	else
		out << com.re << "+" << com.im << "*i\t";
	return out;
}

//���������� ��������� ����� ��� ����������� �����
istream& operator >> (istream& in, Complex& com) {
	cout << "\nre: ";
	in >> com.re;
	cout << "im: ";
	in >> com.im;
	return in;
}


