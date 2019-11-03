/*
File: Student.h
Description: 
Course: 150018 C++ Workshop
Exercise 6, Question 3
Author: Simcha Rubinstain & Yedidya Korn
*/
#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_
#include "mytypes.h"
#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
	int _id;
	string _firstName;
	string _lastName;
	int _curses;//number of courses

public:
	Student(int id, string firstName, string lastName);//ctor without courses
	Student(int id, string firstName, string lastName, int curses);//ctor with courses
	Student(const Student&);
	Student(Student&&);
	int getCurses();//getter
	virtual ~Student();
	virtual bool stipend()=0;//checks if evry typr gets a scalership
	virtual void print();
	friend void interShip(Student*);//gets a array of student and prints the students that get a scalership
};

class BA : public Student
{
protected:
	int* _grades;//array of grades
	int _numOfGrades =0;//size of array

public:
	BA(int id, string firstName, string lastName) :Student(id, firstName, lastName) {}
	BA(int id, string firstName, string lastName, int curses) :Student(id, firstName, lastName, curses) {}
	BA(int id, string firstName, string lastName, int curses, int numOfGrades);
	BA(const BA&);
	BA(BA&&);
	~BA();
	void entreGrades(int);//enter a few grades at a time
	void addGrade(int);//enter one grade
	int avrage();//avrage of grades
	bool stipend();
	void print();
};

class MA : public BA
{
	bool _research;
public:
	MA(int id, string firstName, string lastName) :BA(id, firstName, lastName) {}
	MA(int id, string firstName, string lastName, int curses) :BA(id, firstName, lastName, curses) {}
	MA(int id, string firstName, string lastName, int curses, int numOfGrades) : BA(id, firstName, lastName, curses, numOfGrades ) {}
	MA(const MA& src ) :BA(src) {}
	MA(MA&& src) : BA(src) {}
	void setResearch(bool);
	bool stipend();
	void print();
};
class PHD : public Student
{
	int _research;//number of researches
public:
	PHD(int id, string firsName, string lastName) :Student(id, firsName, lastName) {}
	PHD(int id, string firsName, string lastName, int curses) :Student(id, firsName, lastName,curses) {}
	PHD(const PHD& src) : Student(src) {}
	PHD(PHD&&src) : Student(src) {}
	void setResearch(int);
	bool stipend();
	void print();
 };

void interShip(Student*);

#endif