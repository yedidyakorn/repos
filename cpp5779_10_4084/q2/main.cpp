/*
File: main.cpp
Description:
Course: 150018 C++ Workshop
Exercise 10, Question 2
Author:Yedidya Korn
*/

#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
#include "Tree.h"



using namespace std;

int main() 
{
	string str;
	int num = 0;
	Node* x;
	Node* y;
	char ch;
	bool empty=false;
	cout << "enter a Mathematical expression.\n";
	cin >> str;
	stack<char> actoins;
	stack<Node*> operands;
	while (str.length()>0)
	{
		while (str.front() < 10 && str.front() >= 0)
		{
			num *= 10;
			num += str.front();
			str.erase(str.begin());
		}
		if (num > 0)
		{
			Node * val = new Nums(num);
			operands.push(val);
			num = 0;
			break;
		}
		 ch = str.front();
		str.erase(str.begin());
		if (ch == ' ')
			break;
		if (ch == '+' || ch == '*' || ch == '/' || ch == '-')
		{
			if (!actoins.empty()||(ch == '-' || ch == '+')||((actoins.top()=='*'||actoins.top=='/')&& (ch == '*' || ch == '/')))
			{
				x = operands.top();
				operands.pop();
				y = operands.top();
				operands.pop();
				Node * a=new Nums(actoins.top(), x, y);
				operands.push(a);
				actoins.pop();
				actoins.push(ch);
			}
				
			else
				actoins.push(ch);

		}
		else
			cout << "INPUT ERROR";
		while (!actoins.empty)
		{
			x = operands.top();
			operands.pop();
			y = operands.top();
			operands.pop();
			Node * a = new Nums(actoins.top(), x, y);
			operands.push(a);
			actoins.pop();
			actoins.push(ch);
		}
	}
	
	cout << "the anser is" << operands.top()->action();


	return 0;
}