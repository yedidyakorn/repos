#include <iostream>
#include "polygon.h"
using namespace std;

int main()
{

	uint a1, b1;

	cout << "enter number of sides for polygon 1:\n";
	cin >> a1;
	Poligon p1(a1);
	if (p1.nomSides() == 3 || p1.nomSides() == 4)
	{
		cout << "enter sides for polygon:\n";
	}

	cout << "enter number of sides for polygon 2:\n";
	cin >> b1;

	if (p1.nomSides() == b1) return 0;

	Poligon p2(b1);
	if (p2.nomSides() == 3 || p2.nomSides() == 4)
	{
		cout << "enter sides for polygon:\n";
	}
	if( p1 == p2)
	{
		cout << "not equal\n";
		return 0;
	}
	cout << "not equal\n";
	return 0;
}