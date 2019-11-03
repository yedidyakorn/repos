/*
File: Complex.cpp
Description: mangers complex numbers
Course: 150018 C++ Workshop
Exercise 2, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#include <iostream>
#include <cmath>
#include "Complex.h"
#include "Rational.h"

using namespace std;

//A function to construct a complex number
Complex & complexCtor(float realNum, float imaginaryNum) {
	Complex temp;
	temp.real = realNum;
	temp.imaginary = imaginaryNum;
	return temp;
}
//Function with one parameter. The previous function is used with parameter 0.
Complex & complexCtor(float realOnly) {
	return complexCtor(realOnly, 0);
}
//The formula: r = shores(a^2 + b^2)
float abs(const Complex & complexNum) {
	float temp = sqrt(complexNum.real) + sqrt(complexNum.imaginary);
	return temp / temp;
}

//Addition and subtraction real number
//Addition and subtraction Im number
Complex operator + (const Complex & a, const Complex & b) {
	float newReal = a.real + b.real;
	float newImaginary = a.imaginary + b.imaginary;
	Complex newTemp = complexCtor(newReal, newImaginary);
	return newTemp;
}

Complex operator - (const Complex & a, const Complex & b) {
	float newReal = a.real - b.real;
	float newImaginary = a.imaginary - b.imaginary;
	Complex newTemp = complexCtor(newReal, newImaginary);
	return newTemp;
}
//Multiply real number, multiplying a Im number
Complex operator * (const Complex & a, const Complex & b) {
	float newReal = a.real * b.real;
	float newImaginary = a.imaginary * b.imaginary;
	Complex newTemp = complexCtor(newReal, newImaginary);
	return newTemp;
}
//Comparing a r number
bool operator == (const Complex & a, const Complex & b) {
	bool check = false;
	if (abs(a) == abs(b))
		check = true;
	return check;
}
//Using a comparison we've already made
bool operator != (const Complex & a, const Complex & b) {
	bool check = true;
	if (abs(a) == abs(b))
		check = false;
	return check;
}

bool operator > (const Complex & a, const Complex & b) {
	bool check = false;
	if (abs(a) > abs(b))
		check = true;
	return check;
}

bool operator < (const Complex & a, const Complex & b) {
	bool check = false;
	if (abs(a) < abs(b))
		check = true;
	return check;
}

bool operator >= (const Complex & a, const Complex & b) {
	bool check = false;
	if (!(a < b))
		check = true;
	return check;
}

bool operator <= (const Complex & a, const Complex & b) {
	bool check = false;
	if (!(a > b))
		check = true;
	return check;
}

//Loading input and output
ostream& operator << (ostream& out, const Complex& complexNum) {
	out << complexNum.real << "+" << complexNum.imaginary << "i\n";
	return out;
}

istream& operator >> (istream& in, Complex& complexNum) {
	in >> complexNum.real >> complexNum.imaginary;
	return in;
}

void addComplex(void* a, const void* b, const void* c) {
	*(Complex*)a = *(Complex*)b + *(Complex*)c;
}
void subComplex(void* a, const void* b, const void* c) {
	*(Complex*)a = *(Complex*)b - *(Complex*)c;
}
void multComplex(void* a, const void* b, const void* c) {
	*(Complex*)a = *(Complex*)b * *(Complex*)c;
}

int compareComplex(const void* a, const void* b) {
	if (a == b)
		return 0;
	if (a > b)
		return 1;
	return -1;
}