//#pragma once
//
//#include <string>
//#include<iostream>
//using namespace std;
//class Employee
//{
//	string _name;
//	int _age;
//	int _sal;
//
//public:
//	Employee(string name, int age, int sal) { _name = name; _age = age; _sal = sal; }
//	Employee(const Employee&)= delete;
//	void operator = (const Employee&) = delete;
//	virtual void whoAmI() { cout << "name: " << _name << " \n age: " << _age << endl; }
//	virtual void dowork() = 0;
//};
//
//class Admin : public Employee
//{
//	string _function;
//public:
//	Admin(string name, int age, int sal, string function) :Employee(name, age, sal) { _function = function; }
//	Admin(const Admin&) = delete;
//	void operator = (const Admin&) = delete;
//	void whoAmI() { cout << "administritor \n"; Employee::whoAmI(); }
//	void dowork() { cout << _function << endl; }
//};
//
//class Lecturer :public Employee
//{
//	int _numOfCourses;
//	string *_courses;
//public:
//	Lecturer(string name, int age, int sal, int numOfCourses, string* courses) :Employee(name, age, sal) { _numOfCourses = numOfCourses;  _courses=courses ; }
//	~Lecturer() { delete _courses; }
//	Lecturer(const Lecturer&) = delete;
//	void operator = (const Lecturer&) = delete;
//	void whoAmI() { cout << "lecturer \n"; Employee::whoAmI(); }
//	void dowork() { for(int i=0;i<_numOfCourses;i++) cout << _courses[i] << endl; }
//};