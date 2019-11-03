/*
File: String.cpp
Description: String class
Course: 150018 C++ Workshop
Exercise 4, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "String.h"

// C-string based Constructor (CTOR)
String::String(const char* s) : str(nullptr) {       // initialize the fields
	setString(s);
}
// Copy CTOR
String::String(const String& other) : str(nullptr) { // initialize the fields
	setString(other.str);
}
// Move CTOR
String::String(String&& other) : str(other.str) {    // initialize with other's data
   // Avoid temp object DTOR removing the dynamic data which is now used in our object
	other.str = nullptr;
}
// Destructor (DTOR)
String::~String() {
	delete[] str; // delete operators handle nullptr by themselves
	str = nullptr;
}

// String getter (Viewer) which returns a dynamic c-string (char array)
// The caller is responsible to free this array after using it
char* String::getString() const {
	if (str == nullptr) return nullptr;    // there is nothing to return...
	unsigned int length = strlen(str) + 1; // calculate the length
	char* temp = new char[length];         // allocate the char array
	strncpy(temp, str, length);            // copy the content
	return temp;
}

// String setter (Modifier)
void String::setString(const char * s) {
	// Protect when setting to the same char array
	if (s == str) return;
	delete[] str; // Free old string dynamic data memory

	if (s != nullptr) { // Create new dynamic char array and copy the content
		unsigned int length = strlen(s) + 1; // calc the length
		str = new char[length];              // allocate new array
		strncpy(str, s, length);             // copy the content
	}
	else // Nullify the string pointer
		str = nullptr;
}

String& String::insert(int index, const char* str) {
	if (strlen(this->str) < index)
		throw (IndexException(index, strlen(this->str)));
	IndexException e(1,2);
	unsigned int length = strlen(str) + 1; // calculate the length
	char* temp = new char[length + index];         // allocate the char array
	strncpy(temp, this->str, index);
	strncpy(temp, str, length);            // copy the content
	String newStr = temp;
	delete temp;
	return newStr;
}

// Copy assignment operator
String& String::operator = (const String& s) {
	if (this == &s) return *this; // Protection from assigning the object to itself
	delete[] str;
	str = nullptr;
	setString(s.str);
	// Allow chained assignments
	return *this;
}

// Move assignment operator
String& String::operator = (String&& s) {
	delete[] str; // Free old string dynamic data memory
	str = s.str;  // Update the pointer
	s.str = nullptr; // Avoid temp object DTOR removing the data now used in our object
	return *this;
}
// Operators

String& String::operator += (const String& rhs) {
	if (rhs.str == nullptr || strlen(rhs.str) == 0) // nothing to add
		return *this;

	if (str == nullptr) { // we have nothing => like a copy ctor
		setString(rhs.str);
		return *this;
	}

	// Create new c-string with appropriate length
	char* temp = new char[strlen(str) + strlen(rhs.str) + 1];
	strcpy(temp, str);     // copy there our original string
	strcat(temp, rhs.str); // concatenate there the second string
	delete[] str;          // free our old memory
	str = temp;            // set now to the new string
	return *this;
}

String operator + (String lhs, const String& rhs) {
	lhs += rhs; // Concatenate second string to the first (local - by value)
	return lhs; // return by value - it will use Move Ctor
}

String& String::operator *= (unsigned int rhs) {
	if (str == nullptr || rhs == 1 || strlen(str) == 0) // nothing to replicate
		return *this;

	if (rhs == 0) { // empty us
		delete[] str;
		str = nullptr;
		return *this;
	}

	// Create new c-string with appropriate length
	char* temp = new char[strlen(str) * rhs + 1];
	strcpy(temp, str);      // First time - copy myself to there
	while (--rhs != 0)       // While there are more replications to do
		strcat(temp, str);  //    concatenate myself to there (again and again)

	delete[] str;          // free our old memory
	str = temp;            // set now to the new string
	return *this;
}

String operator*(String lhs, unsigned int rhs) {
	lhs *= rhs; // Replicate inside the first (local - by value)
	return lhs; // return by value - it will use Move Ctor
}

bool String::operator == (const String& rhs) const {
	return !strcmp(str, rhs.str);
}

bool String::operator != (const String& rhs) const {
	return !(str==rhs.str);
}

bool String::operator > (const String& rhs) const {
	if (strcmp(str, rhs.str) > 0)
		return true;
	else
	return false;
}

bool String::operator < (const String& rhs) const {
	if (strcmp(str, rhs.str) < 0)
		return true;
	else
		return false;
}

bool String::operator >= (const String& rhs) const {
	return !(str<rhs.str);
}

bool String::operator <= (const String& rhs) const {
	return !(str > rhs.str);
}

ostream & operator<<(ostream & out, const String str){
	out << str.getString();
	return out;
}

istream & operator>>(istream & in,  String& str) {
	in >> str;
	return in;
}

int String::operator [] (const char* index) {
	char *temp = strstr(this->str, index);// a pointer to the first place the index string apeers in the original string
	if (temp)
		return (strlen(this->str) - strlen(temp));
	else
		throw index;
}

// Public functions

int String::length() const {
	return strlen(str);
}

void String::print() const {
	if (str != nullptr)
		cout << str;
	cout << endl;
}
