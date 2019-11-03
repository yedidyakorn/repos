/*
File: main.cpp
Description: runs the program
Course: 150018 C++ Workshop
Exercise 8, Question 1
Author: Simcha Rubinstain & Yedidya Korn
*/

#pragma once

#ifndef __LIST_H
#define __LIST_H

#include <iostream>
#include "Iterator.h"
using namespace std;
template <typename T>
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
	List(const T&);
	List(T&&);
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

	List& operator = (const List<T>&);
	friend ostream& operator<<(ostream&, List obj);
	friend istream& operator>>(istream&, List obj);


	class Iterator :public ForwardIterator
	{
		Iterator()
		bool operator==(const ForwardIterator& rhs) const { return p == rhs._value; }
		bool operator!=(const ForwardIterator& rhs) const { return p != rhs._value; }
		ForwardIterator& operator++() { return _next; }
		ForwardIterator operator++(int) { auto copy(*this); ++(*this); return copy; }
	};

protected:
	// data field
	Node* head;
};
template <typename T>
ostream& operator<<(ostream&, List<T> obj);
istream& operator>>(istream&, List<T> obj);



#endif //__LIST_H
