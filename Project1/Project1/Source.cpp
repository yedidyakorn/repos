#include"Header.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class A {
public:
	int f() { return 1; }
	int g() { return 2; }
};

class B :public A {
public:
	int f() { return 3; }
	int g() { return 4; }
};

class C :public B {
public:
	int f() { return 5; }
	int g() { return 6; }
};

int main()
{
	vector<int> vec;
	auto y = 2;
	for (int i = 1; i < 100; i++)
		vec.push_back(i);
	for (auto it1 = vec.begin(); it1 < vec.end(); it1++) {
		cout <<*it1<<"  "<< y << endl;
		y = y + y;

	}
	cout << endl;
	for (auto it1 = vec.begin(); it1 < vec.end(); it1++)
	{
		auto a = *it1;
		cout << a<<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}