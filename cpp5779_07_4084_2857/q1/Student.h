/*
File: Student.h
Description:
Course: 150018 C++ Workshop
Exercise 7, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/
#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
using uint = unsigned int;
using cstring = char*;


	struct Student
	{
		uint _id;
		string _firstName;
		string _lastName;
		char _curses[6]{"NNNNN"};
	};

	Student & studentCtor(const uint id, const string firstName, const string lastName);
	void printStudent(Student& a);



#endif