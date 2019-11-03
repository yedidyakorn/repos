/*
File: Rational.h
Description: mangers rational numbers
Course: 150018 C++ Workshop
Exercise 2, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include "mytypes.h"
#include <iostream>
using namespace std;


struct Rational
{
	int numerator;
	uint denominator;
};

Rational & rationalCtor(int, uint);
Rational & rationalCtor(int);

uint gcd(uint, uint);
void reductFraction(uint&, uint&);

Rational operator + (const Rational & a, const Rational & b);
Rational operator - (const Rational & a, const Rational & b);
Rational operator * (const Rational & a, const Rational & b);

bool operator == (const Rational & a, const Rational & b);
bool operator != (const Rational & a, const Rational & b);
bool operator > (const Rational & a, const Rational & b);
bool operator < (const Rational & a, const Rational & b);
bool operator >= (const Rational & a, const Rational & b);
bool operator <= (const Rational & a, const Rational & b);
ostream& operator << (ostream& out, const Rational& rhs);
istream& operator >> (istream& in, Rational& rhs);

void addRational(void* a, const void* b, const void* c);
void subRational(void* a, const void* b, const void* c);
void multRational(void* a, const void* b, const void* c);
int compareRational(const void* a, const void* b);

#endif