/*
File: Rational.cpp
Description: mangers rational numbers
Course: 150018 C++ Workshop
Exercise 2, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#include <iostream>
#include "Rational.h"

using namespace std;

//A function to construct a rational number. 
//If the mone = 0 then the number will be displayed 0/1. 
Rational & rationalCtor(int numerat, uint denominat) {
	Rational temp;
	if (numerat == 0)
	{
		temp.numerator = 0;
		temp.denominator = 1;
		return temp;
	}
	//If the mone <0 must multiply by -1 to get a positive number
	//So we can send it to a function reductFraction.
	//Check if the mone is negative, to return it to negative
	bool check = false;
	if (numerat < 0)
	{
		numerat *= -1;
		check = true;
	}
	uint numerat2 = (uint)numerat;//A temporary variable to save it as uint
	reductFraction(numerat2, denominat);//Reduce numbers
	int numerat3 = (int)numerat2;// save mone as int
	if (check)
		numerat3 *= -1;
	temp.numerator = numerat3;
	temp.denominator = denominat;
	return temp;
}

//Function with one parameter, will be 0/1.
Rational & rationalCtor(int numerat) {
	Rational temp;
	temp.numerator = numerat;
	temp.denominator = 1;
	return temp;
}

//Euclid's algorithm, finding a common factor
uint gcd(uint x, uint y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x % y);
}

//Narrowing the numbers by dividing the numerator and the denominator by the number we found
void reductFraction(uint& a , uint& b) {
	uint number = gcd(a, b);
	a /= number;
	b /= number;
}

//Addition and subtraction of fractions. 
//Find a common denominator by multiplying the denominators 
//by expanding the numerator according to the common denominator
Rational operator + (const Rational & a, const Rational & b) {
	uint commonDenominator = a.denominator * b.denominator;
	int aNumerator = a.numerator * (commonDenominator / a.denominator);
	int bNumerator = b.numerator * (commonDenominator / b.denominator);
	int newNumerat = aNumerator + bNumerator;
	Rational newTemp = rationalCtor(newNumerat, commonDenominator);
	return newTemp;
}

Rational operator - (const Rational & a, const Rational & b) {
	uint commonDenominator = a.denominator * b.denominator;
	int aNumerator = a.numerator * (commonDenominator / a.denominator);
	int bNumerator = b.numerator * (commonDenominator / b.denominator);
	int newNumerat = aNumerator - bNumerator;
	Rational newTemp = rationalCtor(newNumerat, commonDenominator);
	return newTemp;
}

//Multiply a numerator, multiplying a denominator
Rational operator * (const Rational & a, const Rational & b) {
	int newNumerat = a.numerator * b.numerator;
	uint newDenominat = a.denominator * b.denominator;
	Rational newTemp = rationalCtor(newNumerat, newDenominat);
	return newTemp;
}

//Comparing a numerator, Comparing a denominator
bool operator == (const Rational & a, const Rational & b) {
	bool check = true;
	if (a.numerator != b.numerator || a.denominator != b.denominator)
		check = false;
	return check;
}
//Using a comparison we've already made
bool operator != (const Rational & a, const Rational & b) {
	bool checkNo = true;
	if (a == b)
		checkNo = false;
	return checkNo;
}

bool operator > (const Rational & a, const Rational & b) {
	bool check = false;
	if ((a-b).numerator > 0)
		check = true;
	return check;
}

bool operator < (const Rational & a, const Rational & b) {
	bool check = false;
	if ((a - b).numerator == 0 || (a-b).numerator < 0)
		check = true;
	return check;
}

bool operator >= (const Rational & a, const Rational & b) {
	bool check = false;
	if (!(a < b))
		check = true;
	return check;
}

bool operator <= (const Rational & a, const Rational & b) {
	bool check = false;
	if (!(a > b))
		check = true;
	return check;
}

//Loading input and output
ostream& operator << (ostream& out, const Rational& rationalNum) {
	out << rationalNum.numerator << "/" << rationalNum.denominator;
	return out;
}

istream& operator >> (istream& in, Rational& rationalNum) {
	in >> rationalNum.numerator >> rationalNum.denominator;
	return in;
}

void addRational(void* a, const void* b, const void* c) {
	*(Rational*)a= *(Rational*)b+ *(Rational*)c;
}
void subRational(void* a, const void* b, const void* c) {
	*(Rational*)a = *(Rational*)b - *(Rational*)c;
}
void multRational(void* a, const void* b, const void* c) {
	*(Rational*)a = *(Rational*)b * *(Rational*)c;
}

int compareRational(const void* a, const void* b) {
	if (a == b)
		return 0;
	if (a > b)
		return 1;
	return -1;
}