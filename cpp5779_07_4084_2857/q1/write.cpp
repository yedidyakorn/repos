/*
File: write.cpp
Description:
Course: 150018 C++ Workshop
Exercise 7, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#include"write.h"

void initialization(string fileName)
{
	ofstream outFile;
	Student a;
	string temp = fileName + ".dat";
	a=studentCtor(0, "-------------------", "-------------------");
	outFile.open((char*)temp, ios::out | ios::binary);
	for(int i=0;i<10;i++)
		outFile.write((char*)&a, sizeof(Student));

	outFile.close();
}

void print(string fileName)
{
	ifstream inFile;
	Student a;
	inFile.open(fileName, ios::in | ios::binary);
	for (int i = 0; i < 10; i++)
		inFile.read((char*)&a, sizeof(Student));
	printStudent(a);
	inFile.close();
}
