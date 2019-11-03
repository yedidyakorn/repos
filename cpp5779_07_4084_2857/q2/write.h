/*
File: write.h
Description:
Course: 150018 C++ Workshop
Exercise 7, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/
#pragma once
#ifndef WRITE_H_
#define WRITE_H_
#include <iostream>
#include <string>
#include<fstream>
#include"Student.h"
using namespace std;
using uint = unsigned int;
using cstring = char*;

void initialization(string fileName);
void print(string fileName);


#endif
