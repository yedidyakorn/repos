/*
File: main.cpp
Description:
Course: 150018 C++ Workshop
Exercise 7, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/
#include <iostream>
#include <string>
#include<fstream>
#include"Student.h"
#include"write.h"
using namespace std;
using uint = unsigned int;
using cstring = char*;
int main() 
{
	string name;
	cout << "enter file name\n";
	cin >> name;
	initialization(name);
	print(name);

	system("pause");
	return 0;
}