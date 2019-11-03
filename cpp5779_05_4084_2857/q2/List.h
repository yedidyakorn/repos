/*
File: main.cpp
Description: runs the program
Course: 150018 C++ Workshop
Exercise 5, Question 2
Author: Simcha Rubinstain & Yedidya Korn
*/

#pragma once

#ifndef __LIST_H
#define __LIST_H

#include <iostream>
using namespace std;
//------------------------------------------------
// Class List - Arbitrary size Lists
// Permits insertion and removal only from the front of the List
//------------------------------------------------
class List {

protected:
	//--------------------------------------------
	// inner class Node a single element for the Nodeed List
	//--------------------------------------------
	class Node {
		int   _value;
		Node* _next;
	public:
		// constructor
		Node(int, Node*);
		Node(const Node&);
		// data areas
		int   value() const; // getter only
		Node* next() const;  // getter
		void  next(Node*);   // setter
	}; //end of class Node

public:
	// constructors
	List();
	List(const List&);
	List(List&&);
	~List();
	// operations
	void add(int value);
	int  firstElement() const;
	bool search(const int&) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
	void insert(int key);
	void remove(int key);

	List& operator = (const List&);
	friend ostream& operator<<(ostream&,  List&);
	friend istream& operator>>(istream&, List&);



protected:
	// data field
	Node* head;
};

 ostream& operator<<(ostream&,  List&);
 istream& operator>>(istream&, List&);

#endif //__LIST_H
