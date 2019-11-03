/*
File: common.cpp
Description: makes operations on numbers
Course: 150018 C++ Workshop
Exercise 2, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/


#ifndef COMMON_H_
#define COMMON_H_

#pragma once
#include"Rational.h"
#include"Complex.h"
#include"mytypes.h"

typedef void(*oper) (void *, const void*, const void*);//functoin pointer

//oper mr = multRational, mc = multComplex, sr = subRational, sc = subComplex, ar=addRational, ac = addComplex;
void operation(void *, const void*, const void*, oper);

template <class mytype>
mytype mult(mytype U, mytype V)
{
	return (U*V);
}

template <class mytype>
mytype add(mytype U, mytype V)
{
	return (U+V);
}

template <class mytype>
mytype sub(mytype U, mytype V)
{
	return (U-V);
}

#endif