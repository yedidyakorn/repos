/*
File: common.h
Description: makes operations on numbers
Course: 150018 C++ Workshop
Exercise 2, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#include "common.h"

void operation(void * final, const void* a, const void* b, oper func)//calculates an operation on two cells and puts the result in a third cell
{
	func(final, a, b);
}
