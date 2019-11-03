/*
File: main.cpp
Description: runs the program
Course: 150018 C++ Workshop
Exercise 5, Question 2
Author: Simcha Rubinstain & Yedidya Korn
*/

#include "List.h"

//------------------------------------------------
// class Node implementation
//------------------------------------------------
List::Node::Node(int val, List::Node* nxt) : _value(val), _next(nxt) {}
List::Node::Node(const List::Node& src) : _value(src._value), _next(src._next) {}
int         List::Node::value() const { return _value; }
List::Node* List::Node::next() const { return _next; }
void        List::Node::next(Node* nxt) { _next = nxt; }

//--------------------------------------------
// class List implementation
//--------------------------------------------
List::List() : head(nullptr) {}

List::List(const List &other) {
	Node *src, *trg;
	if (other.head == nullptr)
		head = nullptr;
	else {
		head = new Node(other.head->value(), nullptr);
		if (head == nullptr)
			throw "failed in memory allocation";

		src = other.head;
		trg = head;
		while (src->next() != nullptr) {
			trg->next(new Node(src->next()->value(), nullptr));
			if (trg->next() == nullptr)
				throw "failed in memory allocation";
			src = src->next();
			trg = trg->next();
		}
	}
}

List::List(List &&other) {
	// Keep the temp list is permanent
	head = other.head;
	// Avoid destructing it in the temporary object
	other.head = nullptr;
}

List::~List() {
	clear();
}

void List::clear() {
	// empty all elements from the List
	Node* next;
	for (Node* p = head; p != nullptr; p = next) {
		// delete the element pointed to by p
		next = p->next();
		p->next(nullptr);
		delete p;
	}
	// mark that the List contains no elements 
	head = nullptr;
}

void List::insert(int key)
{
	if (this->isEmpty) {
		this->add(key);
		return;
	}
	List *temp = new List();
	while (key > this->head->value) {
		temp->add(this->head->value);
		this->removeFirst();
	}
	temp->add(this->head->value);
	this->removeFirst();
	while (!this->isEmpty) {
		temp->add(this->head->value);
		this->removeFirst();
	}
	*this = *temp;
	delete temp;
}

//void List::remove(int key)
//{
//	if (this->isEmpty) 
//		throw "list empty";
//	List *temp = new List();
//	while (key > this->head->value) {
//		temp->add(this->head->value);
//		this->removeFirst();
//	}
//	temp->add(this->head->value);
//	this->removeFirst();
//	while (!this->isEmpty) {
//		temp->add(this->head->value);
//		this->removeFirst();
//	}
//	*this = *temp;
//	delete temp;
//}

List & List::operator=(const List &rhs)
{
	if (this == &rhs)
		return *this;
	head = rhs.head;
	return *this;
}


ostream & operator<<(ostream& out,  List& rhs) 
{ 
	if (rhs.isEmpty)
		throw "list is empty";
	while (!rhs.isEmpty)
	{
		out << rhs.head->value << " ";
		rhs.removeFirst();
	}
	return out;
}

istream& operator>>(istream& in, List& rhs) {        // in .cpp
	int s;
	in>>s;
	if (s > rhs.head->value)
		rhs.add(s);
	else
		throw "incorrect input";
	return in;
}


bool List::isEmpty() const {
	// test to see if the List is empty
	// List is empty if the head pointer is null
	return head == nullptr;
}

void List::add(int val) {
	//Add a new value to the front of a Nodeed List
	head = new Node(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}

int List::firstElement() const {
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value();
}

bool List::search(const int &val) const {
	// loop to test each element
	for (Node* p = head; p != nullptr; p = p->next())
		if (val == p->value())
			return true;
	// not found
	return false;
}

void List::removeFirst() {
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Node* p = head;
	// reassign the first node
	head = p->next();
	p->next(nullptr);
	// recover memory used by the first element
	delete p;
}
