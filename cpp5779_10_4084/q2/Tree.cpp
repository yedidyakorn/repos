#include "Tree.h"
#include <iostream>
using namespace std;

double Signs::action()
{
	Node* b;
	Nums n;
	Signs s;
	b = this;
	if (b->type == 'n')
	{
		b = &n;
		return b->action();
	}

	if (b->type == 'o') {
		b = &s;
		switch (_sign)
		{
		case '+':
			return _right->action() + _left->action();
			break;
		case '-':
			return _right->action() + _left->action();
			break;
		case '*':
			return _right->action() * _left->action();
			break;
		case '/':
			return _right->action() / _left->action();
			break;
		default:
			cout << "ERROR";
			break;
		}
	}
	

	return 0.0;
}
