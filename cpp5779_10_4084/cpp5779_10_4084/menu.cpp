/*
File: menu.cpp
Description:
Course: 150018 C++ Workshop
Exercise 10, Question 1
Author:Yedidya Korn
*/#include<iostream>
#include<iomanip>
#include"menu.h"

using namespace std;

MenuOption operator++(MenuOption& rhs) {
	rhs = MenuOption(int(rhs) + 1);
	return rhs;
}

const char* MenuOptionLine[LAST_MENU_OPTION + 1] {
	"Exit",
	"Add a new student",
	"Print details for all students eligible for stipend",
	"Print full name of the student with most research hours"
	"Print number of BA students eligible for stipend",
	"Print full name of all MA students not doing research",
	"Check for existance of a student with >15 courses",
	"Remove PHD students not doing any course",
};

istream& operator>>(istream& in, MenuOption& rhs) {
	int value;
	in >> value;
	rhs = MenuOption(value);
	return in;
}

ostream& operator<<(ostream& out, MenuOption rhs) {
	out << setw(4) << int(rhs) << "\t--\t" << MenuOptionLine[rhs];
	return out;
}

MenuOption menu() {
	MenuOption chosen;

	cout << endl << "Menu options:" << endl << endl;

	for (chosen = FIRST_MENU_OPTION; chosen <= LAST_MENU_OPTION; ++chosen)
		cout << chosen << endl;
	cout << endl;

	cout << "Please choose a menu option: ";
	cin >> chosen;
	return chosen;
}