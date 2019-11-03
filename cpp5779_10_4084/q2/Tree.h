/*
File: main.cpp
Description:
Course: 150018 C++ Workshop
Exercise 10, Question 2
Author:Yedidya Korn
*/
#pragma once
#ifndef __TREE_H
#define __TREE_H
#include <iostream>
#include <string>
using namespace std;

class Node {
	protected:
		char _type;
		Node* _right;
		Node* _left;

	public:
		Node();
		Node(char type, Node* right, Node* left) { _type = type; _right = right; _left = left; }
		char type() { return _type; }
		virtual double action() = 0;
	};

class Signs: public Node
{
	char _sign;
public:
	double action() override;
};

class Nums : public Node
{

	double _num;
public:
	Nums(double x) :Node() { _num = x; }
	Nums(char type, Node* right, Node* left) { _type = type; _right = right; _left = left; }
	Nums();
	double action() override { return _num; }
	void setNum(double num) { _num = num; }

};

#endif // __TREE_H