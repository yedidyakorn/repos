/*
File: main.cpp
Description: This is the test program (main) for managing a bus fleet
Course: 150018 C++ Workshop, Exercise 1, Question 1
Author: Dan Zilberstein
*/

#include <iostream>
#include <iomanip>
#include<cstring>
#include<string.h>
#include "mytypes.h"
#include "bus.h"

using namespace std;

// These are all of the main menu options.  Note that the numbers:
// 0, 1, 2, etc., show up /nowhere/ in the code, even though the
// user will see them on the screen, and will input them for
// choosing a menu option.
// Add your menu options according the the exercise requirements
enum MenuOption {
	EXIT_MENU,
	CREATE_BUS_50_SITS,
	CREATE_BUS_N_SITS,
	ASSIGN_LINE_TO_BUS,
	ADD_BUS_DRIVER,
	REMOVE_BUS,
	PRINT,
	SHOW_LINE,
	SHOW_BUS_DRIVER,
	SHOW_ALL_BUSES,
	// a neat trick for for-loop initial and final values
	FIRST_MENU_OPTION = EXIT_MENU,
	LAST_MENU_OPTION = SHOW_ALL_BUSES
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

// Function main - this is the entry code for the program
// It prints menu and performs the action according to the chosen option.
int main(void) {
	MenuOption chosen;
	int chosenInt, tempID, tempSeats,tempLine;
	uint lineNum;
	char tempname[80];
	// Everything happens inside of this do-while loop, until the user
	//     has decided to exit (or an error occurs).
	do {
		cout << endl << "Menu options:" << endl << endl;

		const int menuIndent = 10;

		// The user will see:
		//
		//           0 -- exit
		//           1 -- set dollars to shekkels conversion rate
		//           2 -- input an account
		// etc.
		//
		// The casts are for doing the "++" as an int type since
		// they are not allowed as a MenuOption type.
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

		// additional preparations if needed
		// ...

		// Note how the individual cases, match nicely to the
		//     operations they will perform.
		switch (chosen) {
		case EXIT_MENU:
			// adios
			cout << "Thanx for using Bus Fleet Management Program!" << endl;
			break;
		case CREATE_BUS_50_SITS:
			cout << "Enter bus ID number: \n";
			cin >> tempID;
			try {
				busCtor(tempID);
			}
			catch(const char* a){
				cout << "the id number " << a << "is invailed.\n";
			}
			break;
		case CREATE_BUS_N_SITS:
			cout << "Enter bus ID number: \n";
			cin >> tempID;
			cout << "Enter number of seats on the bus: \n";
			cin >> tempSeats;
			try {
				busCtor(tempID, tempSeats);
			}
			catch (const char* a) {
				cout << "the id number " << a << "is invailed.\n";
			}
			catch (int num) {
				cout << "the number of seats " << num << "is invailed.\n";
			}
			break;
		case ASSIGN_LINE_TO_BUS:
			cout << "Enter bus ID number: \n";
			cin >> tempID;
			try {
				getBus(tempID);
			}
			catch (const char* a) {
				cout << "the id number " << a << "was not found.\n";
				break;
			}
			cout << "Enter new bus line: \n";
			cin >> lineNum;
			try {
				busLine(*getBus(tempID), lineNum);
			}
			catch (uint line) {
				cout << "the line number " << line << "is invailed.\n";
			}
			catch (int num) {
				cout << "the line number " << num << "is full.\n";
			}
			catch (const char* a) {
				cout << "the id number " << a << "is allready asigned to the line.\n";
			}
			break;
		case ADD_BUS_DRIVER:
			cout << "Enter bus ID number: \n";
			cin >> tempID;
			try {
				getBus(tempID);
			}
			catch (const char* a) {
				cout << "the id number " << a << "was not found.\n";
				break;
			}
			cout << "Enyer bus driver name: \n";
			cin >> tempname;
			try {
				busDriver(*getBus(tempID), tempname);
			}
			catch (...) {
				cout << "the name must have at least 1 charecter.\n";
			}
			break;
		case REMOVE_BUS:
			cout << "Enter bus ID number to remove (only a bus assigned to a line can be removed): \n";
			cin >> tempID;
			try {
				(delBus(tempID));
				cout << "removed secsessfully\n";
			}
			catch (const char*) {
				cout << "cannot remove. ID number dosent exsist in fleet\n";
			}
			catch (uint) {
				cout << "cannot remove. The bus is asigned to a line.\n";
			}
			break;
		case PRINT:
			cout << "Enter bus ID number: \n";
			cin >> tempID;
			try {
				getBus(tempID);
			}
			catch (const char* a) {
				cout << "the id number " << a << "was not found.\n";
				break;
			}
			busPrint(*getBus(tempID));
			break;
		case SHOW_LINE:
			cout << "Enter bus ID number: \n";
			cin >> tempID;
			try {
				getBus(tempID);
			}
			catch (const char* a) {
				cout << "the id number " << a << "was not found.\n";
				break;
			}
			cout<<busLine(*getBus(tempID));
			break;
		case SHOW_BUS_DRIVER:
			cout << "Enter bus ID number: \n";
			cin >> tempID;
			try {
				getBus(tempID);
			}
			catch (const char* a) {
				cout << "the id number " << a << "was not found.\n";
				break;
			}
			cout << busDriver(*getBus(tempID));
			break;
		case SHOW_ALL_BUSES:
			printAll();
			break;
			//... add your cases with your code here
		default:
			break;
		}
	} while (chosen != EXIT_MENU);
	busFleetDtor();
	// Do not forget here to request destroying all the data and freeing all the memory

	return 0;
}
