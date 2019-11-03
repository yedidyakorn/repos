/*
File: menu.cpp
Description: mangers the menu
Course: 150018 C++ Workshop
Exercise 2, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#include"menu.h"
#include"mytypes.h"
#include <iostream>

using namespace std;


	//adds 1 to enom value
	MenuOption& operator ++ ( MenuOption & rhs) {
		MenuOption temp;
		int tmp;
		tmp = rhs;
		tmp++;
		temp = MenuOption(tmp);
		return rhs;
		//return (MenuOption(a));
	}

	//a input operator for enum
	istream& operator >> (istream& in, MenuOption& a) {
		in >> a;
		return in;
	}
