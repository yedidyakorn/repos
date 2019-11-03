/*
File: main.cpp
Description: runs the program
Course: 150018 C++ Workshop
Exercise 6, Question 3
Author: Simcha Rubinstain & Yedidya Korn
*/

#include <iostream>
#include <string>
#include"Student.h"
using namespace std;

int main()
{
	Student *list[7];//array of 7 students
	BA a(123, "Abe", "Avraham", 3);//students info
	a.addGrade(90);
	a.addGrade(100);
	a.addGrade(90);
	BA b(234, "Yizhak", "Avramson", 10);
	b.addGrade(100);
	b.addGrade(100);
	b.addGrade(90);
	b.addGrade(100);
	b.addGrade(90);
	b.addGrade(100);
	b.addGrade(90);
	b.addGrade(100);
	b.addGrade(90);
	b.addGrade(100);
	MA c(345, "Yacaov", "Jacobson", 7);
	c.addGrade(90);
	c.addGrade(100);
	c.addGrade(90);
	c.addGrade(100);
	c.addGrade(90);
	c.addGrade(100);
	c.addGrade(90);
	c.setResearch(false);
	MA d(456, "sara,", "Emanu", 7);
	d.addGrade(90);
	d.addGrade(100);
	d.addGrade(90);
	d.addGrade(100);
	d.addGrade(90);
	d.addGrade(100);
	d.addGrade(90);
	d.setResearch(true);
	PHD e(567, "Rivka", "Imanu", 1);
	e.setResearch(30);
	PHD f(678, "Rachel", "Jacobes", 2);
	f.setResearch(20);
	PHD g(789, "Leah", "Jacobes", 2);
	g.setResearch(30);
	list[0] = &a;
	list[1] = &b;
	list[2] = &c;
	list[3] = &d;
	list[4] = &e;
	list[5] = &f;
	list[6] = &g;
	interShip(*list);
	system("pause");
	return 0;
}