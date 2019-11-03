/*
File: menu.h
Description: mangers the menu
Course: 150018 C++ Workshop
Exercise 2, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#pragma once
#include <iostream>
#include <iomanip>
#include<cstring>
#include<string.h>
#include"mytypes.h"

using namespace std;
	// These are all of the main menu options.  Note that the numbers:
	// 0, 1, 2, etc., show up /nowhere/ in the code, even though the
	// user will see them on the screen, and will input them for
	// choosing a menu option.
	// Add your menu options according the the exercise requirements
	enum MenuOption {
		EXIT_MENU,
		INSERT_A_NUMBER,
		PRINT_A_ARRAY,
		CALCULATE_SUM_OF_ARRAY,
		CALCULATE_MULTIPLICATION_OF_ARRAY,
		SUM_TWO_NUMBERS,
		MULTIPLY_TWO_NUMBERS,
		SUBTRACT_TWO_NUMBERS,
		SORT_ARRAY,
		// a neat trick for for-loop initial and final values
		FIRST_MENU_OPTION = EXIT_MENU,
		LAST_MENU_OPTION = SORT_ARRAY
	};

	// These strings will be seen by the user, on the main menu.  They
	// must be kept consistent with the operations of menu_option
	// above.
	const char * const menuOptionStrings[] = {
		"exit the program",
		"create a bus with 50 seats",
		"create a bus (choose how many seats)",
		"assign line to a bus",
		"add name of a bus driver",
		"remove a bus from the fleet",
		"show a bus information",
		"show line of a bus",
		"show bus driver name",
		"show all the the buses in the fleet"
	};


	MenuOption operator ++ (const MenuOption &);
	istream& operator >> (istream& in, MenuOption& a);
