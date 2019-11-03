#include "polygon.h"


//ctor 
Poligon::Poligon(uint numOfSidses)
{
	_sides = new uint[numOfSidses];

	if (numOfSidses < 3 || numOfSidses > 4)
	{
		cout << "enter sides for polygon:\n";
		int n;
		for (int i = 0; i < numOfSidses; ++i)
		{
			cin >> n;
			_sides[i] = n;
		}
	}
}

//copy ctor
Poligon::Poligon(const Poligon& source)
{
	_numSides = source._numSides;
	_sides = new uint(*(source._sides));
}
//Poligon& Poligon::operator=(const Poligon& rhs)
//{
//	if (this == &rhs) return *this;
//
//	_sides = rhs._sides;
//
//
//}

//move ctor
Poligon::Poligon(Poligon&& other) {
	_sides = other._sides; 
	_numSides = other._numSides;
	other._numSides = NULL;
}
//Poligon& Poligon::operator=(Poligon&& other) 
//{
//	_sides = other._sides;
//	_numSides = other._numSides;
//	other._numSides = NULL;
//}

//getter
uint Poligon::nomSides() const
{
	return _numSides;
}
//getter
uint* Poligon::sides() const
{
	return _sides;
}
//heikef
uint Poligon::Scope(Poligon poligon)
{
	uint sum = 0;
	for (int i = 0; i < _numSides ; ++i)
	{
		sum += poligon._sides[i];
	}
	return sum;
}
//operator ==
bool Poligon::operator==(Poligon& rhs)
{
	return (_numSides == rhs._numSides && Scope(*this) == Scope(rhs));
}
//dtor
Poligon::~Poligon()
{
	delete[]_sides;
}
