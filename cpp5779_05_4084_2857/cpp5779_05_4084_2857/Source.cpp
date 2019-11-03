/*
File: main.cpp
Description: runs the program
Course: 150018 C++ Workshop
Exercise 5, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#include <iostream>
#include<string>


using namespace std;

// Function main - this is the entry code for the program
// It prints menu and performs the action according to the chosen option.
int main(void) {

	string str;
	char ch = ' ';
	cout << "enter a String with four words. ";
	getline(cin, str);//gets string
	int i1,i2,i3;//pointers to spaces between words.(incase the string has '*' inside)
	i1 = str.find_first_of(' ', 1);
	str[i1] = '*';
	i2 = str.find_first_of(' ', 1);
	str[i2] = '*';
	i3 = str.find_first_of(' ', 1);
	str[i3] = '*';
	cout << str<<endl;
	str.replace(str.begin()+i3, str.end(), "#!!@1234");
	cout << str<<endl;
	str.erase(str.begin(), str.begin() + i1+1);
	cout << str << endl;
	str.erase(str.begin(), str.begin() + (i2-i1));
	cout << str << endl;
	str.erase(str.begin(), str.begin() +( i3-i2-1));
	cout << str << endl;
	return 0;
}
