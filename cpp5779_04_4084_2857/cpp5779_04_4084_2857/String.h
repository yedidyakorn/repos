#pragma once
/*
File: String.h
Description: String class
Course: 150018 C++ Workshop
Exercise 4, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#ifndef __STRING_H
#define __STRING_H

#include <iostream>
#include"Errors.h"



using namespace std;

class String {
private:
	char *str;                      // Internal data container - for dynamic c-string
	void setString(const char* s);   // Modifier - for internal usage
public:
	// constructors
	String(const char* s = nullptr); // Default and from c-string
	String(const String& s);         // Copy ctor
	String(String&& s);              // Move ctor
	~String();                       // Dtor

	char* getString() const;         // Viewer
	String& insert(int index, const char* str);

	// Operators
	String& operator = (const String&);     // Copy Assignment
	String& operator = (String&&);          // Move Assignment
	bool operator == (const String&) const; //Equality between two Strings 
	bool operator != (const String&) const; //Equality between two Strings 
	bool operator < (const String&) const; //Equality between two Strings 
	bool operator > (const String&) const; // Equality between two Strings 
	bool operator <= (const String&) const; // Equality between two Strings 
	bool operator >= (const String&) const; // Equality between two Strings 
	String& operator += (const String&);    // Addition to object by concatenation
	friend String operator + (String, const String&); // Symmetric addition as friend
	String& operator *= (unsigned int);     // Multiplication by replicating
	friend String operator * (String, unsigned int);  // Symmetric multiplication as friend
	friend ostream& operator << (ostream& out, const String str);//out func as friend
	friend istream& operator >> (istream& in,  String& str);//out func as friend
	int operator [] (const char*);// checks if there is a sub string

	// Public functions
	int length() const; // Length of the string
	void print() const; // Print the string
};

String operator + (String, const String&); // Declaration of addition operator (global)
String operator * (String, unsigned int);  // Declaration of mulitiplication oeprator (global)
ostream & operator<<(ostream & out, const String str);//Declarationof out func (global)
istream& operator >> (istream& in,  String& str);//Declarationof out func (global)

#endif // __STRING_H
