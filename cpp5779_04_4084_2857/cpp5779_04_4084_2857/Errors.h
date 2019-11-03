#pragma once
/*
File: Errors.h
Description: mangers the errors
Course: 150018 C++ Workshop
Exercise 4, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

struct IndexException {
	unsigned int index;
	unsigned int maxIndex;
	IndexException(int ind, int max) : index(ind), maxIndex(max) {}
};
