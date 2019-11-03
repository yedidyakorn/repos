/*
File: main.cpp
Description: runs the program
Course: 150018 C++ Workshop
Exercise 4, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#include <iostream>
#include <iomanip>
#include<cstring>
#include<string.h>
#include "menu.h"
#include"String.h"


using namespace std;

// Function main - this is the entry code for the program
// It prints menu and performs the action according to the chosen option.
int main(void) {
	MenuOption chosen;
	int chosenInt,n;
	String a, b;
	do {
		cout << endl << "Menu options:" << endl << endl;

		const int menuIndent = 10;
		for (chosen = FIRST_MENU_OPTION; chosen <= LAST_MENU_OPTION;
			chosen = (MenuOption)((int)chosen + 1)) {
			cout << setw(menuIndent) << " " << chosen << " -- ";
			cout << menuOptionStrings[chosen] << endl;
		}
		cout << endl;


		cout << "Please choose a menu option: ";
		cin >> chosenInt;
		// After the user has input an int, it is cast to a
		//   MenuOption variable.
		chosen = (MenuOption)chosenInt;


		// Note how the individual cases, match nicely to the
		//     operations they will perform.
		switch (chosen) {
		case EXIT_MENU:
			break;
		case INSERT_A_STRING:
			cout << "Enter a String\n";
			cin >> a;
			break;
		case INSERT_TOW_STRINGS:
			cout << "Enter two Strings in two lines\n";
			cin >> a;
			cin >> b;
			break;
		case PRINT_STRINGS:
			cout <<"a: "<< a << endl <<"b: "<< b;
			break;
		case COMPARE_STRINGS:
			if (a == b)
				cout << "a=b\n";
			if (a > b)
				cout << "a>b\n";
			if (a < b)
				cout << "a<b\n";
			break;
		case MERGE_STRINGS:
			cout << "enter a number for index\n";
			cin >> n;
			char *temp;
			temp = b.getString();
			try {				
				cout<<a.insert(n, temp)<<endl;
							}
			catch (IndexException a) {
				cout << "ERROR index " << a.index << "can't fit in String that has maxsimum" << a.maxIndex << endl;
			}
			temp = a.getString();
			try {
				cout << b.insert(n,temp) << endl;
			}
			catch (IndexException a) {
				cout << "ERROR index " << a.index << "can't fit in String that has maxsimum" << a.maxIndex << endl;
			}
			delete temp;
			break;
		case SEARCH_ONE_STRING_IN_THE_OTHER:
			try {
				cout << "the first time b appears in a is: " << a[b.getString()]<<endl;
			}
			catch (char* ) {
				cout << "b dosen't appear in a.\n";
			}
			break;
		}
	} while (chosen != EXIT_MENU);


		// Do not forget here to request destroying all the data and freeing all the memory

		return 0;
}
