/*
File: Complex.h
Description: mangers complex numbers
Course: 150018 C++ Workshop
Exercise 2, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include "mytypes.h"
#include <iostream>
using namespace std;



struct Complex
{
	float real;
	float imaginary;
};

Complex & complexCtor(float, float);
Complex & complexCtor(float);

float abs(Complex &);

Complex operator + (const Complex & a, const Complex & b);
Complex operator - (const Complex & a, const Complex & b);
Complex operator * (const Complex & a, const Complex & b);

bool operator == (const Complex & a, const Complex & b);
bool operator != (const Complex & a, const Complex & b);
bool operator > (const Complex & a, const Complex & b);
bool operator < (const Complex & a, const Complex & b);
bool operator >= (const Complex & a, const Complex & b);
bool operator <= (const Complex & a, const Complex & b);

ostream& operator << (ostream& out, const Complex& complexNum);
istream& operator >> (istream& in, Complex& complexNum);

void addComplex(void* a, const void* b, const void* c);
void subComplex(void* a, const void* b, const void* c);
void multComplex(void* a, const void* b, const void* c);

int compareComplex(const void* a, const void* b);


#endif