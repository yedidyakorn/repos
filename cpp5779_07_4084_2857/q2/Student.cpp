/*
File: Student.cpp
Description:
Course: 150018 C++ Workshop
Exercise 7, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/
#include "Student.h"




Student & studentCtor(const uint id, const string firstName, const string lastName)
{
	Student temp;
	temp._id = id;
	temp._firstName = firstName;
	temp._lastName = lastName;
	temp._firstName.resize(20);
	temp._lastName.resize(20);
	return temp;
}

void printStudent(Student & a)
{
	cout << "id: " << a._id << "name: "<< a._firstName << a._lastName;
}



