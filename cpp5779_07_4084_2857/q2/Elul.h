/*
File: Elul.h
Description:
Course: 150018 C++ Workshop
Exercise 7, Question 2
Author: Simcha Rubinstain & Yedidya Korn
*/
#pragma once
#ifndef ELUL_H_
#define ELUL_H_
#include <iostream>
#include <string>
#include<fstream>
#include"Student.h"
#include"write.h"
using namespace std;
using uint = unsigned int;
using cstring = char*;


class Elul
{
	string _name;
	fstream *_ptr;
	bool _file=false;
public:

	Elul();
	Elul(string name, fstream *_ptr = nullptr);
	Elul(Elul&&);
	Elul& operator = (Elul&&);
	~Elul();

	void isFile(string name);

};

#endif