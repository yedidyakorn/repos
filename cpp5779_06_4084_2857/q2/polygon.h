#include <iostream>
using uint = unsigned int;
using namespace std;

class Poligon
{
	uint _numSides;
	uint* _sides;

public:
	Poligon(uint);
	Poligon(const Poligon&);
	/*Poligon& operator=(const Poligon&);*/
	Poligon(Poligon&&);
	/*Poligon& operator=(Poligon&&);*/
	uint nomSides()const;
	uint* sides()const;
	uint Scope(Poligon);
	bool operator==(Poligon&);
	~Poligon();
};

class Triangle : public Poligon
{
	int w;
public:


	Triangle(uint a, uint b, uint c);
	~Triangle();
};

Triangle::Triangle(uint a, uint b, uint c){
	
	

}

Triangle::~Triangle()
{
}
