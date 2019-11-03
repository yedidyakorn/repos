#include "board.h"



void board::reset(int row, int col)
{
	_table = new char*[row];
	for (int i = 0; i < row; i++)
		_table[i] = new char[col];
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			_table[i][j] = ' ';
	for (int j = 1, i = 0; j < col-1; j++)
		_table[i][j] = 47 + j;
	for (int i = 2; i < row; i++)
		for (int j = 0; j < col; j += col-1)
			_table[i][j] = 178;
	for (int j = 0, i = _row-1; j < _row; j++)
		_table[i][j] = 178;
}

void board::actoin(char sign)
{
	cout << endl << "turn- " << sign<<"\t\t";
	int choice;
	cout << "choose a colum (0-"<<_col-3<<")\n";
	cin >> choice;
	while (choice < 0 || choice>_col-3)
	{
		cout << "ERROR\n choose a colum (0-" << _col - 3 << ")\n";
		cin >> choice;
	}
	try { add(choice+1,sign); }
	catch (...) {
		cout << "ERROR coulm full\n";
		actoin(sign);
	}
	if (tiad())
	{
		_gameOver = true;
		_winner = 'N';
	}
	if (win(sign))
	{
		_gameOver = true;
		_winner = sign;
	}

}

void board::show()
{
	for (int i = 0; i < _row; i++) {
		for (int j = 0; j < _col; j++) {
			cout << _table[i][j];
		}
		cout << endl;
	}
	cout <<endl<<endl;
}

void board::add(int col,char sign)
{
	if (checkIfFull(col))
		throw "full";
	for (int i = 2; i < _row-1; i++)
	{
		if (_table[i + 1][col] != ' ') {
			_table[i][col] = sign;
			break;
		}
			
	}

}

bool board::checkIfFull(int col)
{
	if(_table[2][col]!=' ')
		return true;
	else
		return false;
}

bool board::win(char sign)
{

	for (int i = _row-2; i > 1; i--) {
		for (int j = 1; j < _col-1; j++) {
			if(j<_col-4)
				if (_table[i][j] == sign&& _table[i][j+1]==sign&& _table[i][j + 2] == sign && _table[i][j + 3] == sign)
					return true;
			if(i>4)
				if (_table[i][j] == sign && _table[i-1][j] == sign && _table[i-2][j] == sign && _table[i-3][j] == sign)
					return true;
			if (i > 4&&j<_col-4)
				if (_table[i][j] == sign && _table[i - 1][j+1] == sign && _table[i - 2][j+2] == sign && _table[i - 3][j + 3] == sign)
					return true;
			if (i < _row-4 && j < _col - 4)
				if (_table[i][j] == sign && _table[i + 1][j + 1] == sign && _table[i + 2][j + 2] == sign && _table[i + 3][j + 3] == sign)
					return true;
		}
	}
	
	
	return false;
}

bool board::tiad()
{
	for(int i=1;i<_col-1;i++)
		if(!checkIfFull(i))
			return false;
	return true;
}




board::~board()
{
}
