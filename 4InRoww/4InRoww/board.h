#pragma once
#include <iostream>
using namespace std;

class board
{
	int _row;
	int _col;
	char** _table;
	bool _gameOver = false;
	char _winner;
public:
	board(int row, int col) { _row = row + 3; _col = col + 2; reset(_row, _col); }
	~board();
	void reset(int,int);//resets the table to spaces
	void actoin(char);//
	void show();
	void add(int,char);
	bool checkIfFull(int);
	bool gameOver() {return _gameOver; }
	bool win(char);
	bool tiad();
	char winner() { return _winner; }

};

