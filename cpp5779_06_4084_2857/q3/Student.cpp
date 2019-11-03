/*
File: Student.cpp
Description:
Course: 150018 C++ Workshop
Exercise 6, Question 3
Author: Simcha Rubinstain & Yedidya Korn
*/

#include "Student.h"

Student::Student(int id, string firstName, string lastName)
{
	_id = id;
	_firstName = firstName;
	_lastName = lastName;
}

Student::Student(int id, string firstName, string lastName, int curses)
{
	_id = id;
	_firstName = firstName;
	_lastName = lastName;
	_curses = curses;
}

Student::Student(const Student &src)
{
	_id = src._id;
	_firstName = src._firstName;
	_lastName = src._lastName;
	_curses = src._curses;
}

Student::Student(Student && other)
{
	_id = other._id;
	_firstName = other._firstName;
	_lastName = other._lastName;
	_curses = other._curses;
}

int Student::getCurses()
{
	return _curses;
}

Student::~Student()
{
}

void Student::print()
{
	cout << "ID: " << _id << "\n First name: " << _firstName << "\n Last name" << _lastName << "\n Number of courses: " << _curses << endl << "==================\n";
}


BA::BA(int id, string firstName, string lastName, int curses, int numOfGrades) : Student(id, firstName, lastName,curses)
{
	this->entreGrades(numOfGrades);
}

BA::BA(const BA &src) :Student(src._id, src._firstName, src._lastName, src._curses)
{
	if (_numOfGrades)
	{
		int *temp = new int[src._numOfGrades];
		for (int i = 0; i < src._numOfGrades; i++)
			temp[i] = src._grades[i];
		_grades = temp;
		delete temp;
	}

}

BA::BA(BA &&src) :Student(src._id, src._firstName, src._lastName, src._curses)
{
	_grades = src._grades;
	delete src._grades;
}

BA::~BA()
{
	delete _grades;
}

void BA::entreGrades(int numOfGrades)
{
	if (numOfGrades+_numOfGrades > _curses)
		throw "ERROR- more grades then cuorses\n";
	int *temp = new int[numOfGrades + _numOfGrades];
	for (int i = 0; i < numOfGrades; i++)
	{
		cout << "enter grade number " << i + 1;
		cin >> temp[i];
	}
	_numOfGrades += numOfGrades;
	_grades = temp;
	delete temp;
}

void BA::addGrade( int grade)
{
	if (_numOfGrades >= _curses)
		throw "ERROR- more grades then cuorses\n";
	int *temp = new int[_numOfGrades+1];
	for (int i = 0; i < _numOfGrades; i++)
		temp[i] = this->_grades[i];
	temp[_numOfGrades] = grade;
	_grades = temp;
	_curses++;
	delete temp;
}

int BA::avrage()
{
	int avg = 0;
	for (int i = 0; i < _curses; i++)
		avg += _grades[i];
	avg /= _curses;
	return avg;
}

bool BA::stipend()
{
	if (_curses > 9 && avrage() > 95)
		return true;
	return false;
}

void BA::print()
{
	cout << "ID: " << _id << "\n First name: " << _firstName << "\n Last name" << _lastName << "\n Number of courses: " << _curses << "Grades: ";
	for (int i = 0; i < _curses; i++)
		cout << _grades[i] << " ";
	cout << endl << "==================\n";
}

void MA::setResearch(bool rsc)
{
	_research = rsc;
}

bool MA::stipend()
{
	if (_curses > 7 && avrage() > 90 && _research)
		return true;
	return false;
}

void MA::print()
{
	BA::print();
	if (_research)
		cout << "research: yes\n" << "==================\n";
	else
		cout << "research: no\n" << "==================\n";
}

void PHD::setResearch(int research)
{
	_research = research;
}

bool PHD::stipend()
{
	if (_curses > 2 && _research>30)
		return true;
	return false;
}

void PHD::print()
{
	Student::print();
	cout << "Research hours: " << _research<<endl<<"==================\n";
}

void interShip(Student* list)
{
	for (int i = 0; i < list->getCurses(); i++)
		if (list[i].stipend())
			list[i].print();
}