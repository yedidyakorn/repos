#include<iostream>
#include<iomanip>
#include"menu .h"

using namespace std;

MenuOption operator++(MenuOption& rhs) {
	rhs = MenuOption(int(rhs) + 1);
	return rhs;
}

const char* MenuOptionLine[LAST_MENU_OPTION + 1] {
	"Exit",
	"Show the number of leaves",
	"Show the height",
	"Reflect the tree",
	"Show the number of nodes with left sones only",
	"Show the level of a node",
	"Remove a node"
};

istream& operator >> (istream& in, MenuOption& rhs) {
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