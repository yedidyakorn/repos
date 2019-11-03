#pragma once
/*
File: menu.h
Description: mangers the menu
Course: 150018 C++ Workshop
Exercise 4, Question 1
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
	INSERT_A_STRING,
	INSERT_TOW_STRINGS,
	PRINT_STRINGS,
	COMPARE_STRINGS,
	MERGE_STRINGS,
	SEARCH_ONE_STRING_IN_THE_OTHER,
	// a neat trick for for-loop initial and final values
	FIRST_MENU_OPTION = EXIT_MENU,
	LAST_MENU_OPTION = SEARCH_ONE_STRING_IN_THE_OTHER
};

// These strings will be seen by the user, on the main menu.  They
// must be kept consistent with the operations of menu_option
// above.
const char * const menuOptionStrings[] = {
	"exit the program",
	"insert a string",
	"insert two strings",
	"print a srting",
	"compare strings",
	"merge strings",
	"search one string in the other",
};


MenuOption operator ++ (const MenuOption &);
//istream& operator >> (istream& in, MenuOption& a);
