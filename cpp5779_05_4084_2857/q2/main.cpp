/*
File: main.cpp
Description: runs the program
Course: 150018 C++ Workshop
Exercise 5, Question 2
Author: Simcha Rubinstain & Yedidya Korn
*/

#include <iostream>
#include "List.h"
using namespace std;

int main() {
	List lst;
	int choice, val;
	cout << "enter the list values\n";
	cin >> lst;
	cout << "choose 0-2\n";
	cin >> choice;
	while (choice) {
		switch (choice) {
		case 1:
			cout << "enter a value to insert\n";
			cin >> val;
			lst.insert(val);
			break;
		case 2:
			cout << "enter a value to remove\n";
			cin >> val;
			try {
				lst.remove(val);
			}
			catch (char* msg) {
				cout << msg << endl;
			}
			break;
		default:
			cout << "ERROR\n";
		}
		cout << lst << endl;
		cout << "choose 0-2\n";
		cin >> choice;
	}
	return 0;
}
